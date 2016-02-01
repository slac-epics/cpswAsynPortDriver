#ifndef PGP2BAXI_DRIVER_H
#define PGP2BAXI_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define CountResetString "CountReset"
#define ResetRxString "ResetRx"
#define FlushString "Flush"
#define LoopbackString "Loopback"
#define LocDataString "LocData"
#define AutoStatusString "AutoStatus"
#define StatusString "Status"
#define RxPhyReadyString "RxPhyReady"
#define TxPhyReadyString "TxPhyReady"
#define RxLocalLinkReadyString "RxLocalLinkReady"
#define RxRemLinkReadyString "RxRemLinkReady"
#define TxLinkReadyString "TxLinkReady"
#define RxLinkPolarityString "RxLinkPolarity"
#define RxRemPauseString "RxRemPause"
#define TxLocPauseString "TxLocPause"
#define RxRemOverflowString "RxRemOverflow"
#define TxLocOverflowString "TxLocOverflow"
#define RxRemLinkDataString "RxRemLinkData"
#define RxCellErrorCountString "RxCellErrorCount"
#define RxLinkDownCountString "RxLinkDownCount"
#define RxLinkErrorCountString "RxLinkErrorCount"
#define RxRemOverflow0CountString "RxRemOverflow0Count"
#define RxRemOverflow1CountString "RxRemOverflow1Count"
#define RxRemOverflow2CountString "RxRemOverflow2Count"
#define RxRemOverflow3CountString "RxRemOverflow3Count"
#define RxFrameErrorCountString "RxFrameErrorCount"
#define RxFrameCountString "RxFrameCount"
#define TxLocOverflow0CountString "TxLocOverflow0Count"
#define TxLocOverflow1CountString "TxLocOverflow1Count"
#define TxLocOverflow2CountString "TxLocOverflow2Count"
#define TxLocOverflow3CountString "TxLocOverflow3Count"
#define TxFrameErrorCountString "TxFrameErrorCount"
#define TxFrameCountString "TxFrameCount"
#define RxClkFreqString "RxClkFreq"
#define TxClkFreqString "TxClkFreq"
#define TxOpCodeStatusString "TxOpCodeStatus"
#define LastTxOpCodeString "LastTxOpCode"
#define RxOpCodeStatusString "RxOpCodeStatus"
#define LastRxOpCodeString "LastRxOpCode"
#define TxOpCodeCountString "TxOpCodeCount"
#define RxOpCodeCountString "RxOpCodeCount"

/* Commands */
#define CResetRxString "C_ResetRx"
#define CFlushString "C_Flush"


 /* This class implements the AxiVersion driver. */
class Pgp2bAxiDriver : public cpswAsynDriver {
public:
    Pgp2bAxiDriver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_CountReset;
    #define FIRST_PGP2BAXI_PARAM p_CountReset
    int p_ResetRx;
    int p_Flush;
    int p_Loopback;
    int p_LocData;
    int p_AutoStatus;
    int p_Status;
    int p_RxPhyReady;
    int p_TxPhyReady;
    int p_RxLocalLinkReady;
    int p_RxRemLinkReady;
    int p_TxLinkReady;
    int p_RxLinkPolarity;
    int p_RxRemPause;
    int p_TxLocPause;
    int p_RxRemOverflow;
    int p_TxLocOverflow;
    int p_RxRemLinkData;
    int p_RxCellErrorCount;
    int p_RxLinkDownCount;
    int p_RxLinkErrorCount;
    int p_RxRemOverflow0Count;
    int p_RxRemOverflow1Count;
    int p_RxRemOverflow2Count;
    int p_RxRemOverflow3Count;
    int p_RxFrameErrorCount;
    int p_RxFrameCount;
    int p_TxLocOverflow0Count;
    int p_TxLocOverflow1Count;
    int p_TxLocOverflow2Count;
    int p_TxLocOverflow3Count;
    int p_TxFrameErrorCount;
    int p_TxFrameCount;
    int p_RxClkFreq;
    int p_TxClkFreq;
    int p_TxOpCodeStatus;
    int p_LastTxOpCode;
    int p_RxOpCodeStatus;
    int p_LastRxOpCode;
    int p_TxOpCodeCount;
    int p_RxOpCodeCount;
/* Commands */
    int p_C_ResetRx;
    int p_C_Flush;
    #define LAST_PGP2BAXI_PARAM p_C_Flush


    #define NUM_PGP2BAXI_PARAMS (&LAST_PGP2BAXI_PARAM - &FIRST_PGP2BAXI_PARAM + 1)

private:
    asynStatus ResetRx();
    asynStatus Flush();

};

#endif

