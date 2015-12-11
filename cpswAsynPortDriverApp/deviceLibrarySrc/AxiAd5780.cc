#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiAd5780.h"

#define addrSize 4

AXIAd5780 IAXIAd5780::create(const char *name)
{
AXIAd5780Impl v = CEntryImpl::create<AXIAd5780Impl::element_type>(name);
Field f;
        f = IIntField::create("dacRefreshRate", false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10 );
        f = IIntField::create("dacData", 32, false,  0);
        v->CMMIODevImpl::addAtAddress( f,   0x30 );
        f = IIntField::create("debugMux", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x80 );
        f = IIntField::create("debugData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x90 );
        f = IIntField::create("sdoDisable", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA0 );
        f = IIntField::create("binaryOffset", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA1 );
        f = IIntField::create("dacTriState", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA2 );
        f = IIntField::create("opGnd", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA3 );
        f = IIntField::create("rbuf", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA4 );
        f = IIntField::create("halfSckPeriod", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA5 );
        f = IIntField::create("dacRst", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFE );

        return v;
}

CAXIAd5780Impl::CAXIAd5780Impl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}
