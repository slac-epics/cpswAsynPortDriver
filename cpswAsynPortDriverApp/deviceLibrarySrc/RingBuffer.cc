#include "RingBuffer.h"

#define addrSize 4

RingBuffer IRingBuffer::create(const char *name)
{
RingBufferImpl v = CShObj::create<RingBufferImpl>(name);
Field f;
        f = IIntField::create("WaveformSize", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("RAM_ADDR_WIDTH_G", 8, false, 20);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("ExtdataLogClr", 1, false, 28);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("ExtDataLogEn", 1, false, 29);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("IntdataLogClr", 1, false, 30);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("IntDataLogEn", 1, false, 31);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("Reg0x0000", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("RingBuffer", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize, 2046);
        return v;
}

CRingBufferImpl::CRingBufferImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

