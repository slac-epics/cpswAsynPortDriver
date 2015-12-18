/*
 * cpswAsynDriver.cpp
 * 
 * Asyn driver that inherits from the asynPortDriver class to demonstrate its use.
 * It simulates a digital scope looking at a 1kHz 1000-point noisy sine wave.  Controls are
 * provided for time/division, volts/division, volt offset, trigger delay, noise amplitude, update time,
 * and run/stop.
 * Readbacks are provides for the waveform data, min, max and mean values.
 *
 * Author: Mark Rivers
 *
 * Created Feb. 5, 2009
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>


#include <epicsTypes.h>
#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsString.h>
#include <epicsTimer.h>
#include <epicsMutex.h>
#include <epicsEvent.h>
#include <iocsh.h>

#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>
#include <epicsExport.h>

#include <asynOctetSyncIO.h>


static const char *driverName="cpswAsynDriver";
static void asynPollerC(void *drvPvt);


/** Constructor for the cpswAsynDriver class.
  * Calls constructor for the asynPortDriver base class.
  * \param[in] portName The name of the asyn port driver to be created.
  * \param[in] maxPoints The maximum  number of points in the volt and time arrays */
cpswAsynDriver::cpswAsynDriver(const char *portName, Path p, int nelms, int nEntries) 
   : asynPortDriver(portName, 
                    nelms, /* maxAddr */ 
                    nEntries,
                    asynInt32Mask | asynFloat64Mask | asynOctetMask | asynDrvUserMask, /* Interface mask */
                    asynInt32Mask | asynFloat64Mask | asynOctetMask | asynEnumMask,  /* Interrupt mask */
                    1, /* asynFlags.  This driver does block and it is not multi-device, so flag is 1 */
                    1, /* Autoconnect */
                    0, /* Default priority */
                    0), /* Default stack size*/   
                    shuttingDown_(0) 
{
    asynStatus status;
    int i;
    const char *functionName = "cpswAsynDriver";
    //ScalVals.resize(nEntries, (ScalVal) NULL);
    ScalVals.reserve(nEntries);

    if (ScalVals[0] == NULL)
	printf("ScalVals initialized NULL\n");
    else
	printf("ScalVals NOT initialized NULL\n");

    pollEventId_ = epicsEventMustCreate(epicsEventEmpty);
    path_ = p;
}

/** Called when asyn clients call pasynInt32->write().
  * This function sends a signal to the cyclicTask thread if the value of P_Run has changed.
  * For all parameters it sets the value in the parameter library and calls any registered callbacks..
  * \param[in] pasynUser pasynUser structure that encodes the reason and address.
  * \param[in] value Value to write. */
asynStatus cpswAsynDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    const char* functionName = "writeInt32";

    uint32_t u32 = (uint32_t) value;
    status = getAddress(pasynUser, &addr); if (status != asynSuccess) return(status);
    
    /* Fetch the parameter string name for possible use in debugging */
    getParamName(function, &paramName);

    if(ScalVals[function] != NULL) {
        try {
        ScalVals[function]->setVal( &u32, 1 );
        } catch (CPSWError &e ) {
            printf("CPSW Error: %s\n", e.getInfo().c_str());
            status = asynError;
        }
    }
    if (status != asynSuccess) return (status);

    setIntegerParam(addr, function, value); 

    /* Do callbacks so higher layers see any changes */
    status = (asynStatus) callParamCallbacks();
    
    if (status) 
        epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize, 
                  "%s:%s: status=%d, function=%d, name=%s, value=%d", 
                  driverName, functionName, status, function, paramName, value);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d, name=%s, value=%d\n", 
              driverName, functionName, function, paramName, value);
    return status;
}

/** Called when asyn clients call pasynFloat64Array->read().
  * Returns the value of the P_Waveform or P_TimeBase arrays.  
  * \param[in] pasynUser pasynUser structure that encodes the reason and address.
  * \param[in] value Pointer to the array to read.
  * \param[in] nElements Number of elements to read.
  * \param[out] nIn Number of elements actually read. */
