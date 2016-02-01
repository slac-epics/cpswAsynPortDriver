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
   createParam(AdcReg0x0100String, asynParamInt32, &p_AdcReg0x0100, IScalVal::create);
   createParam(AdcReg0x0101String, asynParamInt32, &p_AdcReg0x0101, IScalVal::create);
   createParam(AdcReg0x0102String, asynParamInt32, &p_AdcReg0x0102, IScalVal::create);
   createParam(AdcReg0x0103String, asynParamInt32, &p_AdcReg0x0103, IScalVal::create);
   createParam(AdcReg0x0104String, asynParamInt32, &p_AdcReg0x0104, IScalVal::create);
   createParam(AdcReg0x0105String, asynParamInt32, &p_AdcReg0x0105, IScalVal::create);
   createParam(AdcReg0x0106String, asynParamInt32, &p_AdcReg0x0106, IScalVal::create);
   createParam(AdcReg0x0107String, asynParamInt32, &p_AdcReg0x0107, IScalVal::create);
   createParam(AdcReg0x0108String, asynParamInt32, &p_AdcReg0x0108, IScalVal::create);
   createParam(AdcReg0x0109String, asynParamInt32, &p_AdcReg0x0109, IScalVal::create);
   createParam(AdcReg0x010aString, asynParamInt32, &p_AdcReg0x010a, IScalVal::create);
   createParam(AdcReg0x010bString, asynParamInt32, &p_AdcReg0x010b, IScalVal::create);
   createParam(AdcReg0x010cString, asynParamInt32, &p_AdcReg0x010c, IScalVal::create);
   createParam(AdcReg0x010dString, asynParamInt32, &p_AdcReg0x010d, IScalVal::create);
   createParam(AdcReg0x010eString, asynParamInt32, &p_AdcReg0x010e, IScalVal::create);
   createParam(AdcReg0x010fString, asynParamInt32, &p_AdcReg0x010f, IScalVal::create);
   createParam(AdcReg0x0110String, asynParamInt32, &p_AdcReg0x0110, IScalVal::create);
   createParam(AdcReg0x0111String, asynParamInt32, &p_AdcReg0x0111, IScalVal::create);
   createParam(AdcReg0x0112String, asynParamInt32, &p_AdcReg0x0112, IScalVal::create);
   createParam(AdcReg0x0113String, asynParamInt32, &p_AdcReg0x0113, IScalVal::create);
   createParam(AdcReg0x0114String, asynParamInt32, &p_AdcReg0x0114, IScalVal::create);
   createParam(AdcReg0x0115String, asynParamInt32, &p_AdcReg0x0115, IScalVal::create);
   createParam(AdcReg0x0116String, asynParamInt32, &p_AdcReg0x0116, IScalVal::create);
   createParam(AdcReg0x0117String, asynParamInt32, &p_AdcReg0x0117, IScalVal::create);
   createParam(AdcReg0x0118String, asynParamInt32, &p_AdcReg0x0118, IScalVal::create);
   createParam(AdcReg0x0119String, asynParamInt32, &p_AdcReg0x0119, IScalVal::create);
   createParam(AdcReg0x011aString, asynParamInt32, &p_AdcReg0x011a, IScalVal::create);
   createParam(AdcReg0x011bString, asynParamInt32, &p_AdcReg0x011b, IScalVal::create);
   createParam(AdcReg0x011cString, asynParamInt32, &p_AdcReg0x011c, IScalVal::create);
   createParam(AdcReg0x011dString, asynParamInt32, &p_AdcReg0x011d, IScalVal::create);
   createParam(AdcReg0x011eString, asynParamInt32, &p_AdcReg0x011e, IScalVal::create);
   createParam(AdcReg0x011fString, asynParamInt32, &p_AdcReg0x011f, IScalVal::create);
   createParam(AdcReg0x0120String, asynParamInt32, &p_AdcReg0x0120, IScalVal::create);
   createParam(AdcReg0x0121String, asynParamInt32, &p_AdcReg0x0121, IScalVal::create);
   createParam(AdcReg0x0122String, asynParamInt32, &p_AdcReg0x0122, IScalVal::create);
   createParam(AdcReg0x0123String, asynParamInt32, &p_AdcReg0x0123, IScalVal::create);
   createParam(AdcReg0x0124String, asynParamInt32, &p_AdcReg0x0124, IScalVal::create);
   createParam(AdcReg0x0125String, asynParamInt32, &p_AdcReg0x0125, IScalVal::create);
   createParam(AdcReg0x0126String, asynParamInt32, &p_AdcReg0x0126, IScalVal::create);
   createParam(AdcReg0x0127String, asynParamInt32, &p_AdcReg0x0127, IScalVal::create);
   createParam(AdcReg0x0128String, asynParamInt32, &p_AdcReg0x0128, IScalVal::create);
   createParam(AdcReg0x0129String, asynParamInt32, &p_AdcReg0x0129, IScalVal::create);
   createParam(AdcReg0x012aString, asynParamInt32, &p_AdcReg0x012a, IScalVal::create);
   createParam(AdcReg0x012bString, asynParamInt32, &p_AdcReg0x012b, IScalVal::create);
   createParam(AdcReg0x012cString, asynParamInt32, &p_AdcReg0x012c, IScalVal::create);
   createParam(AdcReg0x012dString, asynParamInt32, &p_AdcReg0x012d, IScalVal::create);
   createParam(AdcReg0x012eString, asynParamInt32, &p_AdcReg0x012e, IScalVal::create);
   createParam(AdcReg0x012fString, asynParamInt32, &p_AdcReg0x012f, IScalVal::create);
   createParam(AdcReg0x0130String, asynParamInt32, &p_AdcReg0x0130, IScalVal::create);
   createParam(AdcReg0x0131String, asynParamInt32, &p_AdcReg0x0131, IScalVal::create);
   createParam(AdcReg0x0132String, asynParamInt32, &p_AdcReg0x0132, IScalVal::create);
   createParam(AdcReg0x0133String, asynParamInt32, &p_AdcReg0x0133, IScalVal::create);
   createParam(AdcReg0x0134String, asynParamInt32, &p_AdcReg0x0134, IScalVal::create);
   createParam(AdcReg0x0135String, asynParamInt32, &p_AdcReg0x0135, IScalVal::create);
   createParam(AdcReg0x0136String, asynParamInt32, &p_AdcReg0x0136, IScalVal::create);
   createParam(AdcReg0x0137String, asynParamInt32, &p_AdcReg0x0137, IScalVal::create);
   createParam(AdcReg0x0138String, asynParamInt32, &p_AdcReg0x0138, IScalVal::create);
   createParam(AdcReg0x0139String, asynParamInt32, &p_AdcReg0x0139, IScalVal::create);
   createParam(AdcReg0x013aString, asynParamInt32, &p_AdcReg0x013a, IScalVal::create);
   createParam(AdcReg0x013bString, asynParamInt32, &p_AdcReg0x013b, IScalVal::create);
   createParam(AdcReg0x013cString, asynParamInt32, &p_AdcReg0x013c, IScalVal::create);
   createParam(AdcReg0x013dString, asynParamInt32, &p_AdcReg0x013d, IScalVal::create);
   createParam(AdcReg0x013eString, asynParamInt32, &p_AdcReg0x013e, IScalVal::create);
   createParam(AdcReg0x013fString, asynParamInt32, &p_AdcReg0x013f, IScalVal::create);
   createParam(AdcReg0x0140String, asynParamInt32, &p_AdcReg0x0140, IScalVal::create);
   createParam(AdcReg0x0141String, asynParamInt32, &p_AdcReg0x0141, IScalVal::create);
   createParam(AdcReg0x0142String, asynParamInt32, &p_AdcReg0x0142, IScalVal::create);
   createParam(AdcReg0x0143String, asynParamInt32, &p_AdcReg0x0143, IScalVal::create);
   createParam(AdcReg0x0144String, asynParamInt32, &p_AdcReg0x0144, IScalVal::create);
   createParam(AdcReg0x0145String, asynParamInt32, &p_AdcReg0x0145, IScalVal::create);
   createParam(AdcReg0x0146String, asynParamInt32, &p_AdcReg0x0146, IScalVal::create);
   createParam(AdcReg0x0147String, asynParamInt32, &p_AdcReg0x0147, IScalVal::create);
   createParam(AdcReg0x0148String, asynParamInt32, &p_AdcReg0x0148, IScalVal::create);
   createParam(AdcReg0x0149String, asynParamInt32, &p_AdcReg0x0149, IScalVal::create);
   createParam(AdcReg0x014aString, asynParamInt32, &p_AdcReg0x014a, IScalVal::create);
   createParam(AdcReg0x014bString, asynParamInt32, &p_AdcReg0x014b, IScalVal::create);
   createParam(AdcReg0x014cString, asynParamInt32, &p_AdcReg0x014c, IScalVal::create);
   createParam(AdcReg0x014dString, asynParamInt32, &p_AdcReg0x014d, IScalVal::create);
   createParam(AdcReg0x014eString, asynParamInt32, &p_AdcReg0x014e, IScalVal::create);
   createParam(AdcReg0x014fString, asynParamInt32, &p_AdcReg0x014f, IScalVal::create);
   createParam(AdcReg0x0150String, asynParamInt32, &p_AdcReg0x0150, IScalVal::create);
   createParam(AdcReg0x0151String, asynParamInt32, &p_AdcReg0x0151, IScalVal::create);
   createParam(AdcReg0x0152String, asynParamInt32, &p_AdcReg0x0152, IScalVal::create);
   createParam(AdcReg0x0153String, asynParamInt32, &p_AdcReg0x0153, IScalVal::create);
   createParam(AdcReg0x0154String, asynParamInt32, &p_AdcReg0x0154, IScalVal::create);
   createParam(AdcReg0x0155String, asynParamInt32, &p_AdcReg0x0155, IScalVal::create);
   createParam(AdcReg0x0156String, asynParamInt32, &p_AdcReg0x0156, IScalVal::create);
   createParam(AdcReg0x0157String, asynParamInt32, &p_AdcReg0x0157, IScalVal::create);
   createParam(AdcReg0x0158String, asynParamInt32, &p_AdcReg0x0158, IScalVal::create);
   createParam(AdcReg0x0159String, asynParamInt32, &p_AdcReg0x0159, IScalVal::create);
   createParam(AdcReg0x015aString, asynParamInt32, &p_AdcReg0x015a, IScalVal::create);
   createParam(AdcReg0x015bString, asynParamInt32, &p_AdcReg0x015b, IScalVal::create);
   createParam(AdcReg0x015cString, asynParamInt32, &p_AdcReg0x015c, IScalVal::create);
   createParam(AdcReg0x015dString, asynParamInt32, &p_AdcReg0x015d, IScalVal::create);
   createParam(AdcReg0x015eString, asynParamInt32, &p_AdcReg0x015e, IScalVal::create);
   createParam(AdcReg0x015fString, asynParamInt32, &p_AdcReg0x015f, IScalVal::create);
   createParam(AdcReg0x0160String, asynParamInt32, &p_AdcReg0x0160, IScalVal::create);
   createParam(AdcReg0x0161String, asynParamInt32, &p_AdcReg0x0161, IScalVal::create);
   createParam(AdcReg0x0162String, asynParamInt32, &p_AdcReg0x0162, IScalVal::create);
   createParam(AdcReg0x0163String, asynParamInt32, &p_AdcReg0x0163, IScalVal::create);
   createParam(AdcReg0x0164String, asynParamInt32, &p_AdcReg0x0164, IScalVal::create);
   createParam(AdcReg0x0165String, asynParamInt32, &p_AdcReg0x0165, IScalVal::create);
   createParam(AdcReg0x0166String, asynParamInt32, &p_AdcReg0x0166, IScalVal::create);
   createParam(AdcReg0x0167String, asynParamInt32, &p_AdcReg0x0167, IScalVal::create);
   createParam(AdcReg0x0168String, asynParamInt32, &p_AdcReg0x0168, IScalVal::create);
   createParam(AdcReg0x0169String, asynParamInt32, &p_AdcReg0x0169, IScalVal::create);
   createParam(AdcReg0x016aString, asynParamInt32, &p_AdcReg0x016a, IScalVal::create);
   createParam(AdcReg0x016bString, asynParamInt32, &p_AdcReg0x016b, IScalVal::create);
   createParam(AdcReg0x016cString, asynParamInt32, &p_AdcReg0x016c, IScalVal::create);
   createParam(AdcReg0x016dString, asynParamInt32, &p_AdcReg0x016d, IScalVal::create);
   createParam(AdcReg0x016eString, asynParamInt32, &p_AdcReg0x016e, IScalVal::create);
   createParam(AdcReg0x016fString, asynParamInt32, &p_AdcReg0x016f, IScalVal::create);
   createParam(AdcReg0x0170String, asynParamInt32, &p_AdcReg0x0170, IScalVal::create);
   createParam(AdcReg0x0171String, asynParamInt32, &p_AdcReg0x0171, IScalVal::create);
   createParam(AdcReg0x0172String, asynParamInt32, &p_AdcReg0x0172, IScalVal::create);
   createParam(AdcReg0x0173String, asynParamInt32, &p_AdcReg0x0173, IScalVal::create);
   createParam(AdcReg0x0174String, asynParamInt32, &p_AdcReg0x0174, IScalVal::create);
   createParam(AdcReg0x0175String, asynParamInt32, &p_AdcReg0x0175, IScalVal::create);
   createParam(AdcReg0x0176String, asynParamInt32, &p_AdcReg0x0176, IScalVal::create);
   createParam(AdcReg0x0177String, asynParamInt32, &p_AdcReg0x0177, IScalVal::create);
   createParam(AdcReg0x0178String, asynParamInt32, &p_AdcReg0x0178, IScalVal::create);
   createParam(AdcReg0x0179String, asynParamInt32, &p_AdcReg0x0179, IScalVal::create);
   createParam(AdcReg0x017aString, asynParamInt32, &p_AdcReg0x017a, IScalVal::create);
   createParam(AdcReg0x017bString, asynParamInt32, &p_AdcReg0x017b, IScalVal::create);
   createParam(AdcReg0x017cString, asynParamInt32, &p_AdcReg0x017c, IScalVal::create);

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
     printf("Childl nelms:%d\n", c->getNelms());
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


