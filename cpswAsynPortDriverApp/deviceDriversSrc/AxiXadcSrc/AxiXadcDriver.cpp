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
                 :cpswAsynDriver(portName, p->findByName("AxiXadc"), nelms, NUM_AXIXADC_PARAMS)
{

/* Registers */
   createParam(TemperatureString, asynParamInt32, &p_Temperature, IScalVal::create);
   createParam(VccIntString, asynParamInt32, &p_VccInt, IScalVal::create);
   createParam(VccAuxString, asynParamInt32, &p_VccAux, IScalVal::create);
   createParam(VrefPString, asynParamInt32, &p_VrefP, IScalVal::create);
   createParam(VrefNString, asynParamInt32, &p_VrefN, IScalVal::create);
   createParam(VccBramString, asynParamInt32, &p_VccBram, IScalVal::create);
   createParam(SupplyOffsetAString, asynParamInt32, &p_SupplyOffsetA, IScalVal::create);
   createParam(AdcOffsetAString, asynParamInt32, &p_AdcOffsetA, IScalVal::create);
   createParam(AdcGainAString, asynParamInt32, &p_AdcGainA, IScalVal::create);
   createParam(VccpIntString, asynParamInt32, &p_VccpInt, IScalVal::create);
   createParam(VccpAuxString, asynParamInt32, &p_VccpAux, IScalVal::create);
   createParam(VccpDdrString, asynParamInt32, &p_VccpDdr, IScalVal::create);
   createParam(VinAux_0String, asynParamInt32, &p_VinAux_0, IScalVal::create);
   createParam(VinAux01String, asynParamInt32, &p_VinAux01, IScalVal::create);
   createParam(VinAux02String, asynParamInt32, &p_VinAux02, IScalVal::create);
   createParam(VinAux03String, asynParamInt32, &p_VinAux03, IScalVal::create);
   createParam(VinAux04String, asynParamInt32, &p_VinAux04, IScalVal::create);
   createParam(VinAux05String, asynParamInt32, &p_VinAux05, IScalVal::create);
   createParam(VinAux06String, asynParamInt32, &p_VinAux06, IScalVal::create);
   createParam(VinAux07String, asynParamInt32, &p_VinAux07, IScalVal::create);
   createParam(VinAux08String, asynParamInt32, &p_VinAux08, IScalVal::create);
   createParam(VinAux09String, asynParamInt32, &p_VinAux09, IScalVal::create);
   createParam(VinAux10String, asynParamInt32, &p_VinAux10, IScalVal::create);
   createParam(VinAux11String, asynParamInt32, &p_VinAux11, IScalVal::create);
   createParam(VinAux12String, asynParamInt32, &p_VinAux12, IScalVal::create);
   createParam(VinAux13String, asynParamInt32, &p_VinAux13, IScalVal::create);
   createParam(VinAux14String, asynParamInt32, &p_VinAux14, IScalVal::create);
   createParam(VinAux15String, asynParamInt32, &p_VinAux15, IScalVal::create);
   createParam(TemperatureMaxString, asynParamInt32, &p_TemperatureMax, IScalVal::create);
   createParam(VccIntMaxString, asynParamInt32, &p_VccIntMax, IScalVal::create);
   createParam(VccAuxMaxString, asynParamInt32, &p_VccAuxMax, IScalVal::create);
   createParam(VccBramMaxString, asynParamInt32, &p_VccBramMax, IScalVal::create);
   createParam(TemperatureMinString, asynParamInt32, &p_TemperatureMin, IScalVal::create);
   createParam(VccIntMinString, asynParamInt32, &p_VccIntMin, IScalVal::create);
   createParam(VccAuxMinString, asynParamInt32, &p_VccAuxMin, IScalVal::create);
   createParam(VccBramMinString, asynParamInt32, &p_VccBramMin, IScalVal::create);
   createParam(VccpIntMaxString, asynParamInt32, &p_VccpIntMax, IScalVal::create);
   createParam(VccpAuxMaxString, asynParamInt32, &p_VccpAuxMax, IScalVal::create);
   createParam(VccpDdrMaxString, asynParamInt32, &p_VccpDdrMax, IScalVal::create);
   createParam(VccpIntMinString, asynParamInt32, &p_VccpIntMin, IScalVal::create);
   createParam(VccpAuxMinString, asynParamInt32, &p_VccpAuxMin, IScalVal::create);
   createParam(VccpDdrMinString, asynParamInt32, &p_VccpDdrMin, IScalVal::create);
   createParam(FlagString, asynParamInt32, &p_Flag, IScalVal::create);
   createParam(Flag_JTGDString, asynParamInt32, &p_Flag_JTGD, IScalVal::create);
   createParam(Flag_JTGRString, asynParamInt32, &p_Flag_JTGR, IScalVal::create);
   createParam(Flag_REFString, asynParamInt32, &p_Flag_REF, IScalVal::create);
   createParam(Flag_VccpDdrString, asynParamInt32, &p_Flag_VccpDdr, IScalVal::create);
   createParam(Flag_VccpAuxString, asynParamInt32, &p_Flag_VccpAux, IScalVal::create);
   createParam(Flag_VccpIntString, asynParamInt32, &p_Flag_VccpInt, IScalVal::create);
   createParam(Flag_VccBramString, asynParamInt32, &p_Flag_VccBram, IScalVal::create);
   createParam(Flag_VccAuxString, asynParamInt32, &p_Flag_VccAux, IScalVal::create);
   createParam(Flag_VccIntString, asynParamInt32, &p_Flag_VccInt, IScalVal::create);
   createParam(Flag_TemperatureString, asynParamInt32, &p_Flag_Temperature, IScalVal::create);
}



extern "C" int AxiXadcCreate(const char *portName, const char *path)
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
  new AxiXadcDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AxiXadcCreateArg0 = {"Port name", iocshArgString};
static const iocshArg AxiXadcCreateArg1 = {"AxiXadc port name", iocshArgString};
static const iocshArg * const AxiXadcCreateArgs[] = {&AxiXadcCreateArg0,
                                                           &AxiXadcCreateArg1};
static const iocshFuncDef AxiXadcCreateDef = {"AxiXadcCreate", 2, AxiXadcCreateArgs};
static void AxiXadcCreateContollerCallFunc(const iocshArgBuf *args)
{
  AxiXadcCreate(args[0].sval, args[1].sval);
}

static void AxiXadcRegister(void)
{
  iocshRegister(&AxiXadcCreateDef, AxiXadcCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(AxiXadcRegister);
}


