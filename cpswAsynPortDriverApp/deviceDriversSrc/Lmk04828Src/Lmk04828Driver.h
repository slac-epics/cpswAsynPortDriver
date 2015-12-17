#ifndef LMK04828_DRIVER_H
#define LMK04828_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define ID_DEVICE_TYPEString "ID_DEVICE_TYPE"
#define ID_PROD_UPPERString "ID_PROD_UPPER"
#define ID_PROD_LOWERString "ID_PROD_LOWER"
#define ID_MASKREVString "ID_MASKREV"
#define ID_VNDR_UPPERString "ID_VNDR_UPPER"
#define ID_VNDR_LOWERString "ID_VNDR_LOWER"
#define SYS_REF_MUXString "SYS_REF_MUX"
#define SYNC_ENString "SYNC_EN"
#define SYNC_DISString "SYNC_DIS"
#define LmkReg0x0100String "LmkReg0x0100"
#define LmkReg0x0101String "LmkReg0x0101"
#define LmkReg0x0103String "LmkReg0x0103"
#define LmkReg0x0104String "LmkReg0x0104"
#define LmkReg0x0105String "LmkReg0x0105"
#define LmkReg0x0106String "LmkReg0x0106"
#define LmkReg0x0107String "LmkReg0x0107"
#define LmkReg0x0108String "LmkReg0x0108"
#define LmkReg0x0109String "LmkReg0x0109"
#define LmkReg0x010bString "LmkReg0x010b"
#define LmkReg0x010cString "LmkReg0x010c"
#define LmkReg0x010dString "LmkReg0x010d"
#define LmkReg0x010eString "LmkReg0x010e"
#define LmkReg0x010fString "LmkReg0x010f"
#define LmkReg0x0110String "LmkReg0x0110"
#define LmkReg0x0111String "LmkReg0x0111"
#define LmkReg0x0113String "LmkReg0x0113"
#define LmkReg0x0114String "LmkReg0x0114"
#define LmkReg0x0115String "LmkReg0x0115"
#define LmkReg0x0116String "LmkReg0x0116"
#define LmkReg0x0117String "LmkReg0x0117"
#define LmkReg0x0118String "LmkReg0x0118"
#define LmkReg0x0119String "LmkReg0x0119"
#define LmkReg0x011aString "LmkReg0x011a"
#define LmkReg0x011bString "LmkReg0x011b"
#define LmkReg0x011cString "LmkReg0x011c"
#define LmkReg0x011dString "LmkReg0x011d"
#define LmkReg0x011eString "LmkReg0x011e"
#define LmkReg0x011fString "LmkReg0x011f"
#define LmkReg0x0120String "LmkReg0x0120"
#define LmkReg0x0121String "LmkReg0x0121"
#define LmkReg0x0123String "LmkReg0x0123"
#define LmkReg0x0124String "LmkReg0x0124"
#define LmkReg0x0125String "LmkReg0x0125"
#define LmkReg0x0126String "LmkReg0x0126"
#define LmkReg0x0127String "LmkReg0x0127"
#define LmkReg0x0128String "LmkReg0x0128"
#define LmkReg0x0129String "LmkReg0x0129"
#define LmkReg0x012bString "LmkReg0x012b"
#define LmkReg0x012cString "LmkReg0x012c"
#define LmkReg0x012dString "LmkReg0x012d"
#define LmkReg0x012eString "LmkReg0x012e"
#define LmkReg0x012fString "LmkReg0x012f"
#define LmkReg0x0130String "LmkReg0x0130"
#define LmkReg0x0131String "LmkReg0x0131"
#define LmkReg0x0133String "LmkReg0x0133"
#define LmkReg0x0134String "LmkReg0x0134"
#define LmkReg0x0135String "LmkReg0x0135"
#define LmkReg0x0136String "LmkReg0x0136"
#define LmkReg0x0137String "LmkReg0x0137"
#define LmkReg0x0138String "LmkReg0x0138"
#define LmkReg0x0139String "LmkReg0x0139"
#define LmkReg0x013aString "LmkReg0x013a"
#define LmkReg0x013bString "LmkReg0x013b"
#define LmkReg0x013cString "LmkReg0x013c"
#define LmkReg0x013dString "LmkReg0x013d"
#define LmkReg0x013eString "LmkReg0x013e"
#define LmkReg0x013fString "LmkReg0x013f"
#define LmkReg0x0140String "LmkReg0x0140"
#define LmkReg0x0141String "LmkReg0x0141"
#define LmkReg0x0142String "LmkReg0x0142"
#define LmkReg0x0143String "LmkReg0x0143"
#define LmkReg0x0144String "LmkReg0x0144"
#define LmkReg0x0145String "LmkReg0x0145"
#define LmkReg0x0146String "LmkReg0x0146"
#define LmkReg0x0147String "LmkReg0x0147"
#define LmkReg0x0148String "LmkReg0x0148"
#define LmkReg0x0149String "LmkReg0x0149"
#define LmkReg0x014aString "LmkReg0x014a"
#define LmkReg0x014bString "LmkReg0x014b"
#define LmkReg0x014cString "LmkReg0x014c"
#define LmkReg0x014dString "LmkReg0x014d"
#define LmkReg0x014eString "LmkReg0x014e"
#define LmkReg0x014fString "LmkReg0x014f"
#define LmkReg0x0150String "LmkReg0x0150"
#define LmkReg0x0151String "LmkReg0x0151"
#define LmkReg0x0152String "LmkReg0x0152"
#define LmkReg0x0153String "LmkReg0x0153"
#define LmkReg0x0154String "LmkReg0x0154"
#define LmkReg0x0155String "LmkReg0x0155"
#define LmkReg0x0156String "LmkReg0x0156"
#define LmkReg0x0157String "LmkReg0x0157"
#define LmkReg0x0158String "LmkReg0x0158"
#define LmkReg0x0159String "LmkReg0x0159"
#define LmkReg0x015aString "LmkReg0x015a"
#define LmkReg0x015bString "LmkReg0x015b"
#define LmkReg0x015cString "LmkReg0x015c"
#define LmkReg0x015dString "LmkReg0x015d"
#define LmkReg0x015eString "LmkReg0x015e"
#define LmkReg0x015fString "LmkReg0x015f"
#define LmkReg0x0160String "LmkReg0x0160"
#define LmkReg0x0161String "LmkReg0x0161"
#define LmkReg0x0162String "LmkReg0x0162"
#define LmkReg0x0163String "LmkReg0x0163"
#define LmkReg0x0164String "LmkReg0x0164"
#define LmkReg0x0165String "LmkReg0x0165"
#define LmkReg0x0166String "LmkReg0x0166"
#define LmkReg0x0167String "LmkReg0x0167"
#define LmkReg0x0168String "LmkReg0x0168"
#define LmkReg0x0169String "LmkReg0x0169"
#define LmkReg0x016aString "LmkReg0x016a"
#define LmkReg0x016bString "LmkReg0x016b"
#define LmkReg0x016cString "LmkReg0x016c"
#define LmkReg0x016dString "LmkReg0x016d"
#define LmkReg0x016eString "LmkReg0x016e"
#define LmkReg0x0173String "LmkReg0x0173"
#define LmkReg0x0174String "LmkReg0x0174"
#define LmkReg0x017cString "LmkReg0x017c"

