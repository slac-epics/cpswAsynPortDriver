#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "device_library.h"

#define VERSION_AXI_BASE_ADDR_C     (0x00000000 )
//#define XADC_AXI_BASE_ADDR_C        (0x00010000)
#define XADC_AXI_BASE_ADDR_C        (0x00010000 )
/*#define COMMON_AXI_BASE_ADDR_C      (0x00010000)
#define ADC0_AXI_BASE_ADDR_C        (0x00020000)
#define ADC1_AXI_BASE_ADDR_C        (0x00030000)
#define DAC0_AXI_BASE_ADDR_C        (0x00040000)
#define DAC1_AXI_BASE_ADDR_C        (0x00050000)
#define DAC2_AXI_BASE_ADDR_C        (0x00060000)
#define DAC3_AXI_BASE_ADDR_C        (0x00070000)
#define BOOT_MEM_AXI_BASE_ADDR_C    (0x00080000)
#define XADC_AXI_BASE_ADDR_C        (0x00090000)
#define SFP_CTRL_AXI_BASE_ADDR_C    (0x000A0000)
*/


digFpga IdigFpga::create(const char *name)
{
digFpgaImpl v = CEntryImpl::create<digFpgaImpl::element_type>(name);
AXIVers      axiv         = IAXIVers::create("AxiVersion");
//AXILtc2270   axiltc2270   = IAXILtc2270::create("AxiLtc2270");
//AXIAd5780    axiad5780    = IAXIAd5780::create("AxiAd5780");
AXIXadc      axixadc      = IAXIXadc::create("AxiXadc");
//AXICommon    axic         = IAXICommon::create("AxiCommon");
//AXIMicronP30 aximicronp30 = IAXIMicronP30::create("AxiMicronP30");

        
        v->CMMIODevImpl::addAtAddress( axiv ,VERSION_AXI_BASE_ADDR_C );
//        v->CMMIODevImpl::addAtAddress( axiltc2270 , ADC0_AXI_BASE_ADDR_C, 2 ); //nelm 2
//        v->CMMIODevImpl::addAtAddress( axiad5780 , DAC0_AXI_BASE_ADDR_C, 4 ); //nelm 4
        v->CMMIODevImpl::addAtAddress( axixadc , XADC_AXI_BASE_ADDR_C );
//        v->CMMIODevImpl::addAtAddress( axic , COMMON_AXI_BASE_ADDR_C );
//        v->CMMIODevImpl::addAtAddress( aximicronp30 , BOOT_MEM_AXI_BASE_ADDR_C );

        return v;
}

CdigFpgaImpl::CdigFpgaImpl(FKey key) : CMMIODevImpl(key, 0x000B0000 >> 2, LE)
{
}

rootDev IrootDev::m_instance;

rootDev IrootDev::Instance()
{
 if ( !m_instance ) {
   //lock
   if ( !m_instance ) {
     rootDevImpl temp = CEntryImpl::create<rootDevImpl::element_type>("rootDev");
     IrootDev::m_instance = temp;
   } 
 }
 return IrootDev::m_instance;
}

CrootDevImpl::CrootDevImpl(FKey key) : CDevImpl(key, 0)
{
}
