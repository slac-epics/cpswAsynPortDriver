#include "JesdRxDaq.h"

#define addrSize 4

JesdRxDaq IJesdRxDaq::create(const char *name)
{
JesdRxDaqImpl v = CShObj::create<JesdRxDaqImpl>(name);
Field f;
        f = IIntField::create("SwDaqTrigger", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("SwDaqTrigger0", 0, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("SampleDecimation", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("DaqBufferSize", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("S1ChannelSelect", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("S2ChannelSelect", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("StatusStream0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("Pause0", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("Idle0", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("Overflow0", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("Error0", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("JESDValid0", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("Enable0", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("PacketCnt0", 16, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("StatusStream1", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("Pause1", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("Idle1", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("Overflow1", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("Error1", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("JESDValid1", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("Enable1", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("PacketCnt1", 16, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        return v;
}

CJesdRxDaqImpl::CJesdRxDaqImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

