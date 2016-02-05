#include "TenGigEthRegDriver.h"
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

static const char *driverName = "TenGigEthRegDriver";


TenGigEthRegDriver::TenGigEthRegDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p, nelms, NUM_TENGIGETHREG_PARAMS)
{

/* Registers */
   createParam(PhyReadyCntString, asynParamInt32, &p_PhyReadyCnt, IScalVal::create);
   createParam(RxPauseCntString, asynParamInt32, &p_RxPauseCnt, IScalVal::create);
   createParam(TxPauseCntString, asynParamInt32, &p_TxPauseCnt, IScalVal::create);
   createParam(RxCountEnCntString, asynParamInt32, &p_RxCountEnCnt, IScalVal::create);
   createParam(RxOverFlowCntString, asynParamInt32, &p_RxOverFlowCnt, IScalVal::create);
   createParam(RxCrcErrorCntString, asynParamInt32, &p_RxCrcErrorCnt, IScalVal::create);
   createParam(TxCountEnCntString, asynParamInt32, &p_TxCountEnCnt, IScalVal::create);
   createParam(TxUnderRunCntString, asynParamInt32, &p_TxUnderRunCnt, IScalVal::create);
   createParam(TxNotReadyCntString, asynParamInt32, &p_TxNotReadyCnt, IScalVal::create);
   createParam(TxDisableString, asynParamInt32, &p_TxDisable, IScalVal::create);
   createParam(SigDetString, asynParamInt32, &p_SigDet, IScalVal::create);
   createParam(TxFaultString, asynParamInt32, &p_TxFault, IScalVal::create);
   createParam(GtTxRstString, asynParamInt32, &p_GtTxRst, IScalVal::create);
   createParam(GtRxRstString, asynParamInt32, &p_GtRxRst, IScalVal::create);
   createParam(RstCntDoneString, asynParamInt32, &p_RstCntDone, IScalVal::create);
   createParam(QplllockString, asynParamInt32, &p_Qplllock, IScalVal::create);
   createParam(TxRstdoneString, asynParamInt32, &p_TxRstdone, IScalVal::create);
   createParam(RxRstdoneString, asynParamInt32, &p_RxRstdone, IScalVal::create);
   createParam(TxUsrRdyString, asynParamInt32, &p_TxUsrRdy, IScalVal::create);
   createParam(StatusString, asynParamInt32, &p_Status, IScalVal::create);
   createParam(FLAG_PhyReadyString, asynParamInt32, &p_FLAG_PhyReady, IScalVal::create);
   createParam(FLAG_RxPauseString, asynParamInt32, &p_FLAG_RxPause, IScalVal::create);
   createParam(FLAG_TxPauseString, asynParamInt32, &p_FLAG_TxPause, IScalVal::create);
   createParam(FLAG_RxCountEnString, asynParamInt32, &p_FLAG_RxCountEn, IScalVal::create);
   createParam(FLAG_RxOverFlowString, asynParamInt32, &p_FLAG_RxOverFlow, IScalVal::create);
   createParam(FLAG_RxCrcErrorString, asynParamInt32, &p_FLAG_RxCrcError, IScalVal::create);
   createParam(FLAG_TxCountEnString, asynParamInt32, &p_FLAG_TxCountEn, IScalVal::create);
   createParam(FLAG_TxUnderRunString, asynParamInt32, &p_FLAG_TxUnderRun, IScalVal::create);
   createParam(FLAG_TxNotReadyString, asynParamInt32, &p_FLAG_TxNotReady, IScalVal::create);
   createParam(FLAG_TxDisableString, asynParamInt32, &p_FLAG_TxDisable, IScalVal::create);
   createParam(FLAG_SigDetString, asynParamInt32, &p_FLAG_SigDet, IScalVal::create);
   createParam(FLAG_TxFaultString, asynParamInt32, &p_FLAG_TxFault, IScalVal::create);
   createParam(FLAG_GtTxRstString, asynParamInt32, &p_FLAG_GtTxRst, IScalVal::create);
   createParam(FLAG_GtRxRstString, asynParamInt32, &p_FLAG_GtRxRst, IScalVal::create);
   createParam(FLAG_RstCntDoneString, asynParamInt32, &p_FLAG_RstCntDone, IScalVal::create);
   createParam(FLAG_QplllockString, asynParamInt32, &p_FLAG_Qplllock, IScalVal::create);
   createParam(FLAG_TxRstdoneString, asynParamInt32, &p_FLAG_TxRstdone, IScalVal::create);
   createParam(FLAG_RxRstdoneString, asynParamInt32, &p_FLAG_RxRstdone, IScalVal::create);
   createParam(FLAG_TxUsrRdyString, asynParamInt32, &p_FLAG_TxUsrRdy, IScalVal::create);
}



extern "C" int TenGigEthRegCreate(const char *portName, const char *path)
{
  
  Path p = IPath::create();
  try {  
    p = p->findByName(path);
  } catch( CPSWError &e ) {
    printf("CPSWError: %s\n", e.getInfo().c_str());     
    return -1;
  }
  new TenGigEthRegDriver(portName, p, 0);
  return 1;
}


/** Code for iocsh registration */
static const iocshArg TenGigEthRegCreateArg0 = {"Port name", iocshArgString};
static const iocshArg TenGigEthRegCreateArg1 = {"TenGigEthReg port name", iocshArgString};
static const iocshArg * const TenGigEthRegCreateArgs[] = {&TenGigEthRegCreateArg0,
                                                           &TenGigEthRegCreateArg1};
static const iocshFuncDef TenGigEthRegCreateDef = {"TenGigEthRegCreate", 2, TenGigEthRegCreateArgs};
static void TenGigEthRegCreateContollerCallFunc(const iocshArgBuf *args)
{
  TenGigEthRegCreate(args[0].sval, args[1].sval);
}

static void TenGigEthRegRegister(void)
{
  iocshRegister(&TenGigEthRegCreateDef, TenGigEthRegCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(TenGigEthRegRegister);
}


