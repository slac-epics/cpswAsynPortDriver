#ifndef AXIXADC_DRIVER_H
#define AXIXADC_DRIVER_H

#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <cpsw_api_user.h>

/* Registers */
#define TemperatureString "Temperature"
#define VccIntString "VccInt"
#define VccAuxString "VccAux"
#define VrefPString "VrefP"
#define VrefNString "VrefN"
#define VccBramString "VccBram"
#define SupplyOffsetAString "SupplyOffsetA"
#define AdcOffsetAString "AdcOffsetA"
#define AdcGainAString "AdcGainA"
#define VccpIntString "VccpInt"
#define VccpAuxString "VccpAux"
#define VccpDdrString "VccpDdr"
#define VinAux_0String "VinAux_0"
#define VinAux01String "VinAux01"
#define VinAux02String "VinAux02"
#define VinAux03String "VinAux03"
#define VinAux04String "VinAux04"
#define VinAux05String "VinAux05"
#define VinAux06String "VinAux06"
#define VinAux07String "VinAux07"
#define VinAux08String "VinAux08"
#define VinAux09String "VinAux09"
#define VinAux10String "VinAux10"
#define VinAux11String "VinAux11"
#define VinAux12String "VinAux12"
#define VinAux13String "VinAux13"
#define VinAux14String "VinAux14"
#define VinAux15String "VinAux15"
#define TemperatureMaxString "TemperatureMax"
#define VccIntMaxString "VccIntMax"
#define VccAuxMaxString "VccAuxMax"
#define VccBramMaxString "VccBramMax"
#define TemperatureMinString "TemperatureMin"
#define VccIntMinString "VccIntMin"
#define VccAuxMinString "VccAuxMin"
#define VccBramMinString "VccBramMin"
#define VccpIntMaxString "VccpIntMax"
#define VccpAuxMaxString "VccpAuxMax"
#define VccpDdrMaxString "VccpDdrMax"
#define VccpIntMinString "VccpIntMin"
#define VccpAuxMinString "VccpAuxMin"
#define VccpDdrMinString "VccpDdrMin"
#define FlagString "Flag"
#define Flag_JTGDString "Flag_JTGD"
#define Flag_JTGRString "Flag_JTGR"
#define Flag_REFString "Flag_REF"
#define Flag_VccpDdrString "Flag_VccpDdr"
#define Flag_VccpAuxString "Flag_VccpAux"
#define Flag_VccpIntString "Flag_VccpInt"
#define Flag_VccBramString "Flag_VccBram"
#define Flag_VccAuxString "Flag_VccAux"
#define Flag_VccIntString "Flag_VccInt"
#define Flag_TemperatureString "Flag_Temperature"

/* Commands */


 /* This class implements the AxiVersion driver. */
class AxiXadcDriver : public cpswAsynDriver {
public:
    AxiXadcDriver(const char *portName, Path p, int nelms);



protected:
/* Registers */
    int p_Temperature;
    #define FIRST_AXIXADC_PARAM p_Temperature
    int p_VccInt;
    int p_VccAux;
    int p_VrefP;
    int p_VrefN;
    int p_VccBram;
    int p_SupplyOffsetA;
    int p_AdcOffsetA;
    int p_AdcGainA;
    int p_VccpInt;
    int p_VccpAux;
    int p_VccpDdr;
    int p_VinAux_0;
    int p_VinAux01;
    int p_VinAux02;
    int p_VinAux03;
    int p_VinAux04;
    int p_VinAux05;
    int p_VinAux06;
    int p_VinAux07;
    int p_VinAux08;
    int p_VinAux09;
    int p_VinAux10;
    int p_VinAux11;
    int p_VinAux12;
    int p_VinAux13;
    int p_VinAux14;
    int p_VinAux15;
    int p_TemperatureMax;
    int p_VccIntMax;
    int p_VccAuxMax;
    int p_VccBramMax;
    int p_TemperatureMin;
    int p_VccIntMin;
    int p_VccAuxMin;
    int p_VccBramMin;
    int p_VccpIntMax;
    int p_VccpAuxMax;
    int p_VccpDdrMax;
    int p_VccpIntMin;
    int p_VccpAuxMin;
    int p_VccpDdrMin;
    int p_Flag;
    int p_Flag_JTGD;
    int p_Flag_JTGR;
    int p_Flag_REF;
    int p_Flag_VccpDdr;
    int p_Flag_VccpAux;
    int p_Flag_VccpInt;
    int p_Flag_VccBram;
    int p_Flag_VccAux;
    int p_Flag_VccInt;
    int p_Flag_Temperature;
    #define LAST_AXIXADC_PARAM p_Flag_Temperature


    #define NUM_AXIXADC_PARAMS (&LAST_AXIXADC_PARAM - &FIRST_AXIXADC_PARAM + 1)

private:

};

#endif

