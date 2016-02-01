#include "Lmk04828Driver.h"
#include "asynPortDriver.h"
#include "cpswAsynPortDriver.h"
#include <device_library.h>
#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iocsh.h>
#include <epicsThread.h>

#include <epicsExport.h>

static const char *driverName = "Lmk04828Driver";


Lmk04828Driver::Lmk04828Driver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p->findByName("Lmk04828"), nelms, NUM_LMK04828_PARAMS)
{

/* Registers */
   createParam(ID_DEVICE_TYPEString, asynParamInt32, &p_ID_DEVICE_TYPE, IScalVal::create);
   createParam(ID_PROD_UPPERString, asynParamInt32, &p_ID_PROD_UPPER, IScalVal::create);
   createParam(ID_PROD_LOWERString, asynParamInt32, &p_ID_PROD_LOWER, IScalVal::create);
   createParam(ID_MASKREVString, asynParamInt32, &p_ID_MASKREV, IScalVal::create);
   createParam(ID_VNDR_UPPERString, asynParamInt32, &p_ID_VNDR_UPPER, IScalVal::create);
   createParam(ID_VNDR_LOWERString, asynParamInt32, &p_ID_VNDR_LOWER, IScalVal::create);
   createParam(SYS_REF_MUXString, asynParamInt32, &p_SYS_REF_MUX, IScalVal::create);
   createParam(SYNC_ENString, asynParamInt32, &p_SYNC_EN, IScalVal::create);
   createParam(SYNC_DISString, asynParamInt32, &p_SYNC_DIS, IScalVal::create);
   createParam(LmkReg0x0100String, asynParamInt32, &p_LmkReg0x0100, IScalVal::create);
   createParam(LmkReg0x0101String, asynParamInt32, &p_LmkReg0x0101, IScalVal::create);
   createParam(LmkReg0x0103String, asynParamInt32, &p_LmkReg0x0103, IScalVal::create);
   createParam(LmkReg0x0104String, asynParamInt32, &p_LmkReg0x0104, IScalVal::create);
   createParam(LmkReg0x0105String, asynParamInt32, &p_LmkReg0x0105, IScalVal::create);
   createParam(LmkReg0x0106String, asynParamInt32, &p_LmkReg0x0106, IScalVal::create);
   createParam(LmkReg0x0107String, asynParamInt32, &p_LmkReg0x0107, IScalVal::create);
   createParam(LmkReg0x0108String, asynParamInt32, &p_LmkReg0x0108, IScalVal::create);
   createParam(LmkReg0x0109String, asynParamInt32, &p_LmkReg0x0109, IScalVal::create);
   createParam(LmkReg0x010bString, asynParamInt32, &p_LmkReg0x010b, IScalVal::create);
   createParam(LmkReg0x010cString, asynParamInt32, &p_LmkReg0x010c, IScalVal::create);
   createParam(LmkReg0x010dString, asynParamInt32, &p_LmkReg0x010d, IScalVal::create);
   createParam(LmkReg0x010eString, asynParamInt32, &p_LmkReg0x010e, IScalVal::create);
   createParam(LmkReg0x010fString, asynParamInt32, &p_LmkReg0x010f, IScalVal::create);
   createParam(LmkReg0x0110String, asynParamInt32, &p_LmkReg0x0110, IScalVal::create);
   createParam(LmkReg0x0111String, asynParamInt32, &p_LmkReg0x0111, IScalVal::create);
   createParam(LmkReg0x0113String, asynParamInt32, &p_LmkReg0x0113, IScalVal::create);
   createParam(LmkReg0x0114String, asynParamInt32, &p_LmkReg0x0114, IScalVal::create);
   createParam(LmkReg0x0115String, asynParamInt32, &p_LmkReg0x0115, IScalVal::create);
   createParam(LmkReg0x0116String, asynParamInt32, &p_LmkReg0x0116, IScalVal::create);
   createParam(LmkReg0x0117String, asynParamInt32, &p_LmkReg0x0117, IScalVal::create);
   createParam(LmkReg0x0118String, asynParamInt32, &p_LmkReg0x0118, IScalVal::create);
   createParam(LmkReg0x0119String, asynParamInt32, &p_LmkReg0x0119, IScalVal::create);
   createParam(LmkReg0x011aString, asynParamInt32, &p_LmkReg0x011a, IScalVal::create);
   createParam(LmkReg0x011bString, asynParamInt32, &p_LmkReg0x011b, IScalVal::create);
   createParam(LmkReg0x011cString, asynParamInt32, &p_LmkReg0x011c, IScalVal::create);
   createParam(LmkReg0x011dString, asynParamInt32, &p_LmkReg0x011d, IScalVal::create);
   createParam(LmkReg0x011eString, asynParamInt32, &p_LmkReg0x011e, IScalVal::create);
   createParam(LmkReg0x011fString, asynParamInt32, &p_LmkReg0x011f, IScalVal::create);
   createParam(LmkReg0x0120String, asynParamInt32, &p_LmkReg0x0120, IScalVal::create);
   createParam(LmkReg0x0121String, asynParamInt32, &p_LmkReg0x0121, IScalVal::create);
   createParam(LmkReg0x0123String, asynParamInt32, &p_LmkReg0x0123, IScalVal::create);
   createParam(LmkReg0x0124String, asynParamInt32, &p_LmkReg0x0124, IScalVal::create);
   createParam(LmkReg0x0125String, asynParamInt32, &p_LmkReg0x0125, IScalVal::create);
   createParam(LmkReg0x0126String, asynParamInt32, &p_LmkReg0x0126, IScalVal::create);
   createParam(LmkReg0x0127String, asynParamInt32, &p_LmkReg0x0127, IScalVal::create);
   createParam(LmkReg0x0128String, asynParamInt32, &p_LmkReg0x0128, IScalVal::create);
   createParam(LmkReg0x0129String, asynParamInt32, &p_LmkReg0x0129, IScalVal::create);
   createParam(LmkReg0x012bString, asynParamInt32, &p_LmkReg0x012b, IScalVal::create);
   createParam(LmkReg0x012cString, asynParamInt32, &p_LmkReg0x012c, IScalVal::create);
   createParam(LmkReg0x012dString, asynParamInt32, &p_LmkReg0x012d, IScalVal::create);
   createParam(LmkReg0x012eString, asynParamInt32, &p_LmkReg0x012e, IScalVal::create);
   createParam(LmkReg0x012fString, asynParamInt32, &p_LmkReg0x012f, IScalVal::create);
   createParam(LmkReg0x0130String, asynParamInt32, &p_LmkReg0x0130, IScalVal::create);
   createParam(LmkReg0x0131String, asynParamInt32, &p_LmkReg0x0131, IScalVal::create);
   createParam(LmkReg0x0133String, asynParamInt32, &p_LmkReg0x0133, IScalVal::create);
   createParam(LmkReg0x0134String, asynParamInt32, &p_LmkReg0x0134, IScalVal::create);
   createParam(LmkReg0x0135String, asynParamInt32, &p_LmkReg0x0135, IScalVal::create);
   createParam(LmkReg0x0136String, asynParamInt32, &p_LmkReg0x0136, IScalVal::create);
   createParam(LmkReg0x0137String, asynParamInt32, &p_LmkReg0x0137, IScalVal::create);
   createParam(LmkReg0x0138String, asynParamInt32, &p_LmkReg0x0138, IScalVal::create);
   createParam(LmkReg0x0139String, asynParamInt32, &p_LmkReg0x0139, IScalVal::create);
   createParam(LmkReg0x013aString, asynParamInt32, &p_LmkReg0x013a, IScalVal::create);
   createParam(LmkReg0x013bString, asynParamInt32, &p_LmkReg0x013b, IScalVal::create);
   createParam(LmkReg0x013cString, asynParamInt32, &p_LmkReg0x013c, IScalVal::create);
   createParam(LmkReg0x013dString, asynParamInt32, &p_LmkReg0x013d, IScalVal::create);
   createParam(LmkReg0x013eString, asynParamInt32, &p_LmkReg0x013e, IScalVal::create);
   createParam(LmkReg0x013fString, asynParamInt32, &p_LmkReg0x013f, IScalVal::create);
   createParam(LmkReg0x0140String, asynParamInt32, &p_LmkReg0x0140, IScalVal::create);
   createParam(LmkReg0x0141String, asynParamInt32, &p_LmkReg0x0141, IScalVal::create);
   createParam(LmkReg0x0142String, asynParamInt32, &p_LmkReg0x0142, IScalVal::create);
   createParam(LmkReg0x0143String, asynParamInt32, &p_LmkReg0x0143, IScalVal::create);
   createParam(LmkReg0x0144String, asynParamInt32, &p_LmkReg0x0144, IScalVal::create);
   createParam(LmkReg0x0145String, asynParamInt32, &p_LmkReg0x0145, IScalVal::create);
   createParam(LmkReg0x0146String, asynParamInt32, &p_LmkReg0x0146, IScalVal::create);
   createParam(LmkReg0x0147String, asynParamInt32, &p_LmkReg0x0147, IScalVal::create);
   createParam(LmkReg0x0148String, asynParamInt32, &p_LmkReg0x0148, IScalVal::create);
   createParam(LmkReg0x0149String, asynParamInt32, &p_LmkReg0x0149, IScalVal::create);
   createParam(LmkReg0x014aString, asynParamInt32, &p_LmkReg0x014a, IScalVal::create);
   createParam(LmkReg0x014bString, asynParamInt32, &p_LmkReg0x014b, IScalVal::create);
   createParam(LmkReg0x014cString, asynParamInt32, &p_LmkReg0x014c, IScalVal::create);
   createParam(LmkReg0x014dString, asynParamInt32, &p_LmkReg0x014d, IScalVal::create);
   createParam(LmkReg0x014eString, asynParamInt32, &p_LmkReg0x014e, IScalVal::create);
   createParam(LmkReg0x014fString, asynParamInt32, &p_LmkReg0x014f, IScalVal::create);
   createParam(LmkReg0x0150String, asynParamInt32, &p_LmkReg0x0150, IScalVal::create);
   createParam(LmkReg0x0151String, asynParamInt32, &p_LmkReg0x0151, IScalVal::create);
   createParam(LmkReg0x0152String, asynParamInt32, &p_LmkReg0x0152, IScalVal::create);
   createParam(LmkReg0x0153String, asynParamInt32, &p_LmkReg0x0153, IScalVal::create);
   createParam(LmkReg0x0154String, asynParamInt32, &p_LmkReg0x0154, IScalVal::create);
   createParam(LmkReg0x0155String, asynParamInt32, &p_LmkReg0x0155, IScalVal::create);
   createParam(LmkReg0x0156String, asynParamInt32, &p_LmkReg0x0156, IScalVal::create);
   createParam(LmkReg0x0157String, asynParamInt32, &p_LmkReg0x0157, IScalVal::create);
   createParam(LmkReg0x0158String, asynParamInt32, &p_LmkReg0x0158, IScalVal::create);
   createParam(LmkReg0x0159String, asynParamInt32, &p_LmkReg0x0159, IScalVal::create);
   createParam(LmkReg0x015aString, asynParamInt32, &p_LmkReg0x015a, IScalVal::create);
   createParam(LmkReg0x015bString, asynParamInt32, &p_LmkReg0x015b, IScalVal::create);
   createParam(LmkReg0x015cString, asynParamInt32, &p_LmkReg0x015c, IScalVal::create);
   createParam(LmkReg0x015dString, asynParamInt32, &p_LmkReg0x015d, IScalVal::create);
   createParam(LmkReg0x015eString, asynParamInt32, &p_LmkReg0x015e, IScalVal::create);
   createParam(LmkReg0x015fString, asynParamInt32, &p_LmkReg0x015f, IScalVal::create);
   createParam(LmkReg0x0160String, asynParamInt32, &p_LmkReg0x0160, IScalVal::create);
   createParam(LmkReg0x0161String, asynParamInt32, &p_LmkReg0x0161, IScalVal::create);
   createParam(LmkReg0x0162String, asynParamInt32, &p_LmkReg0x0162, IScalVal::create);
   createParam(LmkReg0x0163String, asynParamInt32, &p_LmkReg0x0163, IScalVal::create);
   createParam(LmkReg0x0164String, asynParamInt32, &p_LmkReg0x0164, IScalVal::create);
   createParam(LmkReg0x0165String, asynParamInt32, &p_LmkReg0x0165, IScalVal::create);
   createParam(LmkReg0x0166String, asynParamInt32, &p_LmkReg0x0166, IScalVal::create);
   createParam(LmkReg0x0167String, asynParamInt32, &p_LmkReg0x0167, IScalVal::create);
   createParam(LmkReg0x0168String, asynParamInt32, &p_LmkReg0x0168, IScalVal::create);
   createParam(LmkReg0x0169String, asynParamInt32, &p_LmkReg0x0169, IScalVal::create);
   createParam(LmkReg0x016aString, asynParamInt32, &p_LmkReg0x016a, IScalVal::create);
   createParam(LmkReg0x016bString, asynParamInt32, &p_LmkReg0x016b, IScalVal::create);
   createParam(LmkReg0x016cString, asynParamInt32, &p_LmkReg0x016c, IScalVal::create);
   createParam(LmkReg0x016dString, asynParamInt32, &p_LmkReg0x016d, IScalVal::create);
   createParam(LmkReg0x016eString, asynParamInt32, &p_LmkReg0x016e, IScalVal::create);
   createParam(LmkReg0x0173String, asynParamInt32, &p_LmkReg0x0173, IScalVal::create);
   createParam(LmkReg0x0174String, asynParamInt32, &p_LmkReg0x0174, IScalVal::create);
   createParam(LmkReg0x017cString, asynParamInt32, &p_LmkReg0x017c, IScalVal::create);

/* Commands */
   asynPortDriver::createParam(CSyncClksString, asynParamInt32, &p_C_SyncClks);
   asynPortDriver::createParam(CwriteConfigString, asynParamInt32, &p_C_writeConfig);
}

