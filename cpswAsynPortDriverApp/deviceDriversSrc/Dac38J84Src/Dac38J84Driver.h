#ifndef DAC38J84_DRIVER_H
#define DAC38J84_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define IntStatusString "IntStatus"
#define LaneBufferDelayString "LaneBufferDelay"
#define TemperatureString "Temperature"
#define L1ErrCntString "L1ErrCnt"
#define L2ErrCntString "L2ErrCnt"
#define L1SERDES_alarmString "L1SERDES_alarm"
#define L1ReadFifoEmptyString "L1ReadFifoEmpty"
#define L1ReadFifoUnderflowString "L1ReadFifoUnderflow"
#define L1ReadFifoFullString "L1ReadFifoFull"
#define L1ReadFifoOverflowString "L1ReadFifoOverflow"
#define L1DispErrString "L1DispErr"
#define L1NotitableErrString "L1NotitableErr"
#define L1CodeSyncErrString "L1CodeSyncErr"
#define L1FirstDataMatchErrString "L1FirstDataMatchErr"
#define L1ElasticBuffOverflowString "L1ElasticBuffOverflow"
#define L1LinkConfigErrString "L1LinkConfigErr"
#define L1FrameAlignErrString "L1FrameAlignErr"
#define L1MultiFrameAlignErrString "L1MultiFrameAlignErr"
#define L2SERDES_alarmString "L2SERDES_alarm"
#define L2ReadFifoEmptyString "L2ReadFifoEmpty"
#define L2ReadFifoUnderflowString "L2ReadFifoUnderflow"
#define L2ReadFifoFullString "L2ReadFifoFull"
#define L2ReadFifoOverflowString "L2ReadFifoOverflow"
#define L2DispErrString "L2DispErr"
#define L2NotitableErrString "L2NotitableErr"
#define L2CodeSyncErrString "L2CodeSyncErr"
#define L2FirstDataMatchErrString "L2FirstDataMatchErr"
#define L2ElasticBuffOverflowString "L2ElasticBuffOverflow"
#define L2LinkConfigErrString "L2LinkConfigErr"
#define L2FrameAlignErrString "L2FrameAlignErr"
#define L2MultiFrameAlignErrString "L2MultiFrameAlignErr"
#define L3SERDES_alarmString "L3SERDES_alarm"
#define L4SERDES_alarmString "L4SERDES_alarm"
#define L5SERDES_alarmString "L5SERDES_alarm"
#define L6SERDES_alarmString "L6SERDES_alarm"
#define L7SERDES_alarmString "L7SERDES_alarm"
#define L8SERDES_alarmString "L8SERDES_alarm"
#define Sysref_alarmString "Sysref_alarm"
#define Serdes1pllAlarmString "Serdes1pllAlarm"
#define Serdes0pllAlarmString "Serdes0pllAlarm"
#define SysRefAlarmsString "SysRefAlarms"
#define Lane_alarmString "Lane_alarm"
#define Lane1LossString "Lane1Loss"
#define Lane2LossString "Lane2Loss"
#define Lane1AlarmString "Lane1Alarm"
#define Lane2AlarmString "Lane2Alarm"
#define IDsString "IDs"
#define DacReg0x0000String "DacReg0x0000"
#define DacReg0x0001String "DacReg0x0001"
#define DacReg0x0002String "DacReg0x0002"
#define DacReg0x0003String "DacReg0x0003"
#define DacReg0x0004String "DacReg0x0004"
#define DacReg0x0005String "DacReg0x0005"
#define DacReg0x0006String "DacReg0x0006"

/* Commands */
#define CClearDACAlarmsString "C_ClearDACAlarms"
#define CInitDAC_JESDString "C_InitDAC_JESD"


 /* This class implements the AxiVersion driver. */
class Dac38J84Driver : public cpswAsynDriver {
public:
    Dac38J84Driver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_IntStatus;
    #define FIRST_DAC38J84_PARAM p_IntStatus
    int p_LaneBufferDelay;
    int p_Temperature;
    int p_L1ErrCnt;
    int p_L2ErrCnt;
    int p_L1SERDES_alarm;
    int p_L1ReadFifoEmpty;
    int p_L1ReadFifoUnderflow;
    int p_L1ReadFifoFull;
    int p_L1ReadFifoOverflow;
    int p_L1DispErr;
    int p_L1NotitableErr;
    int p_L1CodeSyncErr;
    int p_L1FirstDataMatchErr;
    int p_L1ElasticBuffOverflow;
    int p_L1LinkConfigErr;
    int p_L1FrameAlignErr;
    int p_L1MultiFrameAlignErr;
    int p_L2SERDES_alarm;
    int p_L2ReadFifoEmpty;
    int p_L2ReadFifoUnderflow;
    int p_L2ReadFifoFull;
    int p_L2ReadFifoOverflow;
    int p_L2DispErr;
    int p_L2NotitableErr;
    int p_L2CodeSyncErr;
    int p_L2FirstDataMatchErr;
    int p_L2ElasticBuffOverflow;
    int p_L2LinkConfigErr;
    int p_L2FrameAlignErr;
    int p_L2MultiFrameAlignErr;
    int p_L3SERDES_alarm;
    int p_L4SERDES_alarm;
    int p_L5SERDES_alarm;
    int p_L6SERDES_alarm;
    int p_L7SERDES_alarm;
    int p_L8SERDES_alarm;
    int p_Sysref_alarm;
    int p_Serdes1pllAlarm;
    int p_Serdes0pllAlarm;
    int p_SysRefAlarms;
    int p_Lane_alarm;
    int p_Lane1Loss;
    int p_Lane2Loss;
    int p_Lane1Alarm;
    int p_Lane2Alarm;
    int p_IDs;
    int p_DacReg0x0000;
    int p_DacReg0x0001;
    int p_DacReg0x0002;
    int p_DacReg0x0003;
    int p_DacReg0x0004;
    int p_DacReg0x0005;
    int p_DacReg0x0006;
/* Commands */
    int p_C_ClearDACAlarms;
    int p_C_InitDAC_JESD;
    #define LAST_DAC38J84_PARAM p_C_InitDAC_JESD


    #define NUM_DAC38J84_PARAMS (&LAST_DAC38J84_PARAM - &FIRST_DAC38J84_PARAM + 1)

private:
    asynStatus ClearDACAlarms();
    asynStatus InitDAC_JESD();

};

#endif

