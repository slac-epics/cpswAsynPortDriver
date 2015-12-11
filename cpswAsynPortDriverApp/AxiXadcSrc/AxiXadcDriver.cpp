#include "AxiXadcDriver.h"
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

static const char *driverName = "AxiXadcDriver";


AxiXadcDriver::AxiXadcDriver(const char *portName, Path p, int nelms) 
	: cpswAsynDriver(portName, p, nelms, 44)

{

    createParam(TemperatureString, asynParamInt32, &p_Temperature);
    createParam(VccIntString, asynParamInt32, &p_VccInt);
    createParam(VccAuxString, asynParamInt32, &p_VccAux);
    createParam(VinString, asynParamInt32, &p_Vin);
    createParam(VrefPString, asynParamInt32, &p_VrefP);
    createParam(VrefNString, asynParamInt32, &p_VrefN);
    createParam(VccBramString, asynParamInt32, &p_VccBram);
    createParam(SupplyOffsetAString, asynParamInt32, &p_SupplyOffsetA);
    createParam(AdcOffsetAString, asynParamInt32, &p_AdcOffsetA);
    createParam(AdcGainAString, asynParamInt32, &p_AdcGainA);
    createParam(VccpIntString, asynParamInt32, &p_VccpInt);
    createParam(VccpAuxString, asynParamInt32, &p_VccpAux);
    createParam(VccpDdrString, asynParamInt32, &p_VccpDdr);
    createParam(VinAux00String, asynParamInt32, &p_VinAux00);
    createParam(VinAux01String, asynParamInt32, &p_VinAux01);
    createParam(VinAux02String, asynParamInt32, &p_VinAux02);
    createParam(VinAux03String, asynParamInt32, &p_VinAux03);
    createParam(VinAux04String, asynParamInt32, &p_VinAux04);
    createParam(VinAux05String, asynParamInt32, &p_VinAux05);
    createParam(VinAux06String, asynParamInt32, &p_VinAux06);
    createParam(VinAux07String, asynParamInt32, &p_VinAux07);
    createParam(VinAux08String, asynParamInt32, &p_VinAux08);
    createParam(VinAux09String, asynParamInt32, &p_VinAux09);
    createParam(VinAux10String, asynParamInt32, &p_VinAux10);
    createParam(VinAux11String, asynParamInt32, &p_VinAux11);
    createParam(VinAux12String, asynParamInt32, &p_VinAux12);
    createParam(VinAux13String, asynParamInt32, &p_VinAux13);
    createParam(VinAux14String, asynParamInt32, &p_VinAux14);
    createParam(VinAux15String, asynParamInt32, &p_VinAux15);
    createParam(TemperatureMaxString, asynParamInt32, &p_TemperatureMax);
    createParam(VccIntMaxString, asynParamInt32, &p_VccIntMax);
    createParam(VccAuxMaxString, asynParamInt32, &p_VccAuxMax);
    createParam(VccBramMaxString, asynParamInt32, &p_VccBramMax);
    createParam(TemperatureMinString, asynParamInt32, &p_TemperatureMin);
    createParam(VccIntMinString, asynParamInt32, &p_VccIntMin);
    createParam(VccAuxMinString, asynParamInt32, &p_VccAuxMin);
    createParam(VccBramMinString, asynParamInt32, &p_VccBramMin);
    createParam(VccpIntMaxString, asynParamInt32, &p_VccpIntMax);
    createParam(VccpAuxMaxString, asynParamInt32, &p_VccpAuxMax);
    createParam(VccpDdrMaxString, asynParamInt32, &p_VccpDdrMax);
    createParam(VccpIntMinString, asynParamInt32, &p_VccpIntMin);
    createParam(VccpAuxMinString, asynParamInt32, &p_VccpAuxMin);
    createParam(VccpDdrMinString, asynParamInt32, &p_VccpDdrMin);
    createParam(FlagString, asynParamInt32, &p_Flag);
    createParam(VccpIntMaxString, asynParamInt32, &p_VccpIntMax);

    startPoller(1);
}

/* This class should poll some variables...*/
asynStatus AxiXadcDriver::poll()
{
   asynStatus status = asynSuccess;

   uint32_t u32;

   Path p = path_->findByName("AxiXadc/Temperature");
   IScalVal::create( p )->getVal(&u32,1);
   setIntegerParam(p_Temperature, (epicsInt32)u32);

   callParamCallbacks();

   return status;
}

extern "C" int AxiXadcCreate(const char *portName, const char *path)
{
  Path p = IrootDev::Instance()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();

  new AxiXadcDriver(portName, p, c->getNelms());
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AxiXadcCreateArg0 = {"Port name", iocshArgString};
static const iocshArg AxiXadcCreateArg1 = {"path", iocshArgString};
static const iocshArg * const AxiXadcCreateArgs[] = {&AxiXadcCreateArg0,
                                                           &AxiXadcCreateArg1};
static const iocshFuncDef AxiXadcCreateDef = {"AxiXadcCreate", 2, AxiXadcCreateArgs};
static void AxiXadcCreateCallFunc(const iocshArgBuf *args)
{
  AxiXadcCreate(args[0].sval, args[1].sval);
}

static void AxiXadcRegister(void)
{
  iocshRegister(&AxiXadcCreateDef, AxiXadcCreateCallFunc);
}

extern "C" {
epicsExportRegistrar(AxiXadcRegister);
}