asynStatus cpswAsynDriver::readInt32(asynUser *pasynUser, epicsInt32 *value)
{
    int function = pasynUser->reason;
    int addr = 0;
    asynStatus status = asynSuccess;
    epicsTimeStamp timeStamp; getTimeStamp(&timeStamp);
    const char *functionName = "readInt32";
    const char *paramName;
    
    uint32_t u32;

    status = getAddress(pasynUser, &addr); if (status != asynSuccess) return(status);

    /* Fetch the parameter string name for possible use in debugging */
    getParamName(function, &paramName);
    if (ScalVals[function] != NULL) {
        scalValToIntegerParam(function, value);
    }
    if (status != asynSuccess) return (status);
    
    /* Set the timestamp */
    pasynUser->timestamp = timeStamp;


    if (status) 
        epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize, 
                  "%s:%s: status=%d, function=%d", 
                  driverName, functionName, status, function);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d\n", 
              driverName, functionName, function);
    return status;
}

asynStatus cpswAsynDriver::readOctet(asynUser *pasynUser, char *value, size_t maxChars,
                                        size_t *nActual, int *eomReason)
{
    int function = pasynUser->reason;
    int addr = 0;
    asynStatus status = asynSuccess;
    epicsTimeStamp timeStamp; getTimeStamp(&timeStamp);
    const char *functionName = "readOctet";
    const char *paramName;
    
//    status = getAddress(pasynUser, &addr); if (status != asynSuccess) return(status);
    getAddress(pasynUser, &addr);
    /* Fetch the parameter string name for possible use in debugging */
    getParamName(function, &paramName);
    if(ScalVals[function] != NULL) {
        try { 
            *nActual = (size_t) ScalVals[function]->getVal( (uint8_t*)value, maxChars );
        } catch (CPSWError &e ) {
            printf("CPSW Error: %s\n", e.getInfo().c_str());
            status = asynError;
         }
    }
    if (status != asynSuccess) return (status);
    /* Set the timestamp */
    setStringParam(addr, function, value); 

    /* Do callbacks so higher layers see any changes */
    status = (asynStatus) callParamCallbacks();
    pasynUser->timestamp = timeStamp;

    if (status) 
        epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize, 
                  "%s:%s: status=%d, function=%d", 
                  driverName, functionName, status, function);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d\n", 
              driverName, functionName, function);
    return status;
}
 
asynStatus cpswAsynDriver::createParam(          const char *name, asynParamType type, int *index, ScalVal(*create)(Path p))
{
    int list;
    asynStatus status;

    // All parameters lists support the same parameters, so add the parameter name to all lists
    for (list=0; list<this->maxAddr; list++) {
        status = createParam(list, name, type, index, create);
        if (status) return asynError;
    }
    return asynSuccess;
}

asynStatus cpswAsynDriver::createParam(int list, const char *name, asynParamType type, int *index, ScalVal(*create)(Path p))
{
    asynStatus status = asynSuccess;
    Path pOut = path_->findByName(name);

    asynPortDriver::createParam(list, name, type, index);
    ScalVals[*index] = create(pOut);
    return status;
}

/** Starts the poller thread.
 ** Derived classes will typically call this at near the end of their constructor.
 ** Derived classes can typically use the base class implementation of the poller thread,
 ** but are free to reimplement it if necessary.
 ** \param[in] pollPeriod The time between polls. */
asynStatus cpswAsynDriver::startPoller(double pollPeriod)
{
  pollPeriod_ = pollPeriod;
  epicsThreadCreate("asynPoller", 
                    epicsThreadPriorityLow,
                    epicsThreadGetStackSize(epicsThreadStackMedium),
                    (EPICSTHREADFUNC)asynPollerC, (void *)this);                
  return asynSuccess;
}      

/** Wakes up the poller thread to make it start polling. */
asynStatus cpswAsynDriver::wakeupPoller()
{ 
  epicsEventSignal(pollEventId_);                                                                         
  return asynSuccess;
} 
  
