#ifndef JESDRX_DRIVER_H
#define JESDRX_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define EnableString "Enable"
#define SysrefDelayString "SysrefDelay"
#define CommonControlString "CommonControl"
#define SubClassString "SubClass"
#define ReplaceEnableString "ReplaceEnable"
#define ResetGTsString "ResetGTs"
#define ClearErrorsString "ClearErrors"
#define InvertSyncString "InvertSync"
#define L1_Test_thrString "L1_Test_thr"
#define L1_Threshold_LowString "L1_Threshold_Low"
#define L1_Threshold_HighString "L1_Threshold_High"
#define L2_Test_thrString "L2_Test_thr"
#define L2_Threshold_LowString "L2_Threshold_Low"
#define L2_Threshold_HighString "L2_Threshold_High"
#define L1_StatusString "L1_Status"
#define L1_GTXReadyString "L1_GTXReady"
#define L1_DataValidString "L1_DataValid"
#define L1_AlignErrString "L1_AlignErr"
#define L1_nSyncString "L1_nSync"
#define L1_RxBuffUflString "L1_RxBuffUfl"
#define L1_RxBuffOflString "L1_RxBuffOfl"
#define L1_PositionErrString "L1_PositionErr"
#define L1_RxEnabledString "L1_RxEnabled"
#define L1_SysRefDetectedString "L1_SysRefDetected"
#define L1_CommaDetectedString "L1_CommaDetected"
#define L1_DisparityErrString "L1_DisparityErr"
#define L1_DecErrString "L1_DecErr"
#define L1_ElBuffLatencyString "L1_ElBuffLatency"
#define L2_StatusString "L2_Status"
#define L2_GTXRdyString "L2_GTXRdy"
#define L2_DataValidString "L2_DataValid"
#define L2_AlignErrString "L2_AlignErr"
#define L2_nSyncString "L2_nSync"
#define L2_RxBuffUflString "L2_RxBuffUfl"
#define L2_RxBuffOflString "L2_RxBuffOfl"
#define L2_PositionErrString "L2_PositionErr"
#define L2_RxEnabledString "L2_RxEnabled"
#define L2_SysRefDetectedString "L2_SysRefDetected"
#define L2_CommaDetectedString "L2_CommaDetected"
#define L2_DisparityErrString "L2_DisparityErr"
#define L2_DecErrString "L2_DecErr"
#define L3_StatusString "L3_Status"
#define L3_GTXRdyString "L3_GTXRdy"
#define L3_DataValidString "L3_DataValid"
#define L3_AlignErrString "L3_AlignErr"
#define L3_nSyncString "L3_nSync"
#define L3_RxBuffUflString "L3_RxBuffUfl"
#define L3_RxBuffOflString "L3_RxBuffOfl"
#define L3_PositionErrString "L3_PositionErr"
#define L3_RxEnabledString "L3_RxEnabled"
#define L3_SysRefDetectedString "L3_SysRefDetected"
#define L3_CommaDetectedString "L3_CommaDetected"
#define L3_DisparityErrString "L3_DisparityErr"
#define L3_DecErrString "L3_DecErr"
#define L4_StatusString "L4_Status"
#define L4_GTXRdyString "L4_GTXRdy"
#define L4_DataValidString "L4_DataValid"
#define L4_AlignErrString "L4_AlignErr"
#define L4_nSyncString "L4_nSync"
#define L4_RxBuffUflString "L4_RxBuffUfl"
#define L4_RxBuffOflString "L4_RxBuffOfl"
#define L4_PositionErrString "L4_PositionErr"
#define L4_RxEnabledString "L4_RxEnabled"
#define L4_SysRefDetectedString "L4_SysRefDetected"
#define L4_CommaDetectedString "L4_CommaDetected"
#define L4_DisparityErrString "L4_DisparityErr"
#define L4_DecErrString "L4_DecErr"
#define L5_StatusString "L5_Status"
#define L5_GTXRdyString "L5_GTXRdy"
#define L5_DataValidString "L5_DataValid"
#define L5_AlignErrString "L5_AlignErr"
#define L5_nSyncString "L5_nSync"
#define L5_RxBuffUflString "L5_RxBuffUfl"
#define L5_RxBuffOflString "L5_RxBuffOfl"
#define L5_PositionErrString "L5_PositionErr"
#define L5_RxEnabledString "L5_RxEnabled"
#define L5_SysRefDetectedString "L5_SysRefDetected"
#define L5_CommaDetectedString "L5_CommaDetected"
#define L5_DisparityErrString "L5_DisparityErr"
#define L5_DecErrString "L5_DecErr"
#define L6_StatusString "L6_Status"
#define L6_GTXRdyString "L6_GTXRdy"
#define L6_DataValidString "L6_DataValid"
#define L6_AlignErrString "L6_AlignErr"
#define L6_nSyncString "L6_nSync"
#define L6_RxBuffUflString "L6_RxBuffUfl"
#define L6_RxBuffOflString "L6_RxBuffOfl"
#define L6_PositionErrString "L6_PositionErr"
#define L6_RxEnabledString "L6_RxEnabled"
#define L6_SysRefDetectedString "L6_SysRefDetected"
#define L6_CommaDetectedString "L6_CommaDetected"
#define L6_DisparityErrString "L6_DisparityErr"
#define L6_DecErrString "L6_DecErr"

