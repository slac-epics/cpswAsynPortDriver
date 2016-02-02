#ifndef ADC16DX370_DRIVER_H
#define ADC16DX370_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define ID_DEVICE_TYPEString "ID_DEVICE_TYPE"
#define PD_MODEString "PD_MODE"
#define ID_PROD_UPPERString "ID_PROD_UPPER"
#define ID_PROD_LOWERString "ID_PROD_LOWER"
#define ID_MASKREVString "ID_MASKREV"
#define ID_VNDR_UPPERString "ID_VNDR_UPPER"
#define ID_VNDR_LOWERString "ID_VNDR_LOWER"
#define ADC_StatusString "ADC_Status"
#define Clock_readyString "Clock_ready"
#define Calibration_doneString "Calibration_done"
#define PLL_lockString "PLL_lock"
#define Aligned_to_sysrefString "Aligned_to_sysref"
#define Realigned_to_sysrefString "Realigned_to_sysref"
#define Sync_form_FPGAString "Sync_form_FPGA"
#define Link_activeString "Link_active"
#define SYS_ENString "SYS_EN"
#define AdcReg0x0000String "AdcReg0x0000"
#define AdcReg0x0002String "AdcReg0x0002"
#define AdcReg0x0003String "AdcReg0x0003"
#define AdcReg0x0004String "AdcReg0x0004"
#define AdcReg0x0005String "AdcReg0x0005"
#define AdcReg0x0006String "AdcReg0x0006"
#define AdcReg0x000cString "AdcReg0x000c"
#define AdcReg0x000dString "AdcReg0x000d"
#define AdcReg0x000eString "AdcReg0x000e"
#define AdcReg0x000fString "AdcReg0x000f"
#define AdcReg0x0010String "AdcReg0x0010"
#define AdcReg0x0011String "AdcReg0x0011"
#define AdcReg0x0012String "AdcReg0x0012"
#define AdcReg0x0013String "AdcReg0x0013"
#define AdcReg0x0014String "AdcReg0x0014"
#define AdcReg0x0015String "AdcReg0x0015"
#define AdcReg0x0019String "AdcReg0x0019"
#define AdcReg0x003bString "AdcReg0x003b"
#define AdcReg0x003cString "AdcReg0x003c"
#define AdcReg0x003dString "AdcReg0x003d"
#define AdcReg0x0047String "AdcReg0x0047"
#define AdcReg0x0060String "AdcReg0x0060"
#define AdcReg0x0061String "AdcReg0x0061"
#define AdcReg0x0062String "AdcReg0x0062"
#define AdcReg0x0063String "AdcReg0x0063"
#define AdcReg0x0070String "AdcReg0x0070"

/* Commands */
#define CCalibrateADCString "C_CalibrateADC"


 /* This class implements the AxiVersion driver. */
class Adc16Dx370Driver : public cpswAsynDriver {
public:
    Adc16Dx370Driver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_ID_DEVICE_TYPE;
    #define FIRST_ADC16DX370_PARAM p_ID_DEVICE_TYPE
    int p_PD_MODE;
    int p_ID_PROD_UPPER;
    int p_ID_PROD_LOWER;
    int p_ID_MASKREV;
    int p_ID_VNDR_UPPER;
    int p_ID_VNDR_LOWER;
    int p_ADC_Status;
    int p_Clock_ready;
    int p_Calibration_done;
    int p_PLL_lock;
    int p_Aligned_to_sysref;
    int p_Realigned_to_sysref;
    int p_Sync_form_FPGA;
    int p_Link_active;
    int p_SYS_EN;
    int p_AdcReg0x0000;
    int p_AdcReg0x0002;
    int p_AdcReg0x0003;
    int p_AdcReg0x0004;
    int p_AdcReg0x0005;
    int p_AdcReg0x0006;
    int p_AdcReg0x000c;
    int p_AdcReg0x000d;
    int p_AdcReg0x000e;
    int p_AdcReg0x000f;
    int p_AdcReg0x0010;
    int p_AdcReg0x0011;
    int p_AdcReg0x0012;
    int p_AdcReg0x0013;
    int p_AdcReg0x0014;
    int p_AdcReg0x0015;
    int p_AdcReg0x0019;
    int p_AdcReg0x003b;
    int p_AdcReg0x003c;
    int p_AdcReg0x003d;
    int p_AdcReg0x0047;
    int p_AdcReg0x0060;
    int p_AdcReg0x0061;
    int p_AdcReg0x0062;
    int p_AdcReg0x0063;
    int p_AdcReg0x0070;
/* Commands */
    int p_C_CalibrateADC;
    #define LAST_ADC16DX370_PARAM p_C_CalibrateADC


    #define NUM_ADC16DX370_PARAMS (&LAST_ADC16DX370_PARAM - &FIRST_ADC16DX370_PARAM + 1)

private:
    asynStatus CalibrateADC();

};

#endif