/** Polls the device.
 ** The base class cpswPoller thread calls this method once.
 ** This base class implementation does nothing.  Derived classes can implement this method if there
 ** are parameters that need to be polled. */
asynStatus cpswAsynDriver::poll()    
{                                                                        
  return asynSuccess;
} 
  
static void asynPollerC(void *drvPvt)
{ 
  cpswAsynDriver *pCpswDriver = (cpswAsynDriver*)drvPvt;      
  pCpswDriver->asynPoller();                                                              
} 

void cpswAsynDriver::asynPoller()
{
  double timeout;
  int status;

  timeout = pollPeriod_;
  wakeupPoller();  /* Force on poll at startup */

  while(1) {
    if (timeout != 0.) status = epicsEventWaitWithTimeout(pollEventId_, timeout);
    else               status = epicsEventWait(pollEventId_);
    if (status == epicsEventWaitOK) {
 /* We got an event, rather than a timeout.  This is because other software
 ** knows that we should do a poll.
 **/
    }
    lock();
    if (shuttingDown_) {
      unlock();
      break;
    }
    poll();
    unlock();
  }
}


/** Build a file name from component parts.
  * \param[in] maxChars  The size of the fullFileName string.
  * \param[out] fullFileName The constructed file name including the file path.
  * 
  * This is a convenience function that constructs a complete file name
  * from the NDFilePath, NDFileName, NDFileNumber, and
  * NDFileTemplate parameters. If NDAutoIncrement is true then it increments the
  * NDFileNumber after creating the file name.
  */
int cpswAsynDriver::createFileName(int maxChars, char *fullFileName)
{
    /* Formats a complete file name from the components defined in NDStdDriverParams */
    int status = asynSuccess;
    char filePath[MAX_FILENAME_LEN];
    char fileName[MAX_FILENAME_LEN];
    char fileTemplate[MAX_FILENAME_LEN];
    int fileNumber;
    int autoIncrement;
    int len;
    
    this->checkPath();
    status |= getStringParam(NDFilePath, sizeof(filePath), filePath);
    status |= getStringParam(NDFileName, sizeof(fileName), fileName); 
    status |= getStringParam(NDFileTemplate, sizeof(fileTemplate), fileTemplate); 
    status |= getIntegerParam(NDFileNumber, &fileNumber);
    status |= getIntegerParam(NDAutoIncrement, &autoIncrement);
    if (status) return(status);
    len = epicsSnprintf(fullFileName, maxChars, fileTemplate, 
                        filePath, fileName, fileNumber);
    if (len < 0) {
        status |= asynError;
        return(status);
    }
    if (autoIncrement) {
        fileNumber++;
        status |= setIntegerParam(NDFileNumber, fileNumber);
    }
    return(status);   
}

/** Checks whether the directory specified NDFilePath parameter exists.
  * 
  * This is a convenience function that determinesthe directory specified NDFilePath parameter exists.
  * It sets the value of NDFilePathExists to 0 (does not exist) or 1 (exists).  
  * It also adds a trailing '/' character to the path if one is not present.
  * Returns a error status if the directory does not exist.
  */
