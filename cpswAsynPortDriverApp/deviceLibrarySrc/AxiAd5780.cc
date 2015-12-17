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

AxiAd5780 IAxiAd5780::create(const char *name)
{
AxiAd5780Impl v = CEntryImpl::create<AxiAd5780Impl::element_type>(name);
Field f;
        f = IIntField::create("dacRefreshRate", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("dacData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);
        f = IIntField::create("debugMux", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize);
        f = IIntField::create("debugData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x90*addrSize);
        f = IIntField::create("sdoDisable", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA0*addrSize);
        f = IIntField::create("binaryOffset", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA1*addrSize);
        f = IIntField::create("dacTriState", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA2*addrSize);
        f = IIntField::create("opGnd", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA3*addrSize);
        f = IIntField::create("rbuf", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA4*addrSize);
        f = IIntField::create("halfSckPeriod", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xA5*addrSize);
        f = IIntField::create("dacRst", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xFE*addrSize);
        return v;
}

CAxiAd5780Impl::CAxiAd5780Impl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

