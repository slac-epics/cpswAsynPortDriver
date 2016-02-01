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
#define AdcReg0x0100String "AdcReg0x0100"
#define AdcReg0x0101String "AdcReg0x0101"
#define AdcReg0x0102String "AdcReg0x0102"
#define AdcReg0x0103String "AdcReg0x0103"
#define AdcReg0x0104String "AdcReg0x0104"
#define AdcReg0x0105String "AdcReg0x0105"
#define AdcReg0x0106String "AdcReg0x0106"
#define AdcReg0x0107String "AdcReg0x0107"
#define AdcReg0x0108String "AdcReg0x0108"
#define AdcReg0x0109String "AdcReg0x0109"
#define AdcReg0x010aString "AdcReg0x010a"
#define AdcReg0x010bString "AdcReg0x010b"
#define AdcReg0x010cString "AdcReg0x010c"
#define AdcReg0x010dString "AdcReg0x010d"
#define AdcReg0x010eString "AdcReg0x010e"
#define AdcReg0x010fString "AdcReg0x010f"
#define AdcReg0x0110String "AdcReg0x0110"
#define AdcReg0x0111String "AdcReg0x0111"
#define AdcReg0x0112String "AdcReg0x0112"
#define AdcReg0x0113String "AdcReg0x0113"
#define AdcReg0x0114String "AdcReg0x0114"
#define AdcReg0x0115String "AdcReg0x0115"
#define AdcReg0x0116String "AdcReg0x0116"
#define AdcReg0x0117String "AdcReg0x0117"
#define AdcReg0x0118String "AdcReg0x0118"
#define AdcReg0x0119String "AdcReg0x0119"
#define AdcReg0x011aString "AdcReg0x011a"
#define AdcReg0x011bString "AdcReg0x011b"
#define AdcReg0x011cString "AdcReg0x011c"
#define AdcReg0x011dString "AdcReg0x011d"
#define AdcReg0x011eString "AdcReg0x011e"
#define AdcReg0x011fString "AdcReg0x011f"
#define AdcReg0x0120String "AdcReg0x0120"
#define AdcReg0x0121String "AdcReg0x0121"
#define AdcReg0x0122String "AdcReg0x0122"
#define AdcReg0x0123String "AdcReg0x0123"
#define AdcReg0x0124String "AdcReg0x0124"
#define AdcReg0x0125String "AdcReg0x0125"
#define AdcReg0x0126String "AdcReg0x0126"
#define AdcReg0x0127String "AdcReg0x0127"
#define AdcReg0x0128String "AdcReg0x0128"
#define AdcReg0x0129String "AdcReg0x0129"
#define AdcReg0x012aString "AdcReg0x012a"
#define AdcReg0x012bString "AdcReg0x012b"
#define AdcReg0x012cString "AdcReg0x012c"
#define AdcReg0x012dString "AdcReg0x012d"
#define AdcReg0x012eString "AdcReg0x012e"
#define AdcReg0x012fString "AdcReg0x012f"
#define AdcReg0x0130String "AdcReg0x0130"
#define AdcReg0x0131String "AdcReg0x0131"
#define AdcReg0x0132String "AdcReg0x0132"
#define AdcReg0x0133String "AdcReg0x0133"
#define AdcReg0x0134String "AdcReg0x0134"
#define AdcReg0x0135String "AdcReg0x0135"
#define AdcReg0x0136String "AdcReg0x0136"
#define AdcReg0x0137String "AdcReg0x0137"
#define AdcReg0x0138String "AdcReg0x0138"
#define AdcReg0x0139String "AdcReg0x0139"
#define AdcReg0x013aString "AdcReg0x013a"
#define AdcReg0x013bString "AdcReg0x013b"
#define AdcReg0x013cString "AdcReg0x013c"
#define AdcReg0x013dString "AdcReg0x013d"
#define AdcReg0x013eString "AdcReg0x013e"
#define AdcReg0x013fString "AdcReg0x013f"
#define AdcReg0x0140String "AdcReg0x0140"
#define AdcReg0x0141String "AdcReg0x0141"
#define AdcReg0x0142String "AdcReg0x0142"
#define AdcReg0x0143String "AdcReg0x0143"
#define AdcReg0x0144String "AdcReg0x0144"
#define AdcReg0x0145String "AdcReg0x0145"
#define AdcReg0x0146String "AdcReg0x0146"
#define AdcReg0x0147String "AdcReg0x0147"
#define AdcReg0x0148String "AdcReg0x0148"
#define AdcReg0x0149String "AdcReg0x0149"
#define AdcReg0x014aString "AdcReg0x014a"
#define AdcReg0x014bString "AdcReg0x014b"
#define AdcReg0x014cString "AdcReg0x014c"
#define AdcReg0x014dString "AdcReg0x014d"
#define AdcReg0x014eString "AdcReg0x014e"
#define AdcReg0x014fString "AdcReg0x014f"
#define AdcReg0x0150String "AdcReg0x0150"
#define AdcReg0x0151String "AdcReg0x0151"
#define AdcReg0x0152String "AdcReg0x0152"
#define AdcReg0x0153String "AdcReg0x0153"
#define AdcReg0x0154String "AdcReg0x0154"
#define AdcReg0x0155String "AdcReg0x0155"
#define AdcReg0x0156String "AdcReg0x0156"
#define AdcReg0x0157String "AdcReg0x0157"
#define AdcReg0x0158String "AdcReg0x0158"
#define AdcReg0x0159String "AdcReg0x0159"
#define AdcReg0x015aString "AdcReg0x015a"
#define AdcReg0x015bString "AdcReg0x015b"
#define AdcReg0x015cString "AdcReg0x015c"
#define AdcReg0x015dString "AdcReg0x015d"
#define AdcReg0x015eString "AdcReg0x015e"
#define AdcReg0x015fString "AdcReg0x015f"
#define AdcReg0x0160String "AdcReg0x0160"
#define AdcReg0x0161String "AdcReg0x0161"
#define AdcReg0x0162String "AdcReg0x0162"
#define AdcReg0x0163String "AdcReg0x0163"
#define AdcReg0x0164String "AdcReg0x0164"
#define AdcReg0x0165String "AdcReg0x0165"
#define AdcReg0x0166String "AdcReg0x0166"
#define AdcReg0x0167String "AdcReg0x0167"
#define AdcReg0x0168String "AdcReg0x0168"
#define AdcReg0x0169String "AdcReg0x0169"
#define AdcReg0x016aString "AdcReg0x016a"
#define AdcReg0x016bString "AdcReg0x016b"
#define AdcReg0x016cString "AdcReg0x016c"
#define AdcReg0x016dString "AdcReg0x016d"
#define AdcReg0x016eString "AdcReg0x016e"
#define AdcReg0x016fString "AdcReg0x016f"
#define AdcReg0x0170String "AdcReg0x0170"
#define AdcReg0x0171String "AdcReg0x0171"
#define AdcReg0x0172String "AdcReg0x0172"
#define AdcReg0x0173String "AdcReg0x0173"
#define AdcReg0x0174String "AdcReg0x0174"
#define AdcReg0x0175String "AdcReg0x0175"
#define AdcReg0x0176String "AdcReg0x0176"
#define AdcReg0x0177String "AdcReg0x0177"
#define AdcReg0x0178String "AdcReg0x0178"
#define AdcReg0x0179String "AdcReg0x0179"
#define AdcReg0x017aString "AdcReg0x017a"
#define AdcReg0x017bString "AdcReg0x017b"
#define AdcReg0x017cString "AdcReg0x017c"

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
    int p_AdcReg0x0100;
    int p_AdcReg0x0101;
    int p_AdcReg0x0102;
    int p_AdcReg0x0103;
    int p_AdcReg0x0104;
    int p_AdcReg0x0105;
    int p_AdcReg0x0106;
    int p_AdcReg0x0107;
    int p_AdcReg0x0108;
    int p_AdcReg0x0109;
    int p_AdcReg0x010a;
    int p_AdcReg0x010b;
    int p_AdcReg0x010c;
    int p_AdcReg0x010d;
    int p_AdcReg0x010e;
    int p_AdcReg0x010f;
    int p_AdcReg0x0110;
    int p_AdcReg0x0111;
    int p_AdcReg0x0112;
    int p_AdcReg0x0113;
    int p_AdcReg0x0114;
    int p_AdcReg0x0115;
    int p_AdcReg0x0116;
    int p_AdcReg0x0117;
    int p_AdcReg0x0118;
    int p_AdcReg0x0119;
    int p_AdcReg0x011a;
    int p_AdcReg0x011b;
    int p_AdcReg0x011c;
    int p_AdcReg0x011d;
    int p_AdcReg0x011e;
    int p_AdcReg0x011f;
    int p_AdcReg0x0120;
    int p_AdcReg0x0121;
    int p_AdcReg0x0122;
    int p_AdcReg0x0123;
    int p_AdcReg0x0124;
    int p_AdcReg0x0125;
    int p_AdcReg0x0126;
    int p_AdcReg0x0127;
    int p_AdcReg0x0128;
    int p_AdcReg0x0129;
    int p_AdcReg0x012a;
    int p_AdcReg0x012b;
    int p_AdcReg0x012c;
    int p_AdcReg0x012d;
    int p_AdcReg0x012e;
    int p_AdcReg0x012f;
    int p_AdcReg0x0130;
    int p_AdcReg0x0131;
    int p_AdcReg0x0132;
    int p_AdcReg0x0133;
    int p_AdcReg0x0134;
    int p_AdcReg0x0135;
    int p_AdcReg0x0136;
    int p_AdcReg0x0137;
    int p_AdcReg0x0138;
    int p_AdcReg0x0139;
    int p_AdcReg0x013a;
    int p_AdcReg0x013b;
    int p_AdcReg0x013c;
    int p_AdcReg0x013d;
    int p_AdcReg0x013e;
    int p_AdcReg0x013f;
    int p_AdcReg0x0140;
    int p_AdcReg0x0141;
    int p_AdcReg0x0142;
    int p_AdcReg0x0143;
    int p_AdcReg0x0144;
    int p_AdcReg0x0145;
    int p_AdcReg0x0146;
    int p_AdcReg0x0147;
    int p_AdcReg0x0148;
    int p_AdcReg0x0149;
    int p_AdcReg0x014a;
    int p_AdcReg0x014b;
    int p_AdcReg0x014c;
    int p_AdcReg0x014d;
    int p_AdcReg0x014e;
    int p_AdcReg0x014f;
    int p_AdcReg0x0150;
    int p_AdcReg0x0151;
    int p_AdcReg0x0152;
    int p_AdcReg0x0153;
    int p_AdcReg0x0154;
    int p_AdcReg0x0155;
    int p_AdcReg0x0156;
    int p_AdcReg0x0157;
    int p_AdcReg0x0158;
    int p_AdcReg0x0159;
    int p_AdcReg0x015a;
    int p_AdcReg0x015b;
    int p_AdcReg0x015c;
    int p_AdcReg0x015d;
    int p_AdcReg0x015e;
    int p_AdcReg0x015f;
    int p_AdcReg0x0160;
    int p_AdcReg0x0161;
    int p_AdcReg0x0162;
    int p_AdcReg0x0163;
    int p_AdcReg0x0164;
    int p_AdcReg0x0165;
    int p_AdcReg0x0166;
    int p_AdcReg0x0167;
    int p_AdcReg0x0168;
    int p_AdcReg0x0169;
    int p_AdcReg0x016a;
    int p_AdcReg0x016b;
    int p_AdcReg0x016c;
    int p_AdcReg0x016d;
    int p_AdcReg0x016e;
    int p_AdcReg0x016f;
    int p_AdcReg0x0170;
    int p_AdcReg0x0171;
    int p_AdcReg0x0172;
    int p_AdcReg0x0173;
    int p_AdcReg0x0174;
    int p_AdcReg0x0175;
    int p_AdcReg0x0176;
    int p_AdcReg0x0177;
    int p_AdcReg0x0178;
    int p_AdcReg0x0179;
    int p_AdcReg0x017a;
    int p_AdcReg0x017b;
    int p_AdcReg0x017c;
/* Commands */
    int p_C_CalibrateADC;
    #define LAST_ADC16DX370_PARAM p_C_CalibrateADC


    #define NUM_ADC16DX370_PARAMS (&LAST_ADC16DX370_PARAM - &FIRST_ADC16DX370_PARAM + 1)

private:
    asynStatus CalibrateADC();

};

#endif

