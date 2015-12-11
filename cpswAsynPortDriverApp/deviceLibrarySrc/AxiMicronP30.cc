#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiMicronP30.h"

#define addrSize 4

AXIMicronP30 IAXIMicronP30::create(const char *name)
{
AXIMicronP30Impl v = CEntryImpl::create<AXIMicronP30Impl::element_type>(name);
Field f;
        f = IIntField::create("Data", false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00 );
        f = IIntField::create("Addr", 32, false,  0);
        v->CMMIODevImpl::addAtAddress( f,   0x01 );
        f = IIntField::create("Read", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02 );
        f = IIntField::create("Test", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03 );
        f = IIntField::create("FastAddr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x04 );
        f = IIntField::create("FastProg", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x05 );
        f = IIntField::create("BurstAddr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x06 );

        return v;
}

CAXIMicronP30Impl::CAXIMicronP30Impl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}
