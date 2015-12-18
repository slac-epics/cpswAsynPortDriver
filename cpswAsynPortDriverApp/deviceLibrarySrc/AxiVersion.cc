#include "AxiVersion.h"

#define addrSize 4

AxiVersion IAxiVersion::create(const char *name)
{
AxiVersionImpl v = CEntryImpl::create<AxiVersionImpl::element_type>(name);
Field f;
        f = IIntField::create("FpgaVersion", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("ScratchPad", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("DeviceDnaHigh", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("DeviceDnaLow", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("FdSerialHigh", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("FdSerialLow", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("MasterReset", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);
        f = IIntField::create("FpgaReload", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("FpgaReloadAddress", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("Counter", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);
        f = IIntField::create("FpgaReloadHalt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);
        f = IIntField::create("UserConstants", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x100*addrSize, 64);
        f = IIntField::create("BuildStamp", 8, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x200*addrSize, 64);
        return v;
}

CAxiVersionImpl::CAxiVersionImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

