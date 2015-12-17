#include "PrbsTxDriver.h"
#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <device_library.h>
#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iocsh.h>
#include <epicsThread.h>

#include <epicsExport.h>

static const char *driverName = "PrbsTxDriver";


PrbsTxDriver::PrbsTxDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("PrbsTx"), nelms, NUM_PRBSTX_PARAMS)
{

/* Registers */
   createParam(ConfigStatusString, asynParamInt32, &p_ConfigStatus, IScalVal::create);
   createParam(AxiEnString, asynParamInt32, &p_AxiEn, IScalVal::create);
   createParam(TxEnString, asynParamInt32, &p_TxEn, IScalVal::create);
   createParam(BusyString, asynParamInt32, &p_Busy, IScalVal::create);
   createParam(OverflowString, asynParamInt32, &p_Overflow, IScalVal::create);
   createParam(PacketLengthString, asynParamInt32, &p_PacketLength, IScalVal::create);
   createParam(AxiStreamCfgString, asynParamInt32, &p_AxiStreamCfg, IScalVal::create);
   createParam(tDestString, asynParamInt32, &p_tDest, IScalVal::create);
   createParam(tIdString, asynParamInt32, &p_tId, IScalVal::create);
   createParam(DataCountString, asynParamInt32, &p_DataCount, IScalVal::create);
   createParam(EventCountString, asynParamInt32, &p_EventCount, IScalVal::create);
   createParam(RandomDataString, asynParamInt32, &p_RandomData, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(COneShotString, asynParamInt32, &p_C_OneShot);
}

asynStatus PrbsTxDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_OneShot ) {
        OneShot();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus PrbsTxDriver::OneShot()
{
   asynStatus status = asynSuccess;
/* Fill in command logic here */
   printf("Command OneShot not yet implemented!\n");

   return status;
}

extern "C" int PrbsTxCreate(const char *portName, const char *path)
{
  
  Path p = IDev::getRootDev()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  printf("Child found\n");
  printf("Childl nelms:%d\n", c->getNelms());
  new PrbsTxDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg PrbsTxCreateArg0 = {"Port name", iocshArgString};
static const iocshArg PrbsTxCreateArg1 = {"PrbsTx port name", iocshArgString};
static const iocshArg * const PrbsTxCreateArgs[] = {&PrbsTxCreateArg0,
                                                           &PrbsTxCreateArg1};
static const iocshFuncDef PrbsTxCreateDef = {"PrbsTxCreate", 2, PrbsTxCreateArgs};
static void PrbsTxCreateContollerCallFunc(const iocshArgBuf *args)
{
  PrbsTxCreate(args[0].sval, args[1].sval);
}

static void PrbsTxRegister(void)
{
  iocshRegister(&PrbsTxCreateDef, PrbsTxCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(PrbsTxRegister);
}


