#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <epicsExport.h>
#include <iocsh.h>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "Kc705TenGigEth.h"

#define VERSION_AXI_BASE_ADDR_C     (0x00000000)
#define XADC_AXI_BASE_ADDR_C        (0x00010000)


digFpga IdigFpga::create(const char *name)
{
digFpgaImpl v = CEntryImpl::create<digFpgaImpl::element_type>(name);
AXIVers      axiv         = IAXIVers::create("AxiVersion");
AXIXadc      axixadc      = IAXIXadc::create("AxiXadc");

        
        v->CMMIODevImpl::addAtAddress( axiv ,VERSION_AXI_BASE_ADDR_C );
        v->CMMIODevImpl::addAtAddress( axixadc , XADC_AXI_BASE_ADDR_C );

        return v;
}

CdigFpgaImpl::CdigFpgaImpl(FKey key) : CMMIODevImpl(key, 0x000B0000 >> 2, LE)
{
}

extern "C" int Kc705TenGigEthCreate(const char *ipAddr)
{
  
  NoSsiDev r  = INoSsiDev::create("root", ipAddr);
  digFpga digFpga = IdigFpga::create("digFpga");
  rootDev root = IrootDev::Instance();
  r->addAtAddress( digFpga, INoSsiDev::SRP_UDP_V2, 8192 );
  root->addAtAddress( r );

  return 1;
}


/** Code for iocsh registration */
static const iocshArg Kc705TenGigEthCreateArg0 = {"IP Address", iocshArgString};
static const iocshArg * const Kc705TenGigEthCreateArgs[] = {&Kc705TenGigEthCreateArg0};
static const iocshFuncDef Kc705TenGigEthCreateDef = {"Kc705TenGigEthCreate", 1, Kc705TenGigEthCreateArgs};
static void AxiXadcCreateContollerCallFunc(const iocshArgBuf *args)
{
  Kc705TenGigEthCreate(args[0].sval);
}

static void Kc705TenGigEthRegister(void)
{
  iocshRegister(&Kc705TenGigEthCreateDef, AxiXadcCreateContollerCallFunc);
}

extern "C" {
epicsExportRegistrar(Kc705TenGigEthRegister);
}

