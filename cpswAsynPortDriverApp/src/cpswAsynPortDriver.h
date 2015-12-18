#ifndef CPSW_ASYN_DRIVER_H
#define CPSW_ASYN_DRIVER_H

#include "asynPortDriver.h"
#include <cpsw_api_user.h>

#include <epicsEvent.h>
#include <epicsTypes.h>

/** Maximum length of a filename or any of its components */
#define MAX_FILENAME_LEN 256


#define NDFilePathString        "FILE_PATH"         /**< (asynOctet,    r/w) The file path */
#define NDFilePathExistsString  "FILE_PATH_EXISTS"  /**< (asynInt32,    r/w) File path exists? */
#define NDFileNameString        "FILE_NAME"         /**< (asynOctet,    r/w) The file name */
#define NDFileNumberString      "FILE_NUMBER"       /**< (asynInt32,    r/w) The next file number */
#define NDFileTemplateString    "FILE_TEMPLATE"     /**< (asynOctet,    r/w) The file format template; C-style format string */
#define NDAutoIncrementString   "AUTO_INCREMENT"    /**< (asynInt32,    r/w) Autoincrement file number; 0=No, 1=Yes */
#define NDFullFileNameString    "FULL_FILE_NAME"    /**< (asynOctet,    r/o) The actual complete file name for the last file saved */
#define NDFileFormatString      "FILE_FORMAT"       /**< (asynInt32,    r/w) The data format to use for saving the file.  */
#define NDAutoSaveString        "AUTO_SAVE"         /**< (asynInt32,    r/w) Automatically save files */
#define NDWriteFileString       "WRITE_FILE"        /**< (asynInt32,    r/w) Manually save the most recent array to a file when value=1 */
#define NDReadFileString        "READ_FILE"         /**< (asynInt32,    r/w) Manually read file when value=1 */
#define NDFileWriteModeString   "WRITE_MODE"        /**< (asynInt32,    r/w) File saving mode (NDFileMode_t) */
#define NDFileWriteStatusString "WRITE_STATUS"      /**< (asynInt32,    r/w) File write status */
#define NDFileWriteMessageString "WRITE_MESSAGE"    /**< (asynOctet,    r/w) File write message */
#define NDFileNumCaptureString  "NUM_CAPTURE"       /**< (asynInt32,    r/w) Number of arrays to capture */
#define NDFileNumCapturedString "NUM_CAPTURED"      /**< (asynInt32,    r/o) Number of arrays already captured */
#define NDFileCaptureString     "CAPTURE"           /**< (asynInt32,    r/w) Start or stop capturing arrays */
#define NDFileDeleteDriverFileString  "DELETE_DRIVER_FILE"  /**< (asynInt32,    r/w) Delete driver file */
#define NDFileLazyOpenString    "FILE_LAZY_OPEN"    /**< (asynInt32,    r/w) Don't open file until first frame arrives in Stream mode */


/** Class that demonstrates the use of the asynPortDriver base class to greatly simplify the task
  * of writing an asyn port driver.
  * This class does a simple simulation of a digital oscilloscope.  It computes a waveform, computes
  * statistics on the waveform, and does callbacks with the statistics and the waveform data itself. 
  * I have made the methods of this class public in order to generate doxygen documentation for them,
  * but they should really all be private. */
class cpswAsynDriver : public asynPortDriver {
public:
    cpswAsynDriver(const char *portName, Path p, int nelms, int nEntries);
                 
    /* These are the methods that we override from asynPortDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus readInt32(asynUser *pasynUser, epicsInt32 *value);
    virtual asynStatus readOctet(asynUser *pasynUser, char *value, size_t maxChars,
                                        size_t *nActual, int *eomReason);

    virtual asynStatus createParam(          const char *name, asynParamType type, int *index, ScalVal(*create)(Path p));
    virtual asynStatus createParam(int list, const char *name, asynParamType type, int *index, ScalVal(*create)(Path p));

    /* These are the methods that are new to this class */
    void cyclicTask(void);
    virtual asynStatus startPoller(double pollPeriod);
    virtual asynStatus wakeupPoller();
    virtual asynStatus poll();
    void asynPoller();


    /* These are the methods that are new to this class */
    virtual int checkPath();
    virtual int createFileName(int maxChars, char *fullFileName);
    virtual int createFileName(int maxChars, char *filePath, char *fileName);
protected:
    /** cpsw path */
    Path path_;

    epicsEventId pollEventId_;    /**< Event ID to wake up poller */
    double pollPeriod_;           /**< The time between polls */
    int shuttingDown_;

    int NDPortNameSelf;
    #define FIRST_NDARRAY_PARAM NDPortNameSelf
    int NDArraySizeX;
    int NDArraySizeY;
    int NDArraySizeZ;
    int NDArraySize;
    int NDNDimensions;
    int NDDimensions;
    int NDDataType;
    int NDColorMode;
    int NDUniqueId;
    int NDTimeStamp;
    int NDEpicsTSSec;
    int NDEpicsTSNsec;
    int NDBayerPattern;
    int NDArrayCounter;
    int NDFilePath;
    int NDFilePathExists;
    int NDFileName;
    int NDFileNumber;
    int NDFileTemplate;
    int NDAutoIncrement;
    int NDFullFileName;
    int NDFileFormat;
    int NDAutoSave;
    int NDWriteFile;
    int NDReadFile;
    int NDFileWriteMode;
    int NDFileWriteStatus;
    int NDFileWriteMessage;
    int NDFileNumCapture;
    int NDFileNumCaptured;
    int NDFileCapture;
    int NDFileDeleteDriverFile;
    int NDFileLazyOpen;
    int NDAttributesFile;
    int NDArrayData;
    int NDArrayCallbacks;
    int NDPoolMaxBuffers;
    int NDPoolAllocBuffers;
    int NDPoolFreeBuffers;
    int NDPoolMaxMemory;
    int NDPoolUsedMemory;
    #define LAST_NDARRAY_PARAM NDPoolUsedMemory


    std::vector<ScalVal> ScalVals;

    virtual asynStatus scalValToIntegerParam(int function, epicsInt32 *value);
//    virtual asynStatus paramToScalVal(int function);

private:
    /* Our data */
};
#endif
