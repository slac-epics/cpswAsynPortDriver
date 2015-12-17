#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "JesdRx.h"

#define addrSize 4

JesdRx IJesdRx::create(const char *name)
{
JesdRxImpl v = CEntryImpl::create<JesdRxImpl::element_type>(name);
Field f;
        f = IIntField::create("Enable", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("SysrefDelay", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("CommonControl", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("SubClass", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("ReplaceEnable", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("ResetGTs", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("ClearErrors", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("InvertSync", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);
        f = IIntField::create("L1_Test_thr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);
        f = IIntField::create("L1_Threshold_Low", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);
        f = IIntField::create("L1_Threshold_High", 16, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);
        f = IIntField::create("L2_Test_thr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);
        f = IIntField::create("L2_Threshold_Low", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);
        f = IIntField::create("L2_Threshold_High", 16, false, 16);
        v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);
        f = IIntField::create("L1_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_GTXReady", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L1_ElBuffLatency", 8, false, 18);
        v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);
        f = IIntField::create("L2_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L2_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);
        f = IIntField::create("L3_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L3_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);
        f = IIntField::create("L4_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L4_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);
        f = IIntField::create("L5_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L5_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);
        f = IIntField::create("L6_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_GTXRdy", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_DataValid", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_AlignErr", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_nSync", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_RxBuffUfl", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_RxBuffOfl", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_PositionErr", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_RxEnabled", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_SysRefDetected", 1, false, 8);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_CommaDetected", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_DisparityErr", 4, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        f = IIntField::create("L6_DecErr", 4, false, 14);
        v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);
        return v;
}

CJesdRxImpl::CJesdRxImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

