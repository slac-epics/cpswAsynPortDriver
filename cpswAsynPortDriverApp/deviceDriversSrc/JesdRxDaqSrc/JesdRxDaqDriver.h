#ifndef JESDRXDAQ_DRIVER_H
#define JESDRXDAQ_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define SwDaqTriggerString "SwDaqTrigger"
#define SwDaqTrigger0String "SwDaqTrigger0"
#define SampleDecimationString "SampleDecimation"
#define DaqBufferSizeString "DaqBufferSize"
#define S1ChannelSelectString "S1ChannelSelect"
#define S2ChannelSelectString "S2ChannelSelect"
#define StatusStream0String "StatusStream0"
#define Pause0String "Pause0"
#define Idle0String "Idle0"
#define Overflow0String "Overflow0"
#define Error0String "Error0"
#define JESDValid0String "JESDValid0"
#define Enable0String "Enable0"
#define PacketCnt0String "PacketCnt0"
#define StatusStream1String "StatusStream1"
#define Pause1String "Pause1"
#define Idle1String "Idle1"
#define Overflow1String "Overflow1"
#define Error1String "Error1"
#define JESDValid1String "JESDValid1"
#define Enable1String "Enable1"
#define PacketCnt1String "PacketCnt1"

/* Commands */
#define CTriggerDAQString "C_TriggerDAQ"


 /* This class implements the AxiVersion driver. */
class JesdRxDaqDriver : public cpswAsynDriver {
public:
    JesdRxDaqDriver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_SwDaqTrigger;
    #define FIRST_JESDRXDAQ_PARAM p_SwDaqTrigger
    int p_SwDaqTrigger0;
    int p_SampleDecimation;
    int p_DaqBufferSize;
    int p_S1ChannelSelect;
    int p_S2ChannelSelect;
    int p_StatusStream0;
    int p_Pause0;
    int p_Idle0;
    int p_Overflow0;
    int p_Error0;
    int p_JESDValid0;
    int p_Enable0;
    int p_PacketCnt0;
    int p_StatusStream1;
    int p_Pause1;
    int p_Idle1;
    int p_Overflow1;
    int p_Error1;
    int p_JESDValid1;
    int p_Enable1;
    int p_PacketCnt1;
/* Commands */
    int p_C_TriggerDAQ;
    #define LAST_JESDRXDAQ_PARAM p_C_TriggerDAQ


    #define NUM_JESDRXDAQ_PARAMS (&LAST_JESDRXDAQ_PARAM - &FIRST_JESDRXDAQ_PARAM + 1)

private:
    asynStatus TriggerDAQ();

};

#endif

