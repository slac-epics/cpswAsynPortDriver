#include "Adc16Dx370Driver.h"
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

static const char *driverName = "Adc16Dx370Driver";


Adc16Dx370Driver::Adc16Dx370Driver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName(portName), nelms, NUM_ADC16DX370_PARAMS)
{

/* Registers */
   createParam(ID_DEVICE_TYPEString, asynParamInt32, &p_ID_DEVICE_TYPE, IScalVal::create);
   createParam(PD_MODEString, asynParamInt32, &p_PD_MODE, IScalVal::create);
   createParam(ID_PROD_UPPERString, asynParamInt32, &p_ID_PROD_UPPER, IScalVal::create);
   createParam(ID_PROD_LOWERString, asynParamInt32, &p_ID_PROD_LOWER, IScalVal::create);
   createParam(ID_MASKREVString, asynParamInt32, &p_ID_MASKREV, IScalVal::create);
   createParam(ID_VNDR_UPPERString, asynParamInt32, &p_ID_VNDR_UPPER, IScalVal::create);
   createParam(ID_VNDR_LOWERString, asynParamInt32, &p_ID_VNDR_LOWER, IScalVal::create);
   createParam(ADC_StatusString, asynParamInt32, &p_ADC_Status, IScalVal::create);
   createParam(Clock_readyString, asynParamInt32, &p_Clock_ready, IScalVal::create);
   createParam(Calibration_doneString, asynParamInt32, &p_Calibration_done, IScalVal::create);
   createParam(PLL_lockString, asynParamInt32, &p_PLL_lock, IScalVal::create);
   createParam(Aligned_to_sysrefString, asynParamInt32, &p_Aligned_to_sysref, IScalVal::create);
   createParam(Realigned_to_sysrefString, asynParamInt32, &p_Realigned_to_sysref, IScalVal::create);
   createParam(Sync_form_FPGAString, asynParamInt32, &p_Sync_form_FPGA, IScalVal::create);
   createParam(Link_activeString, asynParamInt32, &p_Link_active, IScalVal::create);
   createParam(SYS_ENString, asynParamInt32, &p_SYS_EN, IScalVal::create);
   createParam(AdcReg0x0000String, asynParamInt32, &p_AdcReg0x0000, IScalVal::create);
   createParam(AdcReg0x0002String, asynParamInt32, &p_AdcReg0x0002, IScalVal::create);
   createParam(AdcReg0x0003String, asynParamInt32, &p_AdcReg0x0003, IScalVal::create);
   createParam(AdcReg0x0004String, asynParamInt32, &p_AdcReg0x0004, IScalVal::create);
   createParam(AdcReg0x0005String, asynParamInt32, &p_AdcReg0x0005, IScalVal::create);
   createParam(AdcReg0x0006String, asynParamInt32, &p_AdcReg0x0006, IScalVal::create);
   createParam(AdcReg0x000cString, asynParamInt32, &p_AdcReg0x000c, IScalVal::create);
   createParam(AdcReg0x000dString, asynParamInt32, &p_AdcReg0x000d, IScalVal::create);
   createParam(AdcReg0x000eString, asynParamInt32, &p_AdcReg0x000e, IScalVal::create);
   createParam(AdcReg0x000fString, asynParamInt32, &p_AdcReg0x000f, IScalVal::create);
   createParam(AdcReg0x0010String, asynParamInt32, &p_AdcReg0x0010, IScalVal::create);
   createParam(AdcReg0x0011String, asynParamInt32, &p_AdcReg0x0011, IScalVal::create);
   createParam(AdcReg0x0012String, asynParamInt32, &p_AdcReg0x0012, IScalVal::create);
   createParam(AdcReg0x0013String, asynParamInt32, &p_AdcReg0x0013, IScalVal::create);
   createParam(AdcReg0x0014String, asynParamInt32, &p_AdcReg0x0014, IScalVal::create);
   createParam(AdcReg0x0015String, asynParamInt32, &p_AdcReg0x0015, IScalVal::create);
   createParam(AdcReg0x0019String, asynParamInt32, &p_AdcReg0x0019, IScalVal::create);
   createParam(AdcReg0x003bString, asynParamInt32, &p_AdcReg0x003b, IScalVal::create);
   createParam(AdcReg0x003cString, asynParamInt32, &p_AdcReg0x003c, IScalVal::create);
   createParam(AdcReg0x003dString, asynParamInt32, &p_AdcReg0x003d, IScalVal::create);
   createParam(AdcReg0x0047String, asynParamInt32, &p_AdcReg0x0047, IScalVal::create);
   createParam(AdcReg0x0060String, asynParamInt32, &p_AdcReg0x0060, IScalVal::create);
   createParam(AdcReg0x0061String, asynParamInt32, &p_AdcReg0x0061, IScalVal::create);
   createParam(AdcReg0x0062String, asynParamInt32, &p_AdcReg0x0062, IScalVal::create);
   createParam(AdcReg0x0063String, asynParamInt32, &p_AdcReg0x0063, IScalVal::create);
   createParam(AdcReg0x0070String, asynParamInt32, &p_AdcReg0x0070, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CCalibrateADCString, asynParamInt32, &p_C_CalibrateADC);
}

asynStatus Adc16Dx370Driver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_CalibrateADC ) {
        status = CalibrateADC();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}

asynStatus Adc16Dx370Driver::CalibrateADC()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 3;
  
   try {
     ScalVals[p_PD_MODE]->setVal( &u32, 1);
     epicsThreadSleep(0.1);
     u32 = 0;
     ScalVals[p_PD_MODE]->setVal( &u32, 1);
   } catch (CPSWError &e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
     status = asynError;
   }

   return status;
}

extern "C" int Adc16Dx370Create(const char *portName, const char *path)
{
  
  Path p = IDev::getRootDev()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  new Adc16Dx370Driver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg Adc16Dx370CreateArg0 = {"Port name", iocshArgString};
static const iocshArg Adc16Dx370CreateArg1 = {"Adc16Dx370 port name", iocshArgString};
static const iocshArg * const Adc16Dx370CreateArgs[] = {&Adc16Dx370CreateArg0,
                                                           &Adc16Dx370CreateArg1};
static const iocshFuncDef Adc16Dx370CreateDef = {"Adc16Dx370Create", 2, Adc16Dx370CreateArgs};
static void Adc16Dx370CreateContollerCallFunc(const iocshArgBuf *args)
{
  Adc16Dx370Create(args[0].sval, args[1].sval);
}

static void Adc16Dx370Register(void)
{
  iocshRegister(&Adc16Dx370CreateDef, Adc16Dx370CreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(Adc16Dx370Register);
}


