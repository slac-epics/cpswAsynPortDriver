#include "AmcGenericAdcDacCtrl.h"

#define addrSize 4

AmcGenericAdcDacCtrl IAmcGenericAdcDacCtrl::create(const char *name)
{
AmcGenericAdcDacCtrlImpl v = CShObj::create<AmcGenericAdcDacCtrlImpl>(name);
Field f;
        f = IIntField::create("Adc0_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);
        f = IIntField::create("Adc0_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);
        f = IIntField::create("Adc0_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);
        f = IIntField::create("Adc0_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x43*addrSize);
        f = IIntField::create("Adc1_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x44*addrSize);
        f = IIntField::create("Adc1_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x45*addrSize);
        f = IIntField::create("Adc1_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x46*addrSize);
        f = IIntField::create("Adc1_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x47*addrSize);
        f = IIntField::create("Adc2_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x48*addrSize);
        f = IIntField::create("Adc2_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x49*addrSize);
        f = IIntField::create("Adc2_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4A*addrSize);
        f = IIntField::create("Adc2_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4B*addrSize);
        f = IIntField::create("Adc3_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4C*addrSize);
        f = IIntField::create("Adc3_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4D*addrSize);
        f = IIntField::create("Adc3_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4E*addrSize);
        f = IIntField::create("Adc3_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x4F*addrSize);
        f = IIntField::create("Dac0_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x50*addrSize);
        f = IIntField::create("Dac0_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x51*addrSize);
        f = IIntField::create("Dac0_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x52*addrSize);
        f = IIntField::create("Dac0_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x53*addrSize);
        f = IIntField::create("Dac1_t0", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x54*addrSize);
        f = IIntField::create("Dac1_t1", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x55*addrSize);
        f = IIntField::create("Dac1_t2", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x56*addrSize);
        f = IIntField::create("Dac1_t3", 16, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x57*addrSize);
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
        return v;
}

CAmcGenericAdcDacCtrlImpl::CAmcGenericAdcDacCtrlImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000 >> 2, LE)
{
}

