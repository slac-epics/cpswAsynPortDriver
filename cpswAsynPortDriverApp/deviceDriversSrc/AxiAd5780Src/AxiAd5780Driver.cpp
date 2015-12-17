#include "AxiAd5780Driver.h"
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

static const char *driverName = "AxiAd5780Driver";


AxiAd5780Driver::AxiAd5780Driver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("AxiAd5780"), nelms, NUM_AXIAD5780_PARAMS)
{

/* Registers */
   createParam(dacRefreshRateString, asynParamInt32, &p_dacRefreshRate, IScalVal::create);
   createParam(dacDataString, asynParamInt32, &p_dacData, IScalVal::create);
   createParam(debugMuxString, asynParamInt32, &p_debugMux, IScalVal::create);
   createParam(debugDataString, asynParamInt32, &p_debugData, IScalVal::create);
   createParam(sdoDisableString, asynParamInt32, &p_sdoDisable, IScalVal::create);
   createParam(binaryOffsetString, asynParamInt32, &p_binaryOffset, IScalVal::create);
   createParam(dacTriStateString, asynParamInt32, &p_dacTriState, IScalVal::create);
   createParam(opGndString, asynParamInt32, &p_opGnd, IScalVal::create);
   createParam(rbufString, asynParamInt32, &p_rbuf, IScalVal::create);
   createParam(halfSckPeriodString, asynParamInt32, &p_halfSckPeriod, IScalVal::create);
   createParam(dacRstString, asynParamInt32, &p_dacRst, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CdacRstString, asynParamInt32, &p_C_dacRst);
}

asynStatus AxiAd5780Driver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_dacRst ) {
        dacRst();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus AxiAd5780Driver::dacRst()
{
   asynStatus status = asynSuccess;
/* Fill in command logic here */
   printf("Command dacRst not yet implemented!\n");

   return status;
}

extern "C" int AxiAd5780Create(const char *portName, const char *path)
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
  new AxiAd5780Driver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AxiAd5780CreateArg0 = {"Port name", iocshArgString};
static const iocshArg AxiAd5780CreateArg1 = {"AxiAd5780 port name", iocshArgString};
static const iocshArg * const AxiAd5780CreateArgs[] = {&AxiAd5780CreateArg0,
                                                           &AxiAd5780CreateArg1};
static const iocshFuncDef AxiAd5780CreateDef = {"AxiAd5780Create", 2, AxiAd5780CreateArgs};
static void AxiAd5780CreateContollerCallFunc(const iocshArgBuf *args)
{
  AxiAd5780Create(args[0].sval, args[1].sval);
}

static void AxiAd5780Register(void)
{
  iocshRegister(&AxiAd5780CreateDef, AxiAd5780CreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(AxiAd5780Register);
}


