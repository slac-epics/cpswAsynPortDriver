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

#include "Kcu105NoRssi.h"


#define AXIVERSION_BASE_ADDR_C   ( 0x00000000 )
#define TENGIGETHREG_BASE_ADDR_C   ( 0x00020000 )
#define PRBSTX_BASE_ADDR_C   ( 0x00030000 )

Kcu105NoRssi IKcu105NoRssi::create(const char *name)
{
Kcu105NoRssiImpl v = CShObj::create<Kcu105NoRssiImpl>(name);

        AxiVersion p1 = IAxiVersion::create("AxiVersion");
        v->CMMIODevImpl::addAtAddress( p1, AXIVERSION_BASE_ADDR_C );

        TenGigEthReg p2 = ITenGigEthReg::create("TenGigEthReg");
        v->CMMIODevImpl::addAtAddress( p2, TENGIGETHREG_BASE_ADDR_C );

        PrbsTx p3 = IPrbsTx::create("PrbsTx");
        v->CMMIODevImpl::addAtAddress( p3, PRBSTX_BASE_ADDR_C );

        return v;
}

CKcu105NoRssiImpl::CKcu105NoRssiImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x000B0000 , LE)
{
}

extern "C" int Kcu105NoRssiCreate(const char *ipAddr)
{
  
  NoSsiDev r  = INoSsiDev::create("root", ipAddr);
  Kcu105NoRssi Kcu105NoRssi = IKcu105NoRssi::create("Kcu105NoRssi");
  Dev root = IDev::getRootDev();
  r->addAtAddress( Kcu105NoRssi, INoSsiDev::SRP_UDP_V2, 8192 );
  root->addAtAddress( r );

  return 1;
}


/** Code for iocsh registration */
static const iocshArg Kcu105NoRssiCreateArg0 = {"IP Address", iocshArgString};
static const iocshArg * const Kcu105NoRssiCreateArgs[] = {&Kcu105NoRssiCreateArg0};
static const iocshFuncDef Kcu105NoRssiCreateDef = {"Kcu105NoRssiCreate", 1, Kcu105NoRssiCreateArgs};
static void Kcu105NoRssiCreateCallFunc(const iocshArgBuf *args)
{
  Kcu105NoRssiCreate(args[0].sval);
}

static void Kcu105NoRssiRegister(void)
{
  iocshRegister(&Kcu105NoRssiCreateDef, Kcu105NoRssiCreateCallFunc);
}

extern "C" {
epicsExportRegistrar(Kcu105NoRssiRegister);
}


