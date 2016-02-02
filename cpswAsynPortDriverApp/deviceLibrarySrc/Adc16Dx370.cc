#include "Adc16Dx370.h"

#define addrSize 4

Adc16Dx370 IAdc16Dx370::create(const char *name)
{
Adc16Dx370Impl v = CShObj::create<Adc16Dx370Impl>(name);
Field f;
        f = IIntField::create("ID_DEVICE_TYPE", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x003*addrSize);
        f = IIntField::create("PD_MODE", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x002*addrSize);
        f = IIntField::create("ID_PROD_UPPER", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x004*addrSize);
        f = IIntField::create("ID_PROD_LOWER", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x005*addrSize);
        f = IIntField::create("ID_MASKREV", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x006*addrSize);
        f = IIntField::create("ID_VNDR_UPPER", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00C*addrSize);
        f = IIntField::create("ID_VNDR_LOWER", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00D*addrSize);
        f = IIntField::create("ADC_Status", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Clock_ready", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Calibration_done", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("PLL_lock", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Aligned_to_sysref", 1, false, 3);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Realigned_to_sysref", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Sync_form_FPGA", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("Link_active", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);
        f = IIntField::create("AdcReg0x0000", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0000*addrSize);
        f = IIntField::create("AdcReg0x0002", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0002*addrSize);
        f = IIntField::create("AdcReg0x0003", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0003*addrSize);
        f = IIntField::create("AdcReg0x0004", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0004*addrSize);
        f = IIntField::create("AdcReg0x0005", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0005*addrSize);
        f = IIntField::create("AdcReg0x0006", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0006*addrSize);
        f = IIntField::create("AdcReg0x000c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x000c*addrSize);
        f = IIntField::create("AdcReg0x000d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x000d*addrSize);
        f = IIntField::create("AdcReg0x000e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x000e*addrSize);
        f = IIntField::create("AdcReg0x000f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x000f*addrSize);
        f = IIntField::create("AdcReg0x0010", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0010*addrSize);
        f = IIntField::create("AdcReg0x0011", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0011*addrSize);
        f = IIntField::create("AdcReg0x0012", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0012*addrSize);
        f = IIntField::create("AdcReg0x0013", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0013*addrSize);
        f = IIntField::create("AdcReg0x0014", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0014*addrSize);
        f = IIntField::create("AdcReg0x0015", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0015*addrSize);
        f = IIntField::create("AdcReg0x0019", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0019*addrSize);
        f = IIntField::create("AdcReg0x003b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x003b*addrSize);
        f = IIntField::create("AdcReg0x003c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x003c*addrSize);
        f = IIntField::create("AdcReg0x003d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x003d*addrSize);
        f = IIntField::create("AdcReg0x0047", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0047*addrSize);
        f = IIntField::create("AdcReg0x0060", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0060*addrSize);
        f = IIntField::create("AdcReg0x0061", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0061*addrSize);
        f = IIntField::create("AdcReg0x0062", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0062*addrSize);
        f = IIntField::create("AdcReg0x0063", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0063*addrSize);
        f = IIntField::create("AdcReg0x0070", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0070*addrSize);
        return v;
}

CAdc16Dx370Impl::CAdc16Dx370Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