/* Commands */
#define CClearErrors String "C_ClearErrors "
#define CRestartGTsString "C_RestartGTs"


 /* This class implements the AxiVersion driver. */
class JesdRxDriver : public cpswAsynDriver {
public:
    JesdRxDriver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_Enable;
    #define FIRST_JESDRX_PARAM p_Enable
    int p_SysrefDelay;
    int p_CommonControl;
    int p_SubClass;
    int p_ReplaceEnable;
    int p_ResetGTs;
    int p_ClearErrors;
    int p_InvertSync;
    int p_L1_Test_thr;
    int p_L1_Threshold_Low;
    int p_L1_Threshold_High;
    int p_L2_Test_thr;
    int p_L2_Threshold_Low;
    int p_L2_Threshold_High;
    int p_L1_Status;
    int p_L1_GTXReady;
    int p_L1_DataValid;
    int p_L1_AlignErr;
    int p_L1_nSync;
    int p_L1_RxBuffUfl;
    int p_L1_RxBuffOfl;
    int p_L1_PositionErr;
    int p_L1_RxEnabled;
    int p_L1_SysRefDetected;
    int p_L1_CommaDetected;
    int p_L1_DisparityErr;
    int p_L1_DecErr;
    int p_L1_ElBuffLatency;
    int p_L2_Status;
    int p_L2_GTXRdy;
    int p_L2_DataValid;
    int p_L2_AlignErr;
    int p_L2_nSync;
    int p_L2_RxBuffUfl;
    int p_L2_RxBuffOfl;
    int p_L2_PositionErr;
    int p_L2_RxEnabled;
    int p_L2_SysRefDetected;
    int p_L2_CommaDetected;
    int p_L2_DisparityErr;
    int p_L2_DecErr;
    int p_L3_Status;
    int p_L3_GTXRdy;
    int p_L3_DataValid;
    int p_L3_AlignErr;
    int p_L3_nSync;
    int p_L3_RxBuffUfl;
    int p_L3_RxBuffOfl;
    int p_L3_PositionErr;
    int p_L3_RxEnabled;
    int p_L3_SysRefDetected;
    int p_L3_CommaDetected;
    int p_L3_DisparityErr;
    int p_L3_DecErr;
    int p_L4_Status;
    int p_L4_GTXRdy;
    int p_L4_DataValid;
    int p_L4_AlignErr;
    int p_L4_nSync;
    int p_L4_RxBuffUfl;
    int p_L4_RxBuffOfl;
    int p_L4_PositionErr;
    int p_L4_RxEnabled;
    int p_L4_SysRefDetected;
    int p_L4_CommaDetected;
    int p_L4_DisparityErr;
    int p_L4_DecErr;
    int p_L5_Status;
    int p_L5_GTXRdy;
    int p_L5_DataValid;
    int p_L5_AlignErr;
    int p_L5_nSync;
    int p_L5_RxBuffUfl;
    int p_L5_RxBuffOfl;
    int p_L5_PositionErr;
    int p_L5_RxEnabled;
    int p_L5_SysRefDetected;
    int p_L5_CommaDetected;
    int p_L5_DisparityErr;
    int p_L5_DecErr;
    int p_L6_Status;
    int p_L6_GTXRdy;
    int p_L6_DataValid;
    int p_L6_AlignErr;
    int p_L6_nSync;
    int p_L6_RxBuffUfl;
    int p_L6_RxBuffOfl;
    int p_L6_PositionErr;
    int p_L6_RxEnabled;
    int p_L6_SysRefDetected;
    int p_L6_CommaDetected;
    int p_L6_DisparityErr;
    int p_L6_DecErr;
/* Commands */
    int p_C_ClearErrors ;
    int p_C_RestartGTs;
    #define LAST_JESDRX_PARAM p_C_RestartGTs


    #define NUM_JESDRX_PARAMS (&LAST_JESDRX_PARAM - &FIRST_JESDRX_PARAM + 1)

private:
    asynStatus ClearErrors ();
    asynStatus RestartGTs();

};

#endif

