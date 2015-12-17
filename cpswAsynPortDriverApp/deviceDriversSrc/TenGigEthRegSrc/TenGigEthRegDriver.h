#ifndef TENGIGETHREG_DRIVER_H
#define TENGIGETHREG_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define PhyReadyCntString "PhyReadyCnt"
#define RxPauseCntString "RxPauseCnt"
#define TxPauseCntString "TxPauseCnt"
#define RxCountEnCntString "RxCountEnCnt"
#define RxOverFlowCntString "RxOverFlowCnt"
#define RxCrcErrorCntString "RxCrcErrorCnt"
#define TxCountEnCntString "TxCountEnCnt"
#define TxUnderRunCntString "TxUnderRunCnt"
#define TxNotReadyCntString "TxNotReadyCnt"
#define TxDisableString "TxDisable"
#define SigDetString "SigDet"
#define TxFaultString "TxFault"
#define GtTxRstString "GtTxRst"
#define GtRxRstString "GtRxRst"
#define RstCntDoneString "RstCntDone"
#define QplllockString "Qplllock"
#define TxRstdoneString "TxRstdone"
#define RxRstdoneString "RxRstdone"
#define TxUsrRdyString "TxUsrRdy"
#define StatusString "Status"
#define FLAG_PhyReadyString "FLAG_PhyReady"
#define FLAG_RxPauseString "FLAG_RxPause"
#define FLAG_TxPauseString "FLAG_TxPause"
#define FLAG_RxCountEnString "FLAG_RxCountEn"
#define FLAG_RxOverFlowString "FLAG_RxOverFlow"
#define FLAG_RxCrcErrorString "FLAG_RxCrcError"
#define FLAG_TxCountEnString "FLAG_TxCountEn"
#define FLAG_TxUnderRunString "FLAG_TxUnderRun"
#define FLAG_TxNotReadyString "FLAG_TxNotReady"
#define FLAG_TxDisableString "FLAG_TxDisable"
#define FLAG_SigDetString "FLAG_SigDet"
#define FLAG_TxFaultString "FLAG_TxFault"
#define FLAG_GtTxRstString "FLAG_GtTxRst"
#define FLAG_GtRxRstString "FLAG_GtRxRst"
#define FLAG_RstCntDoneString "FLAG_RstCntDone"
#define FLAG_QplllockString "FLAG_Qplllock"
#define FLAG_TxRstdoneString "FLAG_TxRstdone"
#define FLAG_RxRstdoneString "FLAG_RxRstdone"
#define FLAG_TxUsrRdyString "FLAG_TxUsrRdy"

/* Commands */


 /* This class implements the AxiVersion driver. */
class TenGigEthRegDriver : public cpswAsynDriver {
public:
    TenGigEthRegDriver(const char *portName, Path p, int nelms);



protected:
/* Registers */
    int p_PhyReadyCnt;
    #define FIRST_TENGIGETHREG_PARAM p_PhyReadyCnt
    int p_RxPauseCnt;
    int p_TxPauseCnt;
    int p_RxCountEnCnt;
    int p_RxOverFlowCnt;
    int p_RxCrcErrorCnt;
    int p_TxCountEnCnt;
    int p_TxUnderRunCnt;
    int p_TxNotReadyCnt;
    int p_TxDisable;
    int p_SigDet;
    int p_TxFault;
    int p_GtTxRst;
    int p_GtRxRst;
    int p_RstCntDone;
    int p_Qplllock;
    int p_TxRstdone;
    int p_RxRstdone;
    int p_TxUsrRdy;
    int p_Status;
    int p_FLAG_PhyReady;
    int p_FLAG_RxPause;
    int p_FLAG_TxPause;
    int p_FLAG_RxCountEn;
    int p_FLAG_RxOverFlow;
    int p_FLAG_RxCrcError;
    int p_FLAG_TxCountEn;
    int p_FLAG_TxUnderRun;
    int p_FLAG_TxNotReady;
    int p_FLAG_TxDisable;
    int p_FLAG_SigDet;
    int p_FLAG_TxFault;
    int p_FLAG_GtTxRst;
    int p_FLAG_GtRxRst;
    int p_FLAG_RstCntDone;
    int p_FLAG_Qplllock;
    int p_FLAG_TxRstdone;
    int p_FLAG_RxRstdone;
    int p_FLAG_TxUsrRdy;
    #define LAST_TENGIGETHREG_PARAM p_FLAG_TxUsrRdy


    #define NUM_TENGIGETHREG_PARAMS (&LAST_TENGIGETHREG_PARAM - &FIRST_TENGIGETHREG_PARAM + 1)

private:

};

#endif

