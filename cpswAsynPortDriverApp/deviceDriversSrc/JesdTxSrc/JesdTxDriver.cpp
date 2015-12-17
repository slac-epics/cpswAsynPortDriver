#include "JesdTxDriver.h"
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

static const char *driverName = "JesdTxDriver";


JesdTxDriver::JesdTxDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("JesdTx"), nelms, NUM_JESDTX_PARAMS)
{

/* Registers */
   createParam(EnableString, asynParamInt32, &p_Enable, IScalVal::create);
   createParam(CommonControlString, asynParamInt32, &p_CommonControl, IScalVal::create);
   createParam(SubClassString, asynParamInt32, &p_SubClass, IScalVal::create);
   createParam(ReplaceEnableString, asynParamInt32, &p_ReplaceEnable, IScalVal::create);
   createParam(ResetGTsString, asynParamInt32, &p_ResetGTs, IScalVal::create);
   createParam(InvertSyncString, asynParamInt32, &p_InvertSync, IScalVal::create);
   createParam(EnableTestSigString, asynParamInt32, &p_EnableTestSig, IScalVal::create);
   createParam(PeriodRampStepString, asynParamInt32, &p_PeriodRampStep, IScalVal::create);
   createParam(RampStepString, asynParamInt32, &p_RampStep, IScalVal::create);
   createParam(SquarePeriodString, asynParamInt32, &p_SquarePeriod, IScalVal::create);
   createParam(LowAmplitudeValString, asynParamInt32, &p_LowAmplitudeVal, IScalVal::create);
   createParam(HighAmplitudeValString, asynParamInt32, &p_HighAmplitudeVal, IScalVal::create);
   createParam(L1_StatusString, asynParamInt32, &p_L1_Status, IScalVal::create);
   createParam(L1_GTXReadyString, asynParamInt32, &p_L1_GTXReady, IScalVal::create);
   createParam(L1_DataValidString, asynParamInt32, &p_L1_DataValid, IScalVal::create);
   createParam(L1_IlasActiveString, asynParamInt32, &p_L1_IlasActive, IScalVal::create);
   createParam(L1_nSyncString, asynParamInt32, &p_L1_nSync, IScalVal::create);
   createParam(L1_TxEnabledString, asynParamInt32, &p_L1_TxEnabled, IScalVal::create);
   createParam(L1_SysRefDetectedString, asynParamInt32, &p_L1_SysRefDetected, IScalVal::create);
   createParam(L2_StatusString, asynParamInt32, &p_L2_Status, IScalVal::create);
   createParam(L2_GTXRdyString, asynParamInt32, &p_L2_GTXRdy, IScalVal::create);
   createParam(L2_DataValidString, asynParamInt32, &p_L2_DataValid, IScalVal::create);
   createParam(L2_IlasActiveString, asynParamInt32, &p_L2_IlasActive, IScalVal::create);
   createParam(L2_nSyncString, asynParamInt32, &p_L2_nSync, IScalVal::create);
   createParam(L2_TxEnabledString, asynParamInt32, &p_L2_TxEnabled, IScalVal::create);
   createParam(L2_SysRefDetectedString, asynParamInt32, &p_L2_SysRefDetected, IScalVal::create);
   createParam(L1_SignalSelectString, asynParamInt32, &p_L1_SignalSelect, IScalVal::create);
   createParam(L1_data_out_muxString, asynParamInt32, &p_L1_data_out_mux, IScalVal::create);
   createParam(L1_test_out_muxString, asynParamInt32, &p_L1_test_out_mux, IScalVal::create);
   createParam(L2_SignalSelectString, asynParamInt32, &p_L2_SignalSelect, IScalVal::create);
   createParam(L2_data_out_muxString, asynParamInt32, &p_L2_data_out_mux, IScalVal::create);
   createParam(L2_test_out_muxString, asynParamInt32, &p_L2_test_out_mux, IScalVal::create);
}



extern "C" int JesdTxCreate(const char *portName, const char *path)
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
  new JesdTxDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg JesdTxCreateArg0 = {"Port name", iocshArgString};
static const iocshArg JesdTxCreateArg1 = {"JesdTx port name", iocshArgString};
static const iocshArg * const JesdTxCreateArgs[] = {&JesdTxCreateArg0,
                                                           &JesdTxCreateArg1};
static const iocshFuncDef JesdTxCreateDef = {"JesdTxCreate", 2, JesdTxCreateArgs};
static void JesdTxCreateContollerCallFunc(const iocshArgBuf *args)
{
  JesdTxCreate(args[0].sval, args[1].sval);
}

static void JesdTxRegister(void)
{
  iocshRegister(&JesdTxCreateDef, JesdTxCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(JesdTxRegister);
}


