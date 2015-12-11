#include "AxiVersionDriver.h"
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

static const char *driverName = "AxiVersionDriver";


AxiVersionDriver::AxiVersionDriver(const char *portName, Path p, int nelms)
                 :cpswAsynDriver(portName, p, nelms, NUM_AXIV_PARAMS)
{
   createParam(FpgaVersionString,        asynParamInt32,       &p_FpgaVersion);
   createParam(ScratchPadString,         asynParamInt32,       &p_ScratchPad);
   createParam(DeviceDnaHighString,      asynParamInt32,       &p_DeviceDnaHigh);
   createParam(DeviceDnaLowString,       asynParamInt32,       &p_DeviceDnaLow);
   createParam(FdSerialHighString,       asynParamInt32,       &p_FdSerialHigh);
   createParam(FdSerialLowString,        asynParamInt32,       &p_FdSerialLow);
   createParam(MasterResetString,        asynParamInt32,       &p_MasterReset);
   createParam(FpgaReloadString,         asynParamInt32,       &p_FpgaReload);
   createParam(FpgaReloadAddressString,  asynParamInt32,       &p_FpgaReloadAddress);
   createParam(CounterString,            asynParamInt32,       &p_Counter);
   createParam(FpgaReloadHaltString,     asynParamInt32,       &p_FpgaReloadHalt);
   createParam(UserConstantsString,      asynParamInt32,       &p_UserConstants);
   createParam(BuildStampString,         asynParamOctet,       &p_BuildStamp);
}

extern "C" int AxiVersionCreate(const char *portName, const char *path)
{
  
  NoSsiDev r  = INoSsiDev::create("root", "192.168.2.10");
  digFpga digFpga = IdigFpga::create("digFpga");
  rootDev root = IrootDev::Instance();
  r->addAtAddress( digFpga, INoSsiDev::SRP_UDP_V2, 8192 );
  root->addAtAddress( r );
  Path p = IrootDev::Instance()->findByName(path);
  p->dump( stdout ); fputc('\n', stdout);
  Child c = p->tail();
  if (c == NULL) {
    printf("Child is NULL\n");
  }
  else {
  printf("Child found\n");
  printf("Childl nelms:%d\n", c->getNelms());
  new AxiVersionDriver(portName, p, c->getNelms());
  }
  return(asynSuccess);
}


/** Code for iocsh registration */
static const iocshArg AxiVersionCreateArg0 = {"Port name", iocshArgString};
static const iocshArg AxiVersionCreateArg1 = {"ACR port name", iocshArgString};
static const iocshArg * const AxiVersionCreateArgs[] = {&AxiVersionCreateArg0,
                                                           &AxiVersionCreateArg1};
static const iocshFuncDef AxiVersionCreateDef = {"AxiVersionCreate", 2, AxiVersionCreateArgs};
static void ACRCreateContollerCallFunc(const iocshArgBuf *args)
{
  AxiVersionCreate(args[0].sval, args[1].sval);
}

static void AxiVersionRegister(void)
{
  iocshRegister(&AxiVersionCreateDef, ACRCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(AxiVersionRegister);
}

