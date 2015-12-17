#ifndef AXIAD5780_DRIVER_H
#define AXIAD5780_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define dacRefreshRateString "dacRefreshRate"
#define dacDataString "dacData"
#define debugMuxString "debugMux"
#define debugDataString "debugData"
#define sdoDisableString "sdoDisable"
#define binaryOffsetString "binaryOffset"
#define dacTriStateString "dacTriState"
#define opGndString "opGnd"
#define rbufString "rbuf"
#define halfSckPeriodString "halfSckPeriod"
#define dacRstString "dacRst"

/* Commands */
#define CdacRstString "C_dacRst"


 /* This class implements the AxiVersion driver. */
class AxiAd5780Driver : public cpswAsynDriver {
public:
    AxiAd5780Driver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_dacRefreshRate;
    #define FIRST_AXIAD5780_PARAM p_dacRefreshRate
    int p_dacData;
    int p_debugMux;
    int p_debugData;
    int p_sdoDisable;
    int p_binaryOffset;
    int p_dacTriState;
    int p_opGnd;
    int p_rbuf;
    int p_halfSckPeriod;
    int p_dacRst;
/* Commands */
    int p_C_dacRst;
    #define LAST_AXIAD5780_PARAM p_C_dacRst


    #define NUM_AXIAD5780_PARAMS (&LAST_AXIAD5780_PARAM - &FIRST_AXIAD5780_PARAM + 1)

private:
    asynStatus dacRst();

};

#endif

