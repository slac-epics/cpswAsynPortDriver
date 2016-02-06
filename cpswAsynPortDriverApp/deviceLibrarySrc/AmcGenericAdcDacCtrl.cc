#include "AmcGenericAdcDacCtrl.h"

#define addrSize 4

AmcGenericAdcDacCtrl IAmcGenericAdcDacCtrl::create(const char *name)
{
AmcGenericAdcDacCtrlImpl v = CShObj::create<AmcGenericAdcDacCtrlImpl>(name);
Field f;
        f = IIntField::create("AdcValid0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);
        f = IIntField::create("AdcValid1", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);
        f = IIntField::create("AdcValid2", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);
        f = IIntField::create("AdcValid3", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);
        f = IIntField::create("StatusReg", 4, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);
        f = IIntField::create("Adc0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("Adc1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);
        f = IIntField::create("Adc2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);
        f = IIntField::create("Adc3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x43*addrSize);
        f = IIntField::create("Dac0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x44*addrSize);
        f = IIntField::create("Dac1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x45*addrSize);
        f = IIntField::create("DacVco", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x7E*addrSize);
        f = IIntField::create("AmcClkFreq", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x7F*addrSize);
        f = IIntField::create("LmkClkSel", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize);
        f = IIntField::create("LmkRst", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x81*addrSize);
        f = IIntField::create("lmkSync", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x82*addrSize);
        f = IIntField::create("LmkStatus", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x83*addrSize);
        f = IIntField::create("loopback", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x84*addrSize);
        f = IIntField::create("CounterReset", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0xFF*addrSize);
        f = IIntField::create("LmkMuxSel", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x85*addrSize);
        f = IIntField::create("DebugLogEn", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x86*addrSize);
        f = IIntField::create("DebugLogClr", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x87*addrSize);
        return v;
}

CAmcGenericAdcDacCtrlImpl::CAmcGenericAdcDacCtrlImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

