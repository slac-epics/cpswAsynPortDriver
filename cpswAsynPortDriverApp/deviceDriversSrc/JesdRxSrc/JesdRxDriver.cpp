#include "JesdRxDriver.h"
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

static const char *driverName = "JesdRxDriver";


JesdRxDriver::JesdRxDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("JesdRx"), nelms, NUM_JESDRX_PARAMS)
{

/* Registers */
   createParam(EnableString, asynParamInt32, &p_Enable, IScalVal::create);
   createParam(SysrefDelayString, asynParamInt32, &p_SysrefDelay, IScalVal::create);
   createParam(CommonControlString, asynParamInt32, &p_CommonControl, IScalVal::create);
   createParam(SubClassString, asynParamInt32, &p_SubClass, IScalVal::create);
   createParam(ReplaceEnableString, asynParamInt32, &p_ReplaceEnable, IScalVal::create);
   createParam(ResetGTsString, asynParamInt32, &p_ResetGTs, IScalVal::create);
   createParam(ClearErrorsString, asynParamInt32, &p_ClearErrors, IScalVal::create);
   createParam(InvertSyncString, asynParamInt32, &p_InvertSync, IScalVal::create);
   createParam(L1_Test_thrString, asynParamInt32, &p_L1_Test_thr, IScalVal::create);
   createParam(L1_Threshold_LowString, asynParamInt32, &p_L1_Threshold_Low, IScalVal::create);
   createParam(L1_Threshold_HighString, asynParamInt32, &p_L1_Threshold_High, IScalVal::create);
   createParam(L2_Test_thrString, asynParamInt32, &p_L2_Test_thr, IScalVal::create);
   createParam(L2_Threshold_LowString, asynParamInt32, &p_L2_Threshold_Low, IScalVal::create);
   createParam(L2_Threshold_HighString, asynParamInt32, &p_L2_Threshold_High, IScalVal::create);
   createParam(L1_StatusString, asynParamInt32, &p_L1_Status, IScalVal::create);
   createParam(L1_GTXReadyString, asynParamInt32, &p_L1_GTXReady, IScalVal::create);
   createParam(L1_DataValidString, asynParamInt32, &p_L1_DataValid, IScalVal::create);
   createParam(L1_AlignErrString, asynParamInt32, &p_L1_AlignErr, IScalVal::create);
   createParam(L1_nSyncString, asynParamInt32, &p_L1_nSync, IScalVal::create);
   createParam(L1_RxBuffUflString, asynParamInt32, &p_L1_RxBuffUfl, IScalVal::create);
   createParam(L1_RxBuffOflString, asynParamInt32, &p_L1_RxBuffOfl, IScalVal::create);
   createParam(L1_PositionErrString, asynParamInt32, &p_L1_PositionErr, IScalVal::create);
   createParam(L1_RxEnabledString, asynParamInt32, &p_L1_RxEnabled, IScalVal::create);
   createParam(L1_SysRefDetectedString, asynParamInt32, &p_L1_SysRefDetected, IScalVal::create);
   createParam(L1_CommaDetectedString, asynParamInt32, &p_L1_CommaDetected, IScalVal::create);
   createParam(L1_DisparityErrString, asynParamInt32, &p_L1_DisparityErr, IScalVal::create);
   createParam(L1_DecErrString, asynParamInt32, &p_L1_DecErr, IScalVal::create);
   createParam(L1_ElBuffLatencyString, asynParamInt32, &p_L1_ElBuffLatency, IScalVal::create);
   createParam(L2_StatusString, asynParamInt32, &p_L2_Status, IScalVal::create);
   createParam(L2_GTXRdyString, asynParamInt32, &p_L2_GTXRdy, IScalVal::create);
   createParam(L2_DataValidString, asynParamInt32, &p_L2_DataValid, IScalVal::create);
   createParam(L2_AlignErrString, asynParamInt32, &p_L2_AlignErr, IScalVal::create);
   createParam(L2_nSyncString, asynParamInt32, &p_L2_nSync, IScalVal::create);
   createParam(L2_RxBuffUflString, asynParamInt32, &p_L2_RxBuffUfl, IScalVal::create);
   createParam(L2_RxBuffOflString, asynParamInt32, &p_L2_RxBuffOfl, IScalVal::create);
   createParam(L2_PositionErrString, asynParamInt32, &p_L2_PositionErr, IScalVal::create);
   createParam(L2_RxEnabledString, asynParamInt32, &p_L2_RxEnabled, IScalVal::create);
   createParam(L2_SysRefDetectedString, asynParamInt32, &p_L2_SysRefDetected, IScalVal::create);
   createParam(L2_CommaDetectedString, asynParamInt32, &p_L2_CommaDetected, IScalVal::create);
   createParam(L2_DisparityErrString, asynParamInt32, &p_L2_DisparityErr, IScalVal::create);
   createParam(L2_DecErrString, asynParamInt32, &p_L2_DecErr, IScalVal::create);
   createParam(L3_StatusString, asynParamInt32, &p_L3_Status, IScalVal::create);
   createParam(L3_GTXRdyString, asynParamInt32, &p_L3_GTXRdy, IScalVal::create);
   createParam(L3_DataValidString, asynParamInt32, &p_L3_DataValid, IScalVal::create);
   createParam(L3_AlignErrString, asynParamInt32, &p_L3_AlignErr, IScalVal::create);
   createParam(L3_nSyncString, asynParamInt32, &p_L3_nSync, IScalVal::create);
   createParam(L3_RxBuffUflString, asynParamInt32, &p_L3_RxBuffUfl, IScalVal::create);
   createParam(L3_RxBuffOflString, asynParamInt32, &p_L3_RxBuffOfl, IScalVal::create);
   createParam(L3_PositionErrString, asynParamInt32, &p_L3_PositionErr, IScalVal::create);
   createParam(L3_RxEnabledString, asynParamInt32, &p_L3_RxEnabled, IScalVal::create);
   createParam(L3_SysRefDetectedString, asynParamInt32, &p_L3_SysRefDetected, IScalVal::create);
   createParam(L3_CommaDetectedString, asynParamInt32, &p_L3_CommaDetected, IScalVal::create);
   createParam(L3_DisparityErrString, asynParamInt32, &p_L3_DisparityErr, IScalVal::create);
   createParam(L3_DecErrString, asynParamInt32, &p_L3_DecErr, IScalVal::create);
   createParam(L4_StatusString, asynParamInt32, &p_L4_Status, IScalVal::create);
   createParam(L4_GTXRdyString, asynParamInt32, &p_L4_GTXRdy, IScalVal::create);
   createParam(L4_DataValidString, asynParamInt32, &p_L4_DataValid, IScalVal::create);
   createParam(L4_AlignErrString, asynParamInt32, &p_L4_AlignErr, IScalVal::create);
   createParam(L4_nSyncString, asynParamInt32, &p_L4_nSync, IScalVal::create);
   createParam(L4_RxBuffUflString, asynParamInt32, &p_L4_RxBuffUfl, IScalVal::create);
   createParam(L4_RxBuffOflString, asynParamInt32, &p_L4_RxBuffOfl, IScalVal::create);
   createParam(L4_PositionErrString, asynParamInt32, &p_L4_PositionErr, IScalVal::create);
   createParam(L4_RxEnabledString, asynParamInt32, &p_L4_RxEnabled, IScalVal::create);
   createParam(L4_SysRefDetectedString, asynParamInt32, &p_L4_SysRefDetected, IScalVal::create);
   createParam(L4_CommaDetectedString, asynParamInt32, &p_L4_CommaDetected, IScalVal::create);
   createParam(L4_DisparityErrString, asynParamInt32, &p_L4_DisparityErr, IScalVal::create);
   createParam(L4_DecErrString, asynParamInt32, &p_L4_DecErr, IScalVal::create);
   createParam(L5_StatusString, asynParamInt32, &p_L5_Status, IScalVal::create);
   createParam(L5_GTXRdyString, asynParamInt32, &p_L5_GTXRdy, IScalVal::create);
   createParam(L5_DataValidString, asynParamInt32, &p_L5_DataValid, IScalVal::create);
   createParam(L5_AlignErrString, asynParamInt32, &p_L5_AlignErr, IScalVal::create);
   createParam(L5_nSyncString, asynParamInt32, &p_L5_nSync, IScalVal::create);
   createParam(L5_RxBuffUflString, asynParamInt32, &p_L5_RxBuffUfl, IScalVal::create);
   createParam(L5_RxBuffOflString, asynParamInt32, &p_L5_RxBuffOfl, IScalVal::create);
   createParam(L5_PositionErrString, asynParamInt32, &p_L5_PositionErr, IScalVal::create);
   createParam(L5_RxEnabledString, asynParamInt32, &p_L5_RxEnabled, IScalVal::create);
   createParam(L5_SysRefDetectedString, asynParamInt32, &p_L5_SysRefDetected, IScalVal::create);
   createParam(L5_CommaDetectedString, asynParamInt32, &p_L5_CommaDetected, IScalVal::create);
   createParam(L5_DisparityErrString, asynParamInt32, &p_L5_DisparityErr, IScalVal::create);
   createParam(L5_DecErrString, asynParamInt32, &p_L5_DecErr, IScalVal::create);
   createParam(L6_StatusString, asynParamInt32, &p_L6_Status, IScalVal::create);
   createParam(L6_GTXRdyString, asynParamInt32, &p_L6_GTXRdy, IScalVal::create);
   createParam(L6_DataValidString, asynParamInt32, &p_L6_DataValid, IScalVal::create);
   createParam(L6_AlignErrString, asynParamInt32, &p_L6_AlignErr, IScalVal::create);
   createParam(L6_nSyncString, asynParamInt32, &p_L6_nSync, IScalVal::create);
   createParam(L6_RxBuffUflString, asynParamInt32, &p_L6_RxBuffUfl, IScalVal::create);
   createParam(L6_RxBuffOflString, asynParamInt32, &p_L6_RxBuffOfl, IScalVal::create);
   createParam(L6_PositionErrString, asynParamInt32, &p_L6_PositionErr, IScalVal::create);
   createParam(L6_RxEnabledString, asynParamInt32, &p_L6_RxEnabled, IScalVal::create);
   createParam(L6_SysRefDetectedString, asynParamInt32, &p_L6_SysRefDetected, IScalVal::create);
   createParam(L6_CommaDetectedString, asynParamInt32, &p_L6_CommaDetected, IScalVal::create);
   createParam(L6_DisparityErrString, asynParamInt32, &p_L6_DisparityErr, IScalVal::create);
   createParam(L6_DecErrString, asynParamInt32, &p_L6_DecErr, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CClearErrorsString, asynParamInt32, &p_C_ClearErrors);
   asynPortDriver::createParam(CRestartGTsString, asynParamInt32, &p_C_RestartGTs);
}

