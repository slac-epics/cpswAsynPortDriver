#ifndef AXI_VERISON_DRIVER_H
#define AXI_VERSION_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

#define FpgaVersionString        "FpgaVersion"
#define ScratchPadString         "ScratchPad"
#define DeviceDnaHighString      "DeviceDnaHigh"
#define DeviceDnaLowString       "DeviceDnaLow"
#define FdSerialHighString       "FdSerialHigh"
#define FdSerialLowString        "FdSerialLow"
#define MasterResetString        "MasterReset"
#define FpgaReloadString         "FpgaReload"
#define FpgaReloadAddressString  "FpgaReloadAddress"
#define CounterString            "Counter"
#define FpgaReloadHaltString     "FpgaReloadHalt"
#define UserConstantsString      "UserConstants"
#define BuildStampString         "BuildStamp"

 /* This class implements the AxiVersion driver. */
class AxiVersionDriver : public cpswAsynDriver {
public:
    AxiVersionDriver(const char *portName, Path p, int nelms);

protected:
    int p_FpgaVersion;
    #define FIRST_AXIV_PARAM p_FpgaVersion
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
    #define LAST_AXIV_PARAM p_BuildStamp

    #define NUM_AXIV_PARAMS (&LAST_AXIV_PARAM - &FIRST_AXIV_PARAM + 1)
};

#endif
