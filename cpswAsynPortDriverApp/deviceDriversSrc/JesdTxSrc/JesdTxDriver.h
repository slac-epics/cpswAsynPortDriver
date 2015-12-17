#ifndef JESDTX_DRIVER_H
#define JESDTX_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define EnableString "Enable"
#define CommonControlString "CommonControl"
#define SubClassString "SubClass"
#define ReplaceEnableString "ReplaceEnable"
#define ResetGTsString "ResetGTs"
#define InvertSyncString "InvertSync"
#define EnableTestSigString "EnableTestSig"
#define PeriodRampStepString "PeriodRampStep"
#define RampStepString "RampStep"
#define SquarePeriodString "SquarePeriod"
#define LowAmplitudeValString "LowAmplitudeVal"
#define HighAmplitudeValString "HighAmplitudeVal"
#define L1_StatusString "L1_Status"
#define L1_GTXReadyString "L1_GTXReady"
#define L1_DataValidString "L1_DataValid"
#define L1_IlasActiveString "L1_IlasActive"
#define L1_nSyncString "L1_nSync"
#define L1_TxEnabledString "L1_TxEnabled"
#define L1_SysRefDetectedString "L1_SysRefDetected"
#define L2_StatusString "L2_Status"
#define L2_GTXRdyString "L2_GTXRdy"
#define L2_DataValidString "L2_DataValid"
#define L2_IlasActiveString "L2_IlasActive"
#define L2_nSyncString "L2_nSync"
#define L2_TxEnabledString "L2_TxEnabled"
#define L2_SysRefDetectedString "L2_SysRefDetected"
#define L1_SignalSelectString "L1_SignalSelect"
#define L1_data_out_muxString "L1_data_out_mux"
#define L1_test_out_muxString "L1_test_out_mux"
#define L2_SignalSelectString "L2_SignalSelect"
#define L2_data_out_muxString "L2_data_out_mux"
#define L2_test_out_muxString "L2_test_out_mux"

/* Commands */


 /* This class implements the AxiVersion driver. */
class JesdTxDriver : public cpswAsynDriver {
public:
    JesdTxDriver(const char *portName, Path p, int nelms);



protected:
/* Registers */
    int p_Enable;
    #define FIRST_JESDTX_PARAM p_Enable
    int p_CommonControl;
    int p_SubClass;
    int p_ReplaceEnable;
    int p_ResetGTs;
    int p_InvertSync;
    int p_EnableTestSig;
    int p_PeriodRampStep;
    int p_RampStep;
    int p_SquarePeriod;
    int p_LowAmplitudeVal;
    int p_HighAmplitudeVal;
    int p_L1_Status;
    int p_L1_GTXReady;
    int p_L1_DataValid;
    int p_L1_IlasActive;
    int p_L1_nSync;
    int p_L1_TxEnabled;
    int p_L1_SysRefDetected;
    int p_L2_Status;
    int p_L2_GTXRdy;
    int p_L2_DataValid;
    int p_L2_IlasActive;
    int p_L2_nSync;
    int p_L2_TxEnabled;
    int p_L2_SysRefDetected;
    int p_L1_SignalSelect;
    int p_L1_data_out_mux;
    int p_L1_test_out_mux;
    int p_L2_SignalSelect;
    int p_L2_data_out_mux;
    int p_L2_test_out_mux;
    #define LAST_JESDTX_PARAM p_L2_test_out_mux


    #define NUM_JESDTX_PARAMS (&LAST_JESDTX_PARAM - &FIRST_JESDTX_PARAM + 1)

private:

};

#endif

