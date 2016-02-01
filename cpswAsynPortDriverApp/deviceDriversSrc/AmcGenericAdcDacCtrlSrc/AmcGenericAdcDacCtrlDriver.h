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
#define Adc0_t0String "Adc0_t0"
#define Adc0_t1String "Adc0_t1"
#define Adc0_t2String "Adc0_t2"
#define Adc0_t3String "Adc0_t3"
#define Adc1_t0String "Adc1_t0"
#define Adc1_t1String "Adc1_t1"
#define Adc1_t2String "Adc1_t2"
#define Adc1_t3String "Adc1_t3"
#define Adc2_t0String "Adc2_t0"
#define Adc2_t1String "Adc2_t1"
#define Adc2_t2String "Adc2_t2"
#define Adc2_t3String "Adc2_t3"
#define Adc3_t0String "Adc3_t0"
#define Adc3_t1String "Adc3_t1"
#define Adc3_t2String "Adc3_t2"
#define Adc3_t3String "Adc3_t3"
#define Dac0_t0String "Dac0_t0"
#define Dac0_t1String "Dac0_t1"
#define Dac0_t2String "Dac0_t2"
#define Dac0_t3String "Dac0_t3"
#define Dac1_t0String "Dac1_t0"
#define Dac1_t1String "Dac1_t1"
#define Dac1_t2String "Dac1_t2"
#define Dac1_t3String "Dac1_t3"
#define DacVcoString "DacVco"
#define AmcClkFreqString "AmcClkFreq"
#define LmkClkSelString "LmkClkSel"
#define LmkRstString "LmkRst"
#define lmkSyncString "lmkSync"
#define LmkStatusString "LmkStatus"
#define loopbackString "loopback"
#define CounterResetString "CounterReset"

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
    int p_Adc0_t0;
    int p_Adc0_t1;
    int p_Adc0_t2;
    int p_Adc0_t3;
    int p_Adc1_t0;
    int p_Adc1_t1;
    int p_Adc1_t2;
    int p_Adc1_t3;
    int p_Adc2_t0;
    int p_Adc2_t1;
    int p_Adc2_t2;
    int p_Adc2_t3;
    int p_Adc3_t0;
    int p_Adc3_t1;
    int p_Adc3_t2;
    int p_Adc3_t3;
    int p_Dac0_t0;
    int p_Dac0_t1;
    int p_Dac0_t2;
    int p_Dac0_t3;
    int p_Dac1_t0;
    int p_Dac1_t1;
    int p_Dac1_t2;
    int p_Dac1_t3;
    int p_DacVco;
    int p_AmcClkFreq;
    int p_LmkClkSel;
    int p_LmkRst;
    int p_lmkSync;
    int p_LmkStatus;
    int p_loopback;
    int p_CounterReset;
    #define LAST_AMCGENERICADCDACCTRL_PARAM p_CounterReset


    #define NUM_AMCGENERICADCDACCTRL_PARAMS (&LAST_AMCGENERICADCDACCTRL_PARAM - &FIRST_AMCGENERICADCDACCTRL_PARAM + 1)

private:

};

#endif

