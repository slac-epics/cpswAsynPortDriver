#include "AxiVersionDriver.h"
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

static const char *driverName = "AxiVersionDriver";


AxiVersionDriver::AxiVersionDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName(portName), nelms, NUM_AXIVERSION_PARAMS)
{

/* Registers */
   createParam(FpgaVersionString, asynParamInt32, &p_FpgaVersion, IScalVal::create);
   createParam(ScratchPadString, asynParamInt32, &p_ScratchPad, IScalVal::create);
   createParam(DeviceDnaHighString, asynParamInt32, &p_DeviceDnaHigh, IScalVal::create);
   createParam(DeviceDnaLowString, asynParamInt32, &p_DeviceDnaLow, IScalVal::create);
   createParam(FdSerialHighString, asynParamInt32, &p_FdSerialHigh, IScalVal::create);
   createParam(FdSerialLowString, asynParamInt32, &p_FdSerialLow, IScalVal::create);
   createParam(MasterResetString, asynParamInt32, &p_MasterReset, IScalVal::create);
   createParam(FpgaReloadString, asynParamInt32, &p_FpgaReload, IScalVal::create);
   createParam(FpgaReloadAddressString, asynParamInt32, &p_FpgaReloadAddress, IScalVal::create);
   createParam(CounterString, asynParamInt32, &p_Counter, IScalVal::create);
   createParam(FpgaReloadHaltString, asynParamInt32, &p_FpgaReloadHalt, IScalVal::create);
   createParam(UserConstantsString, asynParamInt32Array, &p_UserConstants, IScalVal::create);
   createParam(BuildStampString, asynParamOctet, &p_BuildStamp, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CMasterResetString, asynParamInt32, &p_C_MasterReset);
   asynPortDriver::createParam(CFpgaReloadString, asynParamInt32, &p_C_FpgaReload);
   asynPortDriver::createParam(CCounterResetString, asynParamInt32, &p_C_CounterReset);
}

asynStatus AxiVersionDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_MasterReset ) {
        MasterReset();
    }
    else if( function == p_C_FpgaReload ) {
        FpgaReload();
    }
    else if( function == p_C_CounterReset ) {
        CounterReset();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus AxiVersionDriver::MasterReset()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_MasterReset]->setVal( &u32, 1 );
   } catch (CPSWError &e) {
     status = asynError;
   }

   return status;
}
asynStatus AxiVersionDriver::FpgaReload()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_FpgaReload]->setVal( &u32, 1 );
   } catch (CPSWError &e) {
     status = asynError;
   }

   return status;
}
asynStatus AxiVersionDriver::CounterReset()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 0;

   try {
     ScalVals[p_Counter]->setVal( &u32, 1 );
   } catch (CPSWError &e) {
     status = asynError;
   }

   return status;
}

extern "C" int AxiVersionCreate(const char *portName, const char *path)
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
  new AxiVersionDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AxiVersionCreateArg0 = {"Port name", iocshArgString};
static const iocshArg AxiVersionCreateArg1 = {"AxiVersion port name", iocshArgString};
static const iocshArg * const AxiVersionCreateArgs[] = {&AxiVersionCreateArg0,
                                                           &AxiVersionCreateArg1};
static const iocshFuncDef AxiVersionCreateDef = {"AxiVersionCreate", 2, AxiVersionCreateArgs};
static void AxiVersionCreateContollerCallFunc(const iocshArgBuf *args)
{
  AxiVersionCreate(args[0].sval, args[1].sval);
}

static void AxiVersionRegister(void)
{
  iocshRegister(&AxiVersionCreateDef, AxiVersionCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(AxiVersionRegister);
}


