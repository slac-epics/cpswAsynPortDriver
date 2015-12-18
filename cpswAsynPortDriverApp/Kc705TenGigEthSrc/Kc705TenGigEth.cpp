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


#define AXIVERSION_BASE_ADDR_C   ( 0x00000000 )
#define AXIXADC_BASE_ADDR_C   ( 0x00010000 )

Kc705TenGigEth IKc705TenGigEth::create(const char *name)
{
Kc705TenGigEthImpl v = CEntryImpl::create<Kc705TenGigEthImpl::element_type>(name);

        AxiVersion p1 = IAxiVersion::create("AxiVersion");
        v->CMMIODevImpl::addAtAddress( p1, AXIVERSION_BASE_ADDR_C );

        AxiXadc p2 = IAxiXadc::create("AxiXadc");
        v->CMMIODevImpl::addAtAddress( p2, AXIXADC_BASE_ADDR_C );

        return v;
}

CKc705TenGigEthImpl::CKc705TenGigEthImpl(FKey key) : CMMIODevImpl(key, 0x000B0000 , LE)
{
}

extern "C" int Kc705TenGigEthCreate(const char *ipAddr)
{
  
  NoSsiDev r  = INoSsiDev::create("root", ipAddr);
  Kc705TenGigEth Kc705TenGigEth = IKc705TenGigEth::create("Kc705TenGigEth");
  Dev root = IDev::getRootDev();
  r->addAtAddress( Kc705TenGigEth, INoSsiDev::SRP_UDP_V2, 8192 );
  root->addAtAddress( r );

  return 1;
}


/** Code for iocsh registration */
static const iocshArg Kc705TenGigEthCreateArg0 = {"IP Address", iocshArgString};
static const iocshArg * const Kc705TenGigEthCreateArgs[] = {&Kc705TenGigEthCreateArg0};
static const iocshFuncDef Kc705TenGigEthCreateDef = {"Kc705TenGigEthCreate", 1, Kc705TenGigEthCreateArgs};
static void Kc705TenGigEthCreateCallFunc(const iocshArgBuf *args)
{
  Kc705TenGigEthCreate(args[0].sval);
}

static void Kc705TenGigEthRegister(void)
{
  iocshRegister(&Kc705TenGigEthCreateDef, Kc705TenGigEthCreateCallFunc);
}

extern "C" {
epicsExportRegistrar(Kc705TenGigEthRegister);
}


