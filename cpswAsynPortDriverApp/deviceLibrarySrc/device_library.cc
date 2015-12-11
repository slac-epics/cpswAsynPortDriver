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

rootDev IrootDev::m_instance;
rootDev IrootDev::Instance()
{
 if ( !m_instance ) {
   //add lock
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
