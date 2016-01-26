#include "JesdTx.h"

#define addrSize 4

JesdTx IJesdTx::create(const char *name)
{
JesdTxImpl v = CShObj::create<JesdTxImpl>(name);
Field f;
        f = IIntField::create("Enable", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("CommonControl", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("SubClass", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("ReplaceEnable", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("ResetGTs", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("InvertSync", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("EnableTestSig", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("PeriodRampStep", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("RampStep", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("SquarePeriod", 16, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);
        f = IIntField::create("LowAmplitudeVal", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);
        f = IIntField::create("HighAmplitudeVal", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);
        f = IIntField::create("L1_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_GTXReady", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_IlasActive", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_TxEnabled", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_SysRefDetected", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L2_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_IlasActive", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_TxEnabled", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_SysRefDetected", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L1_SignalSelect", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("L1_data_out_mux", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("L1_test_out_mux", 4, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);
        f = IIntField::create("L2_SignalSelect", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("L2_data_out_mux", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        f = IIntField::create("L2_test_out_mux", 4, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);
        return v;
}

CJesdTxImpl::CJesdTxImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000 >> 2, LE)
{
}