/* Commands */
#define CSyncClksString "C_SyncClks"
#define CwriteConfigString "C_writeConfig"


 /* This class implements the AxiVersion driver. */
class Lmk04828Driver : public cpswAsynDriver {
public:
    Lmk04828Driver(const char *portName, Path p, int nelms);

    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);


protected:
/* Registers */
    int p_ID_DEVICE_TYPE;
    #define FIRST_LMK04828_PARAM p_ID_DEVICE_TYPE
    int p_ID_PROD_UPPER;
    int p_ID_PROD_LOWER;
    int p_ID_MASKREV;
    int p_ID_VNDR_UPPER;
    int p_ID_VNDR_LOWER;
    int p_SYS_REF_MUX;
    int p_SYNC_EN;
    int p_SYNC_DIS;
    int p_LmkReg0x0100;
    int p_LmkReg0x0101;
    int p_LmkReg0x0103;
    int p_LmkReg0x0104;
    int p_LmkReg0x0105;
    int p_LmkReg0x0106;
    int p_LmkReg0x0107;
    int p_LmkReg0x0108;
    int p_LmkReg0x0109;
    int p_LmkReg0x010b;
    int p_LmkReg0x010c;
    int p_LmkReg0x010d;
    int p_LmkReg0x010e;
    int p_LmkReg0x010f;
    int p_LmkReg0x0110;
    int p_LmkReg0x0111;
    int p_LmkReg0x0113;
    int p_LmkReg0x0114;
    int p_LmkReg0x0115;
    int p_LmkReg0x0116;
    int p_LmkReg0x0117;
    int p_LmkReg0x0118;
    int p_LmkReg0x0119;
    int p_LmkReg0x011a;
    int p_LmkReg0x011b;
    int p_LmkReg0x011c;
    int p_LmkReg0x011d;
    int p_LmkReg0x011e;
    int p_LmkReg0x011f;
    int p_LmkReg0x0120;
    int p_LmkReg0x0121;
    int p_LmkReg0x0123;
    int p_LmkReg0x0124;
    int p_LmkReg0x0125;
    int p_LmkReg0x0126;
    int p_LmkReg0x0127;
    int p_LmkReg0x0128;
    int p_LmkReg0x0129;
    int p_LmkReg0x012b;
    int p_LmkReg0x012c;
    int p_LmkReg0x012d;
    int p_LmkReg0x012e;
    int p_LmkReg0x012f;
    int p_LmkReg0x0130;
    int p_LmkReg0x0131;
    int p_LmkReg0x0133;
    int p_LmkReg0x0134;
    int p_LmkReg0x0135;
    int p_LmkReg0x0136;
    int p_LmkReg0x0137;
    int p_LmkReg0x0138;
    int p_LmkReg0x0139;
    int p_LmkReg0x013a;
    int p_LmkReg0x013b;
    int p_LmkReg0x013c;
    int p_LmkReg0x013d;
    int p_LmkReg0x013e;
    int p_LmkReg0x013f;
    int p_LmkReg0x0140;
    int p_LmkReg0x0141;
    int p_LmkReg0x0142;
    int p_LmkReg0x0143;
    int p_LmkReg0x0144;
    int p_LmkReg0x0145;
    int p_LmkReg0x0146;
    int p_LmkReg0x0147;
    int p_LmkReg0x0148;
    int p_LmkReg0x0149;
    int p_LmkReg0x014a;
    int p_LmkReg0x014b;
    int p_LmkReg0x014c;
    int p_LmkReg0x014d;
    int p_LmkReg0x014e;
    int p_LmkReg0x014f;
    int p_LmkReg0x0150;
    int p_LmkReg0x0151;
    int p_LmkReg0x0152;
    int p_LmkReg0x0153;
    int p_LmkReg0x0154;
    int p_LmkReg0x0155;
    int p_LmkReg0x0156;
    int p_LmkReg0x0157;
    int p_LmkReg0x0158;
    int p_LmkReg0x0159;
    int p_LmkReg0x015a;
    int p_LmkReg0x015b;
    int p_LmkReg0x015c;
    int p_LmkReg0x015d;
    int p_LmkReg0x015e;
    int p_LmkReg0x015f;
    int p_LmkReg0x0160;
    int p_LmkReg0x0161;
    int p_LmkReg0x0162;
    int p_LmkReg0x0163;
    int p_LmkReg0x0164;
    int p_LmkReg0x0165;
    int p_LmkReg0x0166;
    int p_LmkReg0x0167;
    int p_LmkReg0x0168;
    int p_LmkReg0x0169;
    int p_LmkReg0x016a;
    int p_LmkReg0x016b;
    int p_LmkReg0x016c;
    int p_LmkReg0x016d;
    int p_LmkReg0x016e;
    int p_LmkReg0x0173;
    int p_LmkReg0x0174;
    int p_LmkReg0x017c;
/* Commands */
    int p_C_SyncClks;
    int p_C_writeConfig;
    #define LAST_LMK04828_PARAM p_C_writeConfig


    #define NUM_LMK04828_PARAMS (&LAST_LMK04828_PARAM - &FIRST_LMK04828_PARAM + 1)

private:
    asynStatus SyncClks();
    asynStatus writeConfig();

};

#endif

