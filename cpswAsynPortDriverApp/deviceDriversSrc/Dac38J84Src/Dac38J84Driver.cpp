#include "Dac38J84Driver.h"
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

static const char *driverName = "Dac38J84Driver";


Dac38J84Driver::Dac38J84Driver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p, nelms, NUM_DAC38J84_PARAMS)
{

/* Registers */
   createParam(IntStatusString, asynParamInt32, &p_IntStatus, IScalVal::create);
   createParam(LaneBufferDelayString, asynParamInt32, &p_LaneBufferDelay, IScalVal::create);
   createParam(TemperatureString, asynParamInt32, &p_Temperature, IScalVal::create);
   createParam(L1ErrCntString, asynParamInt32, &p_L1ErrCnt, IScalVal::create);
   createParam(L2ErrCntString, asynParamInt32, &p_L2ErrCnt, IScalVal::create);
   createParam(L1SERDES_alarmString, asynParamInt32, &p_L1SERDES_alarm, IScalVal::create);
   createParam(L1ReadFifoEmptyString, asynParamInt32, &p_L1ReadFifoEmpty, IScalVal::create);
   createParam(L1ReadFifoUnderflowString, asynParamInt32, &p_L1ReadFifoUnderflow, IScalVal::create);
   createParam(L1ReadFifoFullString, asynParamInt32, &p_L1ReadFifoFull, IScalVal::create);
   createParam(L1ReadFifoOverflowString, asynParamInt32, &p_L1ReadFifoOverflow, IScalVal::create);
   createParam(L1DispErrString, asynParamInt32, &p_L1DispErr, IScalVal::create);
   createParam(L1NotitableErrString, asynParamInt32, &p_L1NotitableErr, IScalVal::create);
   createParam(L1CodeSyncErrString, asynParamInt32, &p_L1CodeSyncErr, IScalVal::create);
   createParam(L1FirstDataMatchErrString, asynParamInt32, &p_L1FirstDataMatchErr, IScalVal::create);
   createParam(L1ElasticBuffOverflowString, asynParamInt32, &p_L1ElasticBuffOverflow, IScalVal::create);
   createParam(L1LinkConfigErrString, asynParamInt32, &p_L1LinkConfigErr, IScalVal::create);
   createParam(L1FrameAlignErrString, asynParamInt32, &p_L1FrameAlignErr, IScalVal::create);
   createParam(L1MultiFrameAlignErrString, asynParamInt32, &p_L1MultiFrameAlignErr, IScalVal::create);
   createParam(L2SERDES_alarmString, asynParamInt32, &p_L2SERDES_alarm, IScalVal::create);
   createParam(L2ReadFifoEmptyString, asynParamInt32, &p_L2ReadFifoEmpty, IScalVal::create);
   createParam(L2ReadFifoUnderflowString, asynParamInt32, &p_L2ReadFifoUnderflow, IScalVal::create);
   createParam(L2ReadFifoFullString, asynParamInt32, &p_L2ReadFifoFull, IScalVal::create);
   createParam(L2ReadFifoOverflowString, asynParamInt32, &p_L2ReadFifoOverflow, IScalVal::create);
   createParam(L2DispErrString, asynParamInt32, &p_L2DispErr, IScalVal::create);
   createParam(L2NotitableErrString, asynParamInt32, &p_L2NotitableErr, IScalVal::create);
   createParam(L2CodeSyncErrString, asynParamInt32, &p_L2CodeSyncErr, IScalVal::create);
   createParam(L2FirstDataMatchErrString, asynParamInt32, &p_L2FirstDataMatchErr, IScalVal::create);
   createParam(L2ElasticBuffOverflowString, asynParamInt32, &p_L2ElasticBuffOverflow, IScalVal::create);
   createParam(L2LinkConfigErrString, asynParamInt32, &p_L2LinkConfigErr, IScalVal::create);
   createParam(L2FrameAlignErrString, asynParamInt32, &p_L2FrameAlignErr, IScalVal::create);
   createParam(L2MultiFrameAlignErrString, asynParamInt32, &p_L2MultiFrameAlignErr, IScalVal::create);
   createParam(L3SERDES_alarmString, asynParamInt32, &p_L3SERDES_alarm, IScalVal::create);
   createParam(L4SERDES_alarmString, asynParamInt32, &p_L4SERDES_alarm, IScalVal::create);
   createParam(L5SERDES_alarmString, asynParamInt32, &p_L5SERDES_alarm, IScalVal::create);
   createParam(L6SERDES_alarmString, asynParamInt32, &p_L6SERDES_alarm, IScalVal::create);
   createParam(L7SERDES_alarmString, asynParamInt32, &p_L7SERDES_alarm, IScalVal::create);
   createParam(L8SERDES_alarmString, asynParamInt32, &p_L8SERDES_alarm, IScalVal::create);
   createParam(Sysref_alarmString, asynParamInt32, &p_Sysref_alarm, IScalVal::create);
   createParam(Serdes1pllAlarmString, asynParamInt32, &p_Serdes1pllAlarm, IScalVal::create);
   createParam(Serdes0pllAlarmString, asynParamInt32, &p_Serdes0pllAlarm, IScalVal::create);
   createParam(SysRefAlarmsString, asynParamInt32, &p_SysRefAlarms, IScalVal::create);
   createParam(Lane_alarmString, asynParamInt32, &p_Lane_alarm, IScalVal::create);
   createParam(Lane1LossString, asynParamInt32, &p_Lane1Loss, IScalVal::create);
   createParam(Lane2LossString, asynParamInt32, &p_Lane2Loss, IScalVal::create);
   createParam(Lane1AlarmString, asynParamInt32, &p_Lane1Alarm, IScalVal::create);
   createParam(Lane2AlarmString, asynParamInt32, &p_Lane2Alarm, IScalVal::create);
   createParam(IDsString, asynParamInt32, &p_IDs, IScalVal::create);
   createParam(DacReg0x0000String, asynParamInt32, &p_DacReg0x0000, IScalVal::create);
   createParam(DacReg0x0001String, asynParamInt32, &p_DacReg0x0001, IScalVal::create);
   createParam(DacReg0x0002String, asynParamInt32, &p_DacReg0x0002, IScalVal::create);
   createParam(DacReg0x0003String, asynParamInt32, &p_DacReg0x0003, IScalVal::create);
   createParam(DacReg0x0004String, asynParamInt32, &p_DacReg0x0004, IScalVal::create);
   createParam(DacReg0x0005String, asynParamInt32, &p_DacReg0x0005, IScalVal::create);
   createParam(DacReg0x0006String, asynParamInt32, &p_DacReg0x0006, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CClearDACAlarmsString, asynParamInt32, &p_C_ClearDACAlarms);
   asynPortDriver::createParam(CInitDAC_JESDString, asynParamInt32, &p_C_InitDAC_JESD);
}