int cpswAsynDriver::checkPath()
{
    /* Formats a complete file name from the components defined in NDStdDriverParams */
    int status = asynError;
    char filePath[MAX_FILENAME_LEN];
    int hasTerminator=0;
    struct stat buff;
    size_t len;
    int isDir=0;
    int pathExists=0;
    
    status = getStringParam(NDFilePath, sizeof(filePath), filePath);
    len = strlen(filePath);
    if (len == 0) return(asynSuccess);
    /* If the path contains a trailing '/' or '\' remove it, because Windows won't find
     * the directory if it has that trailing character */
    if ((filePath[len-1] == '/') || (filePath[len-1] == '\\')) {
        filePath[len-1] = 0;
        len--;
        hasTerminator=1;
    }
    status = stat(filePath, &buff);
    if (!status) isDir = (S_IFDIR & buff.st_mode);
    if (!status && isDir) {
        pathExists = 1;
        status = asynSuccess;
    }
    /* If the path did not have a trailing terminator then add it if there is room */
    if (!hasTerminator) {
        if (len < MAX_FILENAME_LEN-2) strcat(filePath, "/");
        setStringParam(NDFilePath, filePath);
    }
    setIntegerParam(NDFilePathExists, pathExists);
    return(status);   
}
/** Build a file name from component parts.
  * \param[in] maxChars  The size of the fullFileName string.
  * \param[out] filePath The file path.
  * \param[out] fileName The constructed file name without file file path.
  * 
  * This is a convenience function that constructs a file path and file name
  * from the NDFilePath, NDFileName, NDFileNumber, and
  * NDFileTemplate parameters. If NDAutoIncrement is true then it increments the
  * NDFileNumber after creating the file name.
  */
int cpswAsynDriver::createFileName(int maxChars, char *filePath, char *fileName)
{
    /* Formats a complete file name from the components defined in NDStdDriverParams */
    int status = asynSuccess;
    char fileTemplate[MAX_FILENAME_LEN];
    char name[MAX_FILENAME_LEN];
    int fileNumber;
    int autoIncrement;
    int len;
    
    this->checkPath();
    status |= getStringParam(NDFilePath, maxChars, filePath); 
    status |= getStringParam(NDFileName, sizeof(name), name); 
    status |= getStringParam(NDFileTemplate, sizeof(fileTemplate), fileTemplate); 
    status |= getIntegerParam(NDFileNumber, &fileNumber);
    status |= getIntegerParam(NDAutoIncrement, &autoIncrement);
    if (status) return(status);
    len = epicsSnprintf(fileName, maxChars, fileTemplate, 
                        name, fileNumber);
    if (len < 0) {
        status |= asynError;
        return(status);
    }
    if (autoIncrement) {
        fileNumber++;
        status |= setIntegerParam(NDFileNumber, fileNumber);
    }
    return(status);   
}

/** Get a scalVal and syn to param asyn param library
 *
 * \param[in] function The integer function from asyn param library
 * \param[out] value   The int32 value returned from ScalVal
 *
 * */
asynStatus cpswAsynDriver::scalValToIntegerParam(int function, epicsInt32 *value)
{
    asynStatus status = asynSuccess;
    uint32_t u32;
    try {
        ScalVals[function]->getVal( &u32, 1 );
    }
    catch(CPSWError &e) {
        return asynError;
    }
    *value = (epicsInt32) u32;
    setIntegerParam(0, function, *value);
    callParamCallbacks();
    return status;
}

extern "C" {

/** EPICS iocsh callable function to call constructor for the cpswAsynDriver class.
  * \param[in] portName The name of the asyn port driver to be created.
  * \param[in] maxPoints The maximum  number of points in the volt and time arrays */
int cpswAsynDriverConfigure(const char *portName, const char *path)
{
    Path p;
    int nelms = 1;
    int nentries = 0;

    try {
//        Path p = root->findByName( path );
    } catch (CPSWError &e ) {
        printf("CPSW Error: %s\n", e.getInfo().c_str());
    }
    new cpswAsynDriver(portName, p, nelms, nentries);
    return(asynSuccess);
}


/* EPICS iocsh shell commands */

static const iocshArg initArg0 = { "portName",iocshArgString};
static const iocshArg initArg1 = { "path",iocshArgString};
static const iocshArg * const initArgs[] = {&initArg0,
                                            &initArg1};
static const iocshFuncDef initFuncDef = {"cpswAsynDriverConfigure",2,initArgs};
static void initCallFunc(const iocshArgBuf *args)
{
    cpswAsynDriverConfigure(args[0].sval, args[1].sval);
}

void cpswAsynDriverRegister(void)
{
    iocshRegister(&initFuncDef,initCallFunc);
}

epicsExportRegistrar(cpswAsynDriverRegister);

}

