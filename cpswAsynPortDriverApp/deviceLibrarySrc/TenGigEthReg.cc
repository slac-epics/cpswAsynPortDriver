#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "TenGigEthReg.h"

#define addrSize 4

TenGigEthReg ITenGigEthReg::create(const char *name)
{
TenGigEthRegImpl v = CEntryImpl::create<TenGigEthRegImpl::element_type>(name);
Field f;
        f = IIntField::create("PhyReadyCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("RxPauseCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("TxPauseCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("RxCountEnCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("RxOverFlowCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("RxCrcErrorCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("TxCountEnCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);
        f = IIntField::create("TxUnderRunCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("TxNotReadyCnt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);
        f = IIntField::create("TxDisable", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);
        f = IIntField::create("SigDet", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);
        f = IIntField::create("TxFault", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0B*addrSize);
        f = IIntField::create("GtTxRst", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0C*addrSize);
        f = IIntField::create("GtRxRst", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0D*addrSize);
        f = IIntField::create("RstCntDone", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0E*addrSize);
        f = IIntField::create("Qplllock", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0F*addrSize);
        f = IIntField::create("TxRstdone", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("RxRstdone", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("TxUsrRdy", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_PhyReady", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RxPause", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxPause", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RxCountEn", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RxOverFlow", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RxCrcError", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxCountEn", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxUnderRun", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxNotReady", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxDisable", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_SigDet", 1, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxFault", 1, false, 11);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_GtTxRst", 1, false, 12);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_GtRxRst", 1, false, 13);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RstCntDone", 1, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_Qplllock", 1, false, 15);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxRstdone", 1, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_RxRstdone", 1, false, 17);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("FLAG_TxUsrRdy", 1, false, 18);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        return v;
}

CTenGigEthRegImpl::CTenGigEthRegImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

