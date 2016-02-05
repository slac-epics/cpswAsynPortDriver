#include "RingBufferDriver.h"
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

static const char *driverName = "RingBufferDriver";


RingBufferDriver::RingBufferDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p, nelms, NUM_RINGBUFFER_PARAMS)
{

/* Registers */
   createParam(WaveformSizeString, asynParamInt32, &p_WaveformSize, IScalVal::create);
   createParam(RAM_ADDR_WIDTH_GString, asynParamInt32, &p_RAM_ADDR_WIDTH_G, IScalVal::create);
   createParam(ExtdataLogClrString, asynParamInt32, &p_ExtdataLogClr, IScalVal::create);
   createParam(ExtDataLogEnString, asynParamInt32, &p_ExtDataLogEn, IScalVal::create);
   createParam(IntdataLogClrString, asynParamInt32, &p_IntdataLogClr, IScalVal::create);
   createParam(IntDataLogEnString, asynParamInt32, &p_IntDataLogEn, IScalVal::create);
   createParam(Reg0x0000String, asynParamInt32, &p_Reg0x0000, IScalVal::create);
   createParam(RingBufferString, asynParamInt32Array, &p_RingBuffer, IScalVal::create);
}



extern "C" int RingBufferCreate(const char *portName, const char *path)
{
  
  Path p = IPath::create();
  try {  
    p = p->findByName(path);
  } catch( CPSWError &e ) {
    printf("CPSWError: %s\n", e.getInfo().c_str());     
    return -1;
  }
  new RingBufferDriver(portName, p, 0);
  return 1;
}


/** Code for iocsh registration */
static const iocshArg RingBufferCreateArg0 = {"Port name", iocshArgString};
static const iocshArg RingBufferCreateArg1 = {"RingBuffer port name", iocshArgString};
static const iocshArg * const RingBufferCreateArgs[] = {&RingBufferCreateArg0,
                                                           &RingBufferCreateArg1};
static const iocshFuncDef RingBufferCreateDef = {"RingBufferCreate", 2, RingBufferCreateArgs};
static void RingBufferCreateContollerCallFunc(const iocshArgBuf *args)
{
  RingBufferCreate(args[0].sval, args[1].sval);
}

static void RingBufferRegister(void)
{
  iocshRegister(&RingBufferCreateDef, RingBufferCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(RingBufferRegister);
}


