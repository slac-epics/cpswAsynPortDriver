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

#include "AmcCarrier.h"

#define BAY0_BASE_ADDR_C   (0x80000000) 
#define BAY1_BASE_ADDR_C   (0x80800000)

#define AXIVERSION_BASE_ADDR_C   ( 0x00000000 )
#define PGP2BAXI_BASE_ADDR_C   ( 0x0A000000 )
#define JESDRX_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00000000)  )
#define JESDTX_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00100000)  )
#define LMK04828_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00200000)  )
#define ADC16DX370_0_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00300000) )
#define ADC16DX370_1_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00400000)  )
#define DAC38J84_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00500000) )
#define AMCGENERICADCDACCTRL_BASE_ADDR_C   ( (BAY1_BASE_ADDR_C + 0x00600000) )
#define JESDRXDAQ_BASE_ADDR_C   ( 0x81000000  )

AmcCarrier IAmcCarrier::create(const char *name)
{
AmcCarrierImpl v = CShObj::create<AmcCarrierImpl>(name);

        AxiVersion p1 = IAxiVersion::create("AxiVersion");
        v->CMMIODevImpl::addAtAddress( p1, AXIVERSION_BASE_ADDR_C );

        Pgp2bAxi p2 = IPgp2bAxi::create("Pgp2bAxi");
        v->CMMIODevImpl::addAtAddress( p2, PGP2BAXI_BASE_ADDR_C );

        JesdRx p3 = IJesdRx::create("JesdRx");
        v->CMMIODevImpl::addAtAddress( p3, JESDRX_BASE_ADDR_C );

        JesdTx p4 = IJesdTx::create("JesdTx");
        v->CMMIODevImpl::addAtAddress( p4, JESDTX_BASE_ADDR_C );

        Lmk04828 p5 = ILmk04828::create("Lmk04828");
        v->CMMIODevImpl::addAtAddress( p5, LMK04828_BASE_ADDR_C );

        Adc16Dx370 p6 = IAdc16Dx370::create("Adc16Dx370_0");
        v->CMMIODevImpl::addAtAddress( p6, ADC16DX370_0_BASE_ADDR_C );

        Adc16Dx370 p7 = IAdc16Dx370::create("Adc16Dx370_1");
        v->CMMIODevImpl::addAtAddress( p7, ADC16DX370_1_BASE_ADDR_C );

        Dac38J84 p8 = IDac38J84::create("Dac38J84");
        v->CMMIODevImpl::addAtAddress( p8, DAC38J84_BASE_ADDR_C );

        AmcGenericAdcDacCtrl p9 = IAmcGenericAdcDacCtrl::create("AmcGenericAdcDacCtrl");
        v->CMMIODevImpl::addAtAddress( p9, AMCGENERICADCDACCTRL_BASE_ADDR_C );

        JesdRxDaq p10 = IJesdRxDaq::create("JesdRxDaq");
        v->CMMIODevImpl::addAtAddress( p10, JESDRXDAQ_BASE_ADDR_C );

        return v;
}

CAmcCarrierImpl::CAmcCarrierImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x90000000 , LE)
{
}

extern "C" int AmcCarrierCreate(const char *ipAddr)
{
  
  NoSsiDev r  = INoSsiDev::create("root", ipAddr);
  AmcCarrier AmcCarrier = IAmcCarrier::create("AmcCarrier");
  Dev root = IDev::getRootDev();
  r->addAtAddress( AmcCarrier, INoSsiDev::SRP_UDP_V2, 8192 );
  root->addAtAddress( r );

  return 1;
}


/** Code for iocsh registration */
static const iocshArg AmcCarrierCreateArg0 = {"IP Address", iocshArgString};
static const iocshArg * const AmcCarrierCreateArgs[] = {&AmcCarrierCreateArg0};
static const iocshFuncDef AmcCarrierCreateDef = {"AmcCarrierCreate", 1, AmcCarrierCreateArgs};
static void AmcCarrierCreateCallFunc(const iocshArgBuf *args)
{
  AmcCarrierCreate(args[0].sval);
}

static void AmcCarrierRegister(void)
{
  iocshRegister(&AmcCarrierCreateDef, AmcCarrierCreateCallFunc);
}

extern "C" {
epicsExportRegistrar(AmcCarrierRegister);
}