asynStatus Dac38J84Driver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_ClearDACAlarms ) {
        status = ClearDACAlarms();
    }
    else if( function == p_C_InitDAC_JESD ) {
        status = InitDAC_JESD();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus Dac38J84Driver::ClearDACAlarms()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 0;

   try {
     ScalVals[p_L1SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L2SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L3SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L4SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L5SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L6SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L7SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_L8SERDES_alarm]->setVal( &u32, 1 );
     ScalVals[p_Sysref_alarm]->setVal( &u32, 1 );
   } catch (CPSWError &e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
     status = asynError;
   }

   return status;
}
asynStatus Dac38J84Driver::InitDAC_JESD()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 0x0;

   try {
     ScalVals[p_DacReg0x0003]->setVal( &u32, 1 );
     u32 = 0x1E;
     ScalVals[p_DacReg0x0004]->setVal( &u32, 1 );
     u32 = 0x1;
     ScalVals[p_DacReg0x0004]->setVal( &u32, 1 );
     u32 = 0x1;
     ScalVals[p_DacReg0x0003]->setVal( &u32, 1 );
   } catch (CPSWError &e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
     status = asynError;
   }

   return status;
}

extern "C" int Dac38J84Create(const char *portName, const char *path)
{
  
  Path p = IPath::create();
  try {  
    p = p->findByName(path);
  } catch( CPSWError &e ) {
    printf("CPSWError: %s\n", e.getInfo().c_str());     
    return -1;
  }
  new Dac38J84Driver(portName, p, 0);
  return 1;
}


/** Code for iocsh registration */
static const iocshArg Dac38J84CreateArg0 = {"Port name", iocshArgString};
static const iocshArg Dac38J84CreateArg1 = {"Dac38J84 port name", iocshArgString};
static const iocshArg * const Dac38J84CreateArgs[] = {&Dac38J84CreateArg0,
                                                           &Dac38J84CreateArg1};
static const iocshFuncDef Dac38J84CreateDef = {"Dac38J84Create", 2, Dac38J84CreateArgs};
static void Dac38J84CreateContollerCallFunc(const iocshArgBuf *args)
{
  Dac38J84Create(args[0].sval, args[1].sval);
}

static void Dac38J84Register(void)
{
  iocshRegister(&Dac38J84CreateDef, Dac38J84CreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(Dac38J84Register);
}


