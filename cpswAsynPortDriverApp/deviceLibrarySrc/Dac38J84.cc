#include "Dac38J84.h"

#define addrSize 4

Dac38J84 IDac38J84::create(const char *name)
{
Dac38J84Impl v = CShObj::create<Dac38J84Impl>(name);
Field f;
        f = IIntField::create("IntStatus", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("LaneBufferDelay", 5, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("Temperature", 8, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("L1ErrCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);
        f = IIntField::create("L2ErrCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);
        f = IIntField::create("L1SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1ReadFifoEmpty", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1ReadFifoUnderflow", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1ReadFifoFull", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1ReadFifoOverflow", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1DispErr", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1NotitableErr", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1CodeSyncErr", 1, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1FirstDataMatchErr", 1, false, 11);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1ElasticBuffOverflow", 1, false, 12);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1LinkConfigErr", 1, false, 13);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1FrameAlignErr", 1, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L1MultiFrameAlignErr", 1, false, 15);
        v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);
        f = IIntField::create("L2SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2ReadFifoEmpty", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2ReadFifoUnderflow", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2ReadFifoFull", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2ReadFifoOverflow", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2DispErr", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2NotitableErr", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2CodeSyncErr", 1, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2FirstDataMatchErr", 1, false, 11);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2ElasticBuffOverflow", 1, false, 12);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2LinkConfigErr", 1, false, 13);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2FrameAlignErr", 1, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L2MultiFrameAlignErr", 1, false, 15);
        v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);
        f = IIntField::create("L3SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x66*addrSize);
        f = IIntField::create("L4SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x67*addrSize);
        f = IIntField::create("L5SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x68*addrSize);
        f = IIntField::create("L6SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x69*addrSize);
        f = IIntField::create("L7SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6A*addrSize);
        f = IIntField::create("L8SERDES_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6B*addrSize);
        f = IIntField::create("Sysref_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Serdes1pllAlarm", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Serdes0pllAlarm", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("SysRefAlarms", 4, false, 12);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Lane_alarm", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);
        f = IIntField::create("Lane1Loss", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);
        f = IIntField::create("Lane2Loss", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);
        f = IIntField::create("Lane1Alarm", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);
        f = IIntField::create("Lane2Alarm", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);
        f = IIntField::create("IDs", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x7F*addrSize);
        f = IIntField::create("DacReg0x0000", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0000*addrSize);
        f = IIntField::create("DacReg0x0001", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0001*addrSize);
        f = IIntField::create("DacReg0x0002", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0002*addrSize);
        f = IIntField::create("DacReg0x0003", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0003*addrSize);
        f = IIntField::create("DacReg0x0004", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0004*addrSize);
        f = IIntField::create("DacReg0x0005", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0005*addrSize);
        f = IIntField::create("DacReg0x0006", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0006*addrSize);
        return v;
}

CDac38J84Impl::CDac38J84Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