asynStatus Lmk04828Driver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    const char *paramName;
    if( function == p_C_SyncClks ) {
        status = SyncClks();
    }
    else if( function == p_C_writeConfig ) {
        status = writeConfig();
    }
    else {
        status = cpswAsynDriver::writeInt32(pasynUser, value);
    }

    return status;
}


asynStatus Lmk04828Driver::SyncClks()
{
   asynStatus status = asynSuccess;
   writeConfig();
   return status;
}
asynStatus Lmk04828Driver::writeConfig()
{
   asynStatus status = asynSuccess;
   uint32_t u32 = 0;
   try {
       /* Turn on normal SYNC */
       ScalVals[p_SYS_REF_MUX]->setVal( &u32, 1 );

       /* Poweron SYNC */
       ScalVals[p_SYNC_DIS]->setVal( &u32, 1 );

       epicsThreadSleep(1);

       /* toggle SYNC bit */
       u32 = 1;
       ScalVals[p_SYNC_EN]->setVal( &u32, 1 );
       u32 = 0;
       ScalVals[p_SYNC_EN]->setVal( &u32, 1 );

       u32 = 0xFFFFFFFF;  
       /*  Turn on normal continuous sysref */
       ScalVals[p_SYS_REF_MUX]->setVal( &u32, 1 );

       /*  Poweron down SYNC to not let it interfere */
       ScalVals[p_SYNC_DIS]->setVal( &u32, 1 );
   }
   catch(CPSWError &e) {
     printf("CPSWError: %s\n", e.getInfo().c_str());     
      return asynError;
   }

   return status;
}

extern "C" int Lmk04828Create(const char *portName, const char *path)
{
  
  Path p = IDev::getRootDev()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  printf("Child found\n");
  printf("Childl nelms:%d\n", c->getNelms());
  new Lmk04828Driver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg Lmk04828CreateArg0 = {"Port name", iocshArgString};
static const iocshArg Lmk04828CreateArg1 = {"Lmk04828 port name", iocshArgString};
static const iocshArg * const Lmk04828CreateArgs[] = {&Lmk04828CreateArg0,
                                                           &Lmk04828CreateArg1};
static const iocshFuncDef Lmk04828CreateDef = {"Lmk04828Create", 2, Lmk04828CreateArgs};
static void Lmk04828CreateContollerCallFunc(const iocshArgBuf *args)
{
  Lmk04828Create(args[0].sval, args[1].sval);
}

static void Lmk04828Register(void)
{
  iocshRegister(&Lmk04828CreateDef, Lmk04828CreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(Lmk04828Register);
}


