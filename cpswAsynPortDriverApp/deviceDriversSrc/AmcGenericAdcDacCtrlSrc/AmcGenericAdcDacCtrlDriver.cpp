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
                 :cpswAsynDriver(portName, p, nelms, NUM_AMCGENERICADCDACCTRL_PARAMS)
{

/* Registers */
   createParam(AdcValid0String, asynParamInt32, &p_AdcValid0, IScalVal::create);
   createParam(AdcValid1String, asynParamInt32, &p_AdcValid1, IScalVal::create);
   createParam(AdcValid2String, asynParamInt32, &p_AdcValid2, IScalVal::create);
   createParam(AdcValid3String, asynParamInt32, &p_AdcValid3, IScalVal::create);
   createParam(StatusRegString, asynParamInt32, &p_StatusReg, IScalVal::create);
   createParam(Adc0String, asynParamInt32, &p_Adc0, IScalVal::create);
   createParam(Adc1String, asynParamInt32, &p_Adc1, IScalVal::create);
   createParam(Adc2String, asynParamInt32, &p_Adc2, IScalVal::create);
   createParam(Adc3String, asynParamInt32, &p_Adc3, IScalVal::create);
   createParam(Dac0String, asynParamInt32, &p_Dac0, IScalVal::create);
   createParam(Dac1String, asynParamInt32, &p_Dac1, IScalVal::create);
   createParam(DacVcoString, asynParamInt32, &p_DacVco, IScalVal::create);
   createParam(AmcClkFreqString, asynParamInt32, &p_AmcClkFreq, IScalVal::create);
   createParam(LmkClkSelString, asynParamInt32, &p_LmkClkSel, IScalVal::create);
   createParam(LmkRstString, asynParamInt32, &p_LmkRst, IScalVal::create);
   createParam(lmkSyncString, asynParamInt32, &p_lmkSync, IScalVal::create);
   createParam(LmkStatusString, asynParamInt32, &p_LmkStatus, IScalVal::create);
   createParam(loopbackString, asynParamInt32, &p_loopback, IScalVal::create);
   createParam(CounterResetString, asynParamInt32, &p_CounterReset, IScalVal::create);
   createParam(LmkMuxSelString, asynParamInt32, &p_LmkMuxSel, IScalVal::create);
   createParam(DebugLogEnString, asynParamInt32, &p_DebugLogEn, IScalVal::create);
   createParam(DebugLogClrString, asynParamInt32, &p_DebugLogClr, IScalVal::create);
}



extern "C" int AmcGenericAdcDacCtrlCreate(const char *portName, const char *path)
{
  
  Path p = IPath::create();
  try {  
    p = p->findByName(path);
  } catch( CPSWError &e ) {
    printf("CPSWError: %s\n", e.getInfo().c_str());     
    return -1;
  }
  new AmcGenericAdcDacCtrlDriver(portName, p, 0);
  return 1;
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


