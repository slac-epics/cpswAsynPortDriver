#ifndef AMCGENERICADCDACCTRL_DRIVER_H
#define AMCGENERICADCDACCTRL_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define AdcValid0String "AdcValid0"
#define AdcValid1String "AdcValid1"
#define AdcValid2String "AdcValid2"
#define AdcValid3String "AdcValid3"
#define StatusRegString "StatusReg"
#define Adc0String "Adc0"
#define Adc1String "Adc1"
#define Adc2String "Adc2"
#define Adc3String "Adc3"
#define Dac0String "Dac0"
#define Dac1String "Dac1"
#define DacVcoString "DacVco"
#define AmcClkFreqString "AmcClkFreq"
#define LmkClkSelString "LmkClkSel"
#define LmkRstString "LmkRst"
#define lmkSyncString "lmkSync"
#define LmkStatusString "LmkStatus"
#define loopbackString "loopback"
#define CounterResetString "CounterReset"
#define LmkMuxSelString "LmkMuxSel"
#define DebugLogEnString "DebugLogEn"
#define DebugLogClrString "DebugLogClr"

/* Commands */


 /* This class implements the AxiVersion driver. */
class AmcGenericAdcDacCtrlDriver : public cpswAsynDriver {
public:
    AmcGenericAdcDacCtrlDriver(const char *portName, Path p, int nelms);



protected:
/* Registers */
    int p_AdcValid0;
    #define FIRST_AMCGENERICADCDACCTRL_PARAM p_AdcValid0
    int p_AdcValid1;
    int p_AdcValid2;
    int p_AdcValid3;
    int p_StatusReg;
    int p_Adc0;
    int p_Adc1;
    int p_Adc2;
    int p_Adc3;
    int p_Dac0;
    int p_Dac1;
    int p_DacVco;
    int p_AmcClkFreq;
    int p_LmkClkSel;
    int p_LmkRst;
    int p_lmkSync;
    int p_LmkStatus;
    int p_loopback;
    int p_CounterReset;
    int p_LmkMuxSel;
    int p_DebugLogEn;
    int p_DebugLogClr;
    #define LAST_AMCGENERICADCDACCTRL_PARAM p_DebugLogClr


    #define NUM_AMCGENERICADCDACCTRL_PARAMS (&LAST_AMCGENERICADCDACCTRL_PARAM - &FIRST_AMCGENERICADCDACCTRL_PARAM + 1)

private:

};

#endif

