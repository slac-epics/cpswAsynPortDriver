#include "JesdRxDaqDriver.h"
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

static const char *driverName = "JesdRxDaqDriver";


JesdRxDaqDriver::JesdRxDaqDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName(portName), nelms, NUM_JESDRXDAQ_PARAMS)
{

/* Registers */
   createParam(SwDaqTriggerString, asynParamInt32, &p_SwDaqTrigger, IScalVal::create);
   createParam(SwDaqTrigger0String, asynParamInt32, &p_SwDaqTrigger0, IScalVal::create);
   createParam(SampleDecimationString, asynParamInt32, &p_SampleDecimation, IScalVal::create);
   createParam(DaqBufferSizeString, asynParamInt32, &p_DaqBufferSize, IScalVal::create);
   createParam(S1ChannelSelectString, asynParamInt32, &p_S1ChannelSelect, IScalVal::create);
   createParam(S2ChannelSelectString, asynParamInt32, &p_S2ChannelSelect, IScalVal::create);
   createParam(StatusStream0String, asynParamInt32, &p_StatusStream0, IScalVal::create);
   createParam(Pause0String, asynParamInt32, &p_Pause0, IScalVal::create);
   createParam(Idle0String, asynParamInt32, &p_Idle0, IScalVal::create);
   createParam(Overflow0String, asynParamInt32, &p_Overflow0, IScalVal::create);
   createParam(Error0String, asynParamInt32, &p_Error0, IScalVal::create);
   createParam(JESDValid0String, asynParamInt32, &p_JESDValid0, IScalVal::create);
   createParam(Enable0String, asynParamInt32, &p_Enable0, IScalVal::create);
   createParam(PacketCnt0String, asynParamInt32, &p_PacketCnt0, IScalVal::create);
   createParam(StatusStream1String, asynParamInt32, &p_StatusStream1, IScalVal::create);
   createParam(Pause1String, asynParamInt32, &p_Pause1, IScalVal::create);
   createParam(Idle1String, asynParamInt32, &p_Idle1, IScalVal::create);
   createParam(Overflow1String, asynParamInt32, &p_Overflow1, IScalVal::create);
   createParam(Error1String, asynParamInt32, &p_Error1, IScalVal::create);
   createParam(JESDValid1String, asynParamInt32, &p_JESDValid1, IScalVal::create);
   createParam(Enable1String, asynParamInt32, &p_Enable1, IScalVal::create);
   createParam(PacketCnt1String, asynParamInt32, &p_PacketCnt1, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CTriggerDAQString, asynParamInt32, &p_C_TriggerDAQ);
}

asynStatus JesdRxDaqDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_TriggerDAQ ) {
        status = TriggerDAQ();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus JesdRxDaqDriver::TriggerDAQ()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_SwDaqTrigger0]->setVal( &u32, 1 );
     u32 = 0;
     ScalVals[p_SwDaqTrigger0]->setVal( &u32, 1 );
   } catch (CPSWError e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
     status = asynError;
   }

   return status;
}

extern "C" int JesdRxDaqCreate(const char *portName, const char *path)
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
  new JesdRxDaqDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg JesdRxDaqCreateArg0 = {"Port name", iocshArgString};
static const iocshArg JesdRxDaqCreateArg1 = {"JesdRxDaq port name", iocshArgString};
static const iocshArg * const JesdRxDaqCreateArgs[] = {&JesdRxDaqCreateArg0,
                                                           &JesdRxDaqCreateArg1};
static const iocshFuncDef JesdRxDaqCreateDef = {"JesdRxDaqCreate", 2, JesdRxDaqCreateArgs};
static void JesdRxDaqCreateContollerCallFunc(const iocshArgBuf *args)
{
  JesdRxDaqCreate(args[0].sval, args[1].sval);
}

static void JesdRxDaqRegister(void)
{
  iocshRegister(&JesdRxDaqCreateDef, JesdRxDaqCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(JesdRxDaqRegister);
}


