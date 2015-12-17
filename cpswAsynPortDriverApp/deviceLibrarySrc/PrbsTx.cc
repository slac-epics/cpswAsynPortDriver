#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "PrbsTx.h"

#define addrSize 4

PrbsTx IPrbsTx::create(const char *name)
{
PrbsTxImpl v = CEntryImpl::create<PrbsTxImpl::element_type>(name);
Field f;
        f = IIntField::create("ConfigStatus", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("AxiEn", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("TxEn", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("Busy", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("Overflow", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("PacketLength", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("AxiStreamCfg", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("tDest", 8, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("tId", 8, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("DataCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("EventCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("RandomData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        return v;
}

CPrbsTxImpl::CPrbsTxImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

