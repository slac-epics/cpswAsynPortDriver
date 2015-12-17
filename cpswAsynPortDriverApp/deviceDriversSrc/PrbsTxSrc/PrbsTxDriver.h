#ifndef PRBSTX_DRIVER_H
#define PRBSTX_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define ConfigStatusString "ConfigStatus"
#define AxiEnString "AxiEn"
#define TxEnString "TxEn"
#define BusyString "Busy"
#define OverflowString "Overflow"
#define PacketLengthString "PacketLength"
#define AxiStreamCfgString "AxiStreamCfg"
#define tDestString "tDest"
#define tIdString "tId"
#define DataCountString "DataCount"
#define EventCountString "EventCount"
#define RandomDataString "RandomData"

/* Commands */
#define COneShotString "C_OneShot"


 /* This class implements the AxiVersion driver. */
class PrbsTxDriver : public cpswAsynDriver {
public:
    PrbsTxDriver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_ConfigStatus;
    #define FIRST_PRBSTX_PARAM p_ConfigStatus
    int p_AxiEn;
    int p_TxEn;
    int p_Busy;
    int p_Overflow;
    int p_PacketLength;
    int p_AxiStreamCfg;
    int p_tDest;
    int p_tId;
    int p_DataCount;
    int p_EventCount;
    int p_RandomData;
/* Commands */
    int p_C_OneShot;
    #define LAST_PRBSTX_PARAM p_C_OneShot


    #define NUM_PRBSTX_PARAMS (&LAST_PRBSTX_PARAM - &FIRST_PRBSTX_PARAM + 1)

private:
    asynStatus OneShot();

};

#endif

