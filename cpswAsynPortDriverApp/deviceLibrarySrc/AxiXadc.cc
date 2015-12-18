#include "AxiXadc.h"

#define addrSize 4

AxiXadc IAxiXadc::create(const char *name)
{
AxiXadcImpl v = CEntryImpl::create<AxiXadcImpl::element_type>(name);
Field f;
        f = IIntField::create("Temperature", 24, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x200*addrSize);
        f = IIntField::create("VccInt", 24, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x204*addrSize);
        f = IIntField::create("VccAux", 24, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x208*addrSize);
        f = IIntField::create("VrefP", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x210*addrSize);
        f = IIntField::create("VrefN", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x214*addrSize);
        f = IIntField::create("VccBram", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x218*addrSize);
        f = IIntField::create("SupplyOffsetA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x220*addrSize);
        f = IIntField::create("AdcOffsetA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x224*addrSize);
        f = IIntField::create("AdcGainA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x228*addrSize);
        f = IIntField::create("VccpInt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x234*addrSize);
        f = IIntField::create("VccpAux", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x238*addrSize);
        f = IIntField::create("VccpDdr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x23C*addrSize);
        f = IIntField::create("VinAux_0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x240*addrSize);
        f = IIntField::create("VinAux01", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x244*addrSize);
        f = IIntField::create("VinAux02", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x248*addrSize);
        f = IIntField::create("VinAux03", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x24C*addrSize);
        f = IIntField::create("VinAux04", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x250*addrSize);
        f = IIntField::create("VinAux05", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x254*addrSize);
        f = IIntField::create("VinAux06", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x258*addrSize);
        f = IIntField::create("VinAux07", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x25C*addrSize);
        f = IIntField::create("VinAux08", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x260*addrSize);
        f = IIntField::create("VinAux09", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x264*addrSize);
        f = IIntField::create("VinAux10", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x268*addrSize);
        f = IIntField::create("VinAux11", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x26C*addrSize);
        f = IIntField::create("VinAux12", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x270*addrSize);
        f = IIntField::create("VinAux13", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x274*addrSize);
        f = IIntField::create("VinAux14", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x278*addrSize);
        f = IIntField::create("VinAux15", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x27C*addrSize);
        f = IIntField::create("TemperatureMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x280*addrSize);
        f = IIntField::create("VccIntMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x288*addrSize);
        f = IIntField::create("VccAuxMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x284*addrSize);
        f = IIntField::create("VccBramMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x28C*addrSize);
        f = IIntField::create("TemperatureMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x290*addrSize);
        f = IIntField::create("VccIntMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x294*addrSize);
        f = IIntField::create("VccAuxMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x298*addrSize);
        f = IIntField::create("VccBramMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x29C*addrSize);
        f = IIntField::create("VccpIntMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2A0*addrSize);
        f = IIntField::create("VccpAuxMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2A4*addrSize);
        f = IIntField::create("VccpDdrMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2A8*addrSize);
        f = IIntField::create("VccpIntMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2B0*addrSize);
        f = IIntField::create("VccpAuxMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2B4*addrSize);
        f = IIntField::create("VccpDdrMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2B8*addrSize);
        f = IIntField::create("Flag", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_JTGD", 1, false, 11);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_JTGR", 1, false, 10);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_REF", 1, false, 9);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccpDdr", 1, false, 7);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccpAux", 1, false, 6);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccpInt", 1, false, 5);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccBram", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccAux", 1, false, 2);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_VccInt", 1, false, 1);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        f = IIntField::create("Flag_Temperature", 1, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);
        return v;
}

CAxiXadcImpl::CAxiXadcImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}

