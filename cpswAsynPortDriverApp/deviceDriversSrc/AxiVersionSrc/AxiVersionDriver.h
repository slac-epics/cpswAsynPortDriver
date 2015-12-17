#ifndef AXIVERSION_DRIVER_H
#define AXIVERSION_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define FpgaVersionString "FpgaVersion"
#define ScratchPadString "ScratchPad"
#define DeviceDnaHighString "DeviceDnaHigh"
#define DeviceDnaLowString "DeviceDnaLow"
#define FdSerialHighString "FdSerialHigh"
#define FdSerialLowString "FdSerialLow"
#define MasterResetString "MasterReset"
#define FpgaReloadString "FpgaReload"
#define FpgaReloadAddressString "FpgaReloadAddress"
#define CounterString "Counter"
#define FpgaReloadHaltString "FpgaReloadHalt"
#define UserConstantsString "UserConstants"
#define BuildStampString "BuildStamp"

/* Commands */
#define CMasterResetString "C_MasterReset"
#define CFpgaReloadString "C_FpgaReload"
#define CCounterResetString "C_CounterReset"


 /* This class implements the AxiVersion driver. */
class AxiVersionDriver : public cpswAsynDriver {
public:
    AxiVersionDriver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_FpgaVersion;
    #define FIRST_AXIVERSION_PARAM p_FpgaVersion
    int p_ScratchPad;
    int p_DeviceDnaHigh;
    int p_DeviceDnaLow;
    int p_FdSerialHigh;
    int p_FdSerialLow;
    int p_MasterReset;
    int p_FpgaReload;
    int p_FpgaReloadAddress;
    int p_Counter;
    int p_FpgaReloadHalt;
    int p_UserConstants;
    int p_BuildStamp;
/* Commands */
    int p_C_MasterReset;
    int p_C_FpgaReload;
    int p_C_CounterReset;
    #define LAST_AXIVERSION_PARAM p_C_CounterReset


    #define NUM_AXIVERSION_PARAMS (&LAST_AXIVERSION_PARAM - &FIRST_AXIVERSION_PARAM + 1)

private:
    asynStatus MasterReset();
    asynStatus FpgaReload();
    asynStatus CounterReset();

};

#endif