asynStatus JesdRxDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_ClearErrors ) {
        ClearErrors();
    }
    else if( function == p_C_RestartGTs ) {
        RestartGTs();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus JesdRxDriver::ClearErrors()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_ClearErrors]->setVal( &u32, 1 );
     u32 = 0;
     ScalVals[p_ClearErrors]->setVal( &u32, 1 );

   } catch (CPSWError &e) {
     status = asynError;
   }

   return status;
}
asynStatus JesdRxDriver::RestartGTs()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_ResetGTs]->setVal( &u32, 1 );
     u32 = 0;
     ScalVals[p_ResetGTs]->setVal( &u32, 1 );

   } catch (CPSWError &e) {
     status = asynError;
   }

   return status;
}

extern "C" int JesdRxCreate(const char *portName, const char *path)
{
  
  Path p = IDev::getRootDev()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  new JesdRxDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg JesdRxCreateArg0 = {"Port name", iocshArgString};
static const iocshArg JesdRxCreateArg1 = {"JesdRx port name", iocshArgString};
static const iocshArg * const JesdRxCreateArgs[] = {&JesdRxCreateArg0,
                                                           &JesdRxCreateArg1};
static const iocshFuncDef JesdRxCreateDef = {"JesdRxCreate", 2, JesdRxCreateArgs};
static void JesdRxCreateContollerCallFunc(const iocshArgBuf *args)
{
  JesdRxCreate(args[0].sval, args[1].sval);
}

static void JesdRxRegister(void)
{
  iocshRegister(&JesdRxCreateDef, JesdRxCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(JesdRxRegister);
}


