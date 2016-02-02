#include "Pgp2bAxiDriver.h"
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

static const char *driverName = "Pgp2bAxiDriver";


Pgp2bAxiDriver::Pgp2bAxiDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName(portName), nelms, NUM_PGP2BAXI_PARAMS)
{

/* Registers */
   createParam(CountResetString, asynParamInt32, &p_CountReset, IScalVal::create);
   createParam(ResetRxString, asynParamInt32, &p_ResetRx, IScalVal::create);
   createParam(FlushString, asynParamInt32, &p_Flush, IScalVal::create);
   createParam(LoopbackString, asynParamInt32, &p_Loopback, IScalVal::create);
   createParam(LocDataString, asynParamInt32, &p_LocData, IScalVal::create);
   createParam(AutoStatusString, asynParamInt32, &p_AutoStatus, IScalVal::create);
   createParam(StatusString, asynParamInt32, &p_Status, IScalVal::create);
   createParam(RxPhyReadyString, asynParamInt32, &p_RxPhyReady, IScalVal::create);
   createParam(TxPhyReadyString, asynParamInt32, &p_TxPhyReady, IScalVal::create);
   createParam(RxLocalLinkReadyString, asynParamInt32, &p_RxLocalLinkReady, IScalVal::create);
   createParam(RxRemLinkReadyString, asynParamInt32, &p_RxRemLinkReady, IScalVal::create);
   createParam(TxLinkReadyString, asynParamInt32, &p_TxLinkReady, IScalVal::create);
   createParam(RxLinkPolarityString, asynParamInt32, &p_RxLinkPolarity, IScalVal::create);
   createParam(RxRemPauseString, asynParamInt32, &p_RxRemPause, IScalVal::create);
   createParam(TxLocPauseString, asynParamInt32, &p_TxLocPause, IScalVal::create);
   createParam(RxRemOverflowString, asynParamInt32, &p_RxRemOverflow, IScalVal::create);
   createParam(TxLocOverflowString, asynParamInt32, &p_TxLocOverflow, IScalVal::create);
   createParam(RxRemLinkDataString, asynParamInt32, &p_RxRemLinkData, IScalVal::create);
   createParam(RxCellErrorCountString, asynParamInt32, &p_RxCellErrorCount, IScalVal::create);
   createParam(RxLinkDownCountString, asynParamInt32, &p_RxLinkDownCount, IScalVal::create);
   createParam(RxLinkErrorCountString, asynParamInt32, &p_RxLinkErrorCount, IScalVal::create);
   createParam(RxRemOverflow0CountString, asynParamInt32, &p_RxRemOverflow0Count, IScalVal::create);
   createParam(RxRemOverflow1CountString, asynParamInt32, &p_RxRemOverflow1Count, IScalVal::create);
   createParam(RxRemOverflow2CountString, asynParamInt32, &p_RxRemOverflow2Count, IScalVal::create);
   createParam(RxRemOverflow3CountString, asynParamInt32, &p_RxRemOverflow3Count, IScalVal::create);
   createParam(RxFrameErrorCountString, asynParamInt32, &p_RxFrameErrorCount, IScalVal::create);
   createParam(RxFrameCountString, asynParamInt32, &p_RxFrameCount, IScalVal::create);
   createParam(TxLocOverflow0CountString, asynParamInt32, &p_TxLocOverflow0Count, IScalVal::create);
   createParam(TxLocOverflow1CountString, asynParamInt32, &p_TxLocOverflow1Count, IScalVal::create);
   createParam(TxLocOverflow2CountString, asynParamInt32, &p_TxLocOverflow2Count, IScalVal::create);
   createParam(TxLocOverflow3CountString, asynParamInt32, &p_TxLocOverflow3Count, IScalVal::create);
   createParam(TxFrameErrorCountString, asynParamInt32, &p_TxFrameErrorCount, IScalVal::create);
   createParam(TxFrameCountString, asynParamInt32, &p_TxFrameCount, IScalVal::create);
   createParam(RxClkFreqString, asynParamInt32, &p_RxClkFreq, IScalVal::create);
   createParam(TxClkFreqString, asynParamInt32, &p_TxClkFreq, IScalVal::create);
   createParam(TxOpCodeStatusString, asynParamInt32, &p_TxOpCodeStatus, IScalVal::create);
   createParam(LastTxOpCodeString, asynParamInt32, &p_LastTxOpCode, IScalVal::create);
   createParam(RxOpCodeStatusString, asynParamInt32, &p_RxOpCodeStatus, IScalVal::create);
   createParam(LastRxOpCodeString, asynParamInt32, &p_LastRxOpCode, IScalVal::create);
   createParam(TxOpCodeCountString, asynParamInt32, &p_TxOpCodeCount, IScalVal::create);
   createParam(RxOpCodeCountString, asynParamInt32, &p_RxOpCodeCount, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CResetRxString, asynParamInt32, &p_C_ResetRx);
   asynPortDriver::createParam(CFlushString, asynParamInt32, &p_C_Flush);
}

asynStatus Pgp2bAxiDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_ResetRx ) {
        status = ResetRx();
    }
    else if( function == p_C_Flush ) {
        status = Flush();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus Pgp2bAxiDriver::ResetRx()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 1;

   try {
     ScalVals[p_ResetRx]->setVal( &u32, 1 );
     u32 = 0; 
     ScalVals[p_ResetRx]->setVal( &u32, 1 );

   } catch (CPSWError &e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
     status = asynError;
   }

   return status;
}
asynStatus Pgp2bAxiDriver::Flush()
{
   asynStatus status = asynSuccess;
/* Fill in command logic here */
   printf("Command Flush not yet implemented!\n");

   return status;
}

extern "C" int Pgp2bAxiCreate(const char *portName, const char *path)
{
  
  Path p = IDev::getRootDev()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  new Pgp2bAxiDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg Pgp2bAxiCreateArg0 = {"Port name", iocshArgString};
static const iocshArg Pgp2bAxiCreateArg1 = {"Pgp2bAxi port name", iocshArgString};
static const iocshArg * const Pgp2bAxiCreateArgs[] = {&Pgp2bAxiCreateArg0,
                                                           &Pgp2bAxiCreateArg1};
static const iocshFuncDef Pgp2bAxiCreateDef = {"Pgp2bAxiCreate", 2, Pgp2bAxiCreateArgs};
static void Pgp2bAxiCreateContollerCallFunc(const iocshArgBuf *args)
{
  Pgp2bAxiCreate(args[0].sval, args[1].sval);
}

static void Pgp2bAxiRegister(void)
{
  iocshRegister(&Pgp2bAxiCreateDef, Pgp2bAxiCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(Pgp2bAxiRegister);
}


