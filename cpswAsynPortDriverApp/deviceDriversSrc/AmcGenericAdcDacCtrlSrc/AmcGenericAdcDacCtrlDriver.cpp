#include "AmcGenericAdcDacCtrlDriver.h"
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

static const char *driverName = "AmcGenericAdcDacCtrlDriver";


AmcGenericAdcDacCtrlDriver::AmcGenericAdcDacCtrlDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("AmcGenericAdcDacCtrl"), nelms, NUM_AMCGENERICADCDACCTRL_PARAMS)
{

/* Registers */
   createParam(AdcValid0String, asynParamInt32, &p_AdcValid0, IScalVal::create);
   createParam(AdcValid1String, asynParamInt32, &p_AdcValid1, IScalVal::create);
   createParam(AdcValid2String, asynParamInt32, &p_AdcValid2, IScalVal::create);
   createParam(AdcValid3String, asynParamInt32, &p_AdcValid3, IScalVal::create);
   createParam(StatusRegString, asynParamInt32, &p_StatusReg, IScalVal::create);
   createParam(Adc0_t0String, asynParamInt32, &p_Adc0_t0, IScalVal::create);
   createParam(Adc0_t1String, asynParamInt32, &p_Adc0_t1, IScalVal::create);
   createParam(Adc0_t2String, asynParamInt32, &p_Adc0_t2, IScalVal::create);
   createParam(Adc0_t3String, asynParamInt32, &p_Adc0_t3, IScalVal::create);
   createParam(Adc1_t0String, asynParamInt32, &p_Adc1_t0, IScalVal::create);
   createParam(Adc1_t1String, asynParamInt32, &p_Adc1_t1, IScalVal::create);
   createParam(Adc1_t2String, asynParamInt32, &p_Adc1_t2, IScalVal::create);
   createParam(Adc1_t3String, asynParamInt32, &p_Adc1_t3, IScalVal::create);
   createParam(Adc2_t0String, asynParamInt32, &p_Adc2_t0, IScalVal::create);
   createParam(Adc2_t1String, asynParamInt32, &p_Adc2_t1, IScalVal::create);
   createParam(Adc2_t2String, asynParamInt32, &p_Adc2_t2, IScalVal::create);
   createParam(Adc2_t3String, asynParamInt32, &p_Adc2_t3, IScalVal::create);
   createParam(Adc3_t0String, asynParamInt32, &p_Adc3_t0, IScalVal::create);
   createParam(Adc3_t1String, asynParamInt32, &p_Adc3_t1, IScalVal::create);
   createParam(Adc3_t2String, asynParamInt32, &p_Adc3_t2, IScalVal::create);
   createParam(Adc3_t3String, asynParamInt32, &p_Adc3_t3, IScalVal::create);
   createParam(Dac0_t0String, asynParamInt32, &p_Dac0_t0, IScalVal::create);
   createParam(Dac0_t1String, asynParamInt32, &p_Dac0_t1, IScalVal::create);
   createParam(Dac0_t2String, asynParamInt32, &p_Dac0_t2, IScalVal::create);
   createParam(Dac0_t3String, asynParamInt32, &p_Dac0_t3, IScalVal::create);
   createParam(Dac1_t0String, asynParamInt32, &p_Dac1_t0, IScalVal::create);
   createParam(Dac1_t1String, asynParamInt32, &p_Dac1_t1, IScalVal::create);
   createParam(Dac1_t2String, asynParamInt32, &p_Dac1_t2, IScalVal::create);
   createParam(Dac1_t3String, asynParamInt32, &p_Dac1_t3, IScalVal::create);
   createParam(DacVcoString, asynParamInt32, &p_DacVco, IScalVal::create);
   createParam(AmcClkFreqString, asynParamInt32, &p_AmcClkFreq, IScalVal::create);
   createParam(LmkClkSelString, asynParamInt32, &p_LmkClkSel, IScalVal::create);
   createParam(LmkRstString, asynParamInt32, &p_LmkRst, IScalVal::create);
   createParam(lmkSyncString, asynParamInt32, &p_lmkSync, IScalVal::create);
   createParam(LmkStatusString, asynParamInt32, &p_LmkStatus, IScalVal::create);
   createParam(loopbackString, asynParamInt32, &p_loopback, IScalVal::create);
   createParam(CounterResetString, asynParamInt32, &p_CounterReset, IScalVal::create);
}



extern "C" int AmcGenericAdcDacCtrlCreate(const char *portName, const char *path)
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
  new AmcGenericAdcDacCtrlDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AmcGenericAdcDacCtrlCreateArg0 = {"Port name", iocshArgString};
static const iocshArg AmcGenericAdcDacCtrlCreateArg1 = {"AmcGenericAdcDacCtrl port name", iocshArgString};
static const iocshArg * const AmcGenericAdcDacCtrlCreateArgs[] = {&AmcGenericAdcDacCtrlCreateArg0,
                                                           &AmcGenericAdcDacCtrlCreateArg1};
static const iocshFuncDef AmcGenericAdcDacCtrlCreateDef = {"AmcGenericAdcDacCtrlCreate", 2, AmcGenericAdcDacCtrlCreateArgs};
static void AmcGenericAdcDacCtrlCreateContollerCallFunc(const iocshArgBuf *args)
{
  AmcGenericAdcDacCtrlCreate(args[0].sval, args[1].sval);
}

static void AmcGenericAdcDacCtrlRegister(void)
{
  iocshRegister(&AmcGenericAdcDacCtrlCreateDef, AmcGenericAdcDacCtrlCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(AmcGenericAdcDacCtrlRegister);
}


