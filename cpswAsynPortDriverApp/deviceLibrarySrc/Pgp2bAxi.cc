#include "Pgp2bAxi.h"

#define addrSize 4

Pgp2bAxi IPgp2bAxi::create(const char *name)
{
Pgp2bAxiImpl v = CShObj::create<Pgp2bAxiImpl>(name);
Field f;
        f = IIntField::create("CountReset", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("ResetRx", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("Flush", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("Loopback", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("LocData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("AutoStatus", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxPhyReady", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("TxPhyReady", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxLocalLinkReady", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxRemLinkReady", 3, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("TxLinkReady", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxLinkPolarity", 2, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxRemPause", 4, false, 12);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("TxLocPause", 4, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxRemOverflow", 4, false, 20);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("TxLocOverflow", 4, false, 24);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("RxRemLinkData", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);
        f = IIntField::create("RxCellErrorCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);
        f = IIntField::create("RxLinkDownCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0B*addrSize);
        f = IIntField::create("RxLinkErrorCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0C*addrSize);
        f = IIntField::create("RxRemOverflow0Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0D*addrSize);
        f = IIntField::create("RxRemOverflow1Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0E*addrSize);
        f = IIntField::create("RxRemOverflow2Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0F*addrSize);
        f = IIntField::create("RxRemOverflow3Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("RxFrameErrorCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("RxFrameCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("TxLocOverflow0Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("TxLocOverflow1Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("TxLocOverflow2Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("TxLocOverflow3Count", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x16*addrSize);
        f = IIntField::create("TxFrameErrorCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x17*addrSize);
        f = IIntField::create("TxFrameCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x18*addrSize);
        f = IIntField::create("RxClkFreq", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x19*addrSize);
        f = IIntField::create("TxClkFreq", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1A*addrSize);
        f = IIntField::create("TxOpCodeStatus", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1C*addrSize);
        f = IIntField::create("LastTxOpCode", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1C*addrSize);
        f = IIntField::create("RxOpCodeStatus", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1D*addrSize);
        f = IIntField::create("LastRxOpCode", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1D*addrSize);
        f = IIntField::create("TxOpCodeCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1E*addrSize);
        f = IIntField::create("RxOpCodeCount", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x1F*addrSize);
        return v;
}

CPgp2bAxiImpl::CPgp2bAxiImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

