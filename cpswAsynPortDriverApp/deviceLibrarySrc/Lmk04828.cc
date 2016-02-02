#include "Lmk04828.h"

#define addrSize 4

Lmk04828 ILmk04828::create(const char *name)
{
Lmk04828Impl v = CShObj::create<Lmk04828Impl>(name);
Field f;
        f = IIntField::create("ID_DEVICE_TYPE", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x003*addrSize);
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
        f = IIntField::create("SYS_REF_MUX", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x139*addrSize);
        f = IIntField::create("SYNC_MODE", 2, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x143*addrSize);
        f = IIntField::create("SYNC_EN", 1, false, 4);
        v->CMMIODevImpl::addAtAddress( f , 0x143*addrSize);
        f = IIntField::create("SYNC_DIS", 8, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x144*addrSize);
        f = IIntField::create("LmkReg0x0100", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0100*addrSize);
        f = IIntField::create("LmkReg0x0101", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0101*addrSize);
        f = IIntField::create("LmkReg0x0103", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0103*addrSize);
        f = IIntField::create("LmkReg0x0104", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0104*addrSize);
        f = IIntField::create("LmkReg0x0105", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0105*addrSize);
        f = IIntField::create("LmkReg0x0106", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0106*addrSize);
        f = IIntField::create("LmkReg0x0107", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0107*addrSize);
        f = IIntField::create("LmkReg0x0108", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0108*addrSize);
        f = IIntField::create("LmkReg0x0109", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0109*addrSize);
        f = IIntField::create("LmkReg0x010b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x010b*addrSize);
        f = IIntField::create("LmkReg0x010c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x010c*addrSize);
        f = IIntField::create("LmkReg0x010d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x010d*addrSize);
        f = IIntField::create("LmkReg0x010e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x010e*addrSize);
        f = IIntField::create("LmkReg0x010f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x010f*addrSize);
        f = IIntField::create("LmkReg0x0110", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0110*addrSize);
        f = IIntField::create("LmkReg0x0111", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0111*addrSize);
        f = IIntField::create("LmkReg0x0113", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0113*addrSize);
        f = IIntField::create("LmkReg0x0114", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0114*addrSize);
        f = IIntField::create("LmkReg0x0115", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0115*addrSize);
        f = IIntField::create("LmkReg0x0116", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0116*addrSize);
        f = IIntField::create("LmkReg0x0117", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0117*addrSize);
        f = IIntField::create("LmkReg0x0118", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0118*addrSize);
        f = IIntField::create("LmkReg0x0119", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0119*addrSize);
        f = IIntField::create("LmkReg0x011a", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011a*addrSize);
        f = IIntField::create("LmkReg0x011b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011b*addrSize);
        f = IIntField::create("LmkReg0x011c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011c*addrSize);
        f = IIntField::create("LmkReg0x011d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011d*addrSize);
        f = IIntField::create("LmkReg0x011e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011e*addrSize);
        f = IIntField::create("LmkReg0x011f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x011f*addrSize);
        f = IIntField::create("LmkReg0x0120", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0120*addrSize);
        f = IIntField::create("LmkReg0x0121", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0121*addrSize);
        f = IIntField::create("LmkReg0x0123", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0123*addrSize);
        f = IIntField::create("LmkReg0x0124", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0124*addrSize);
        f = IIntField::create("LmkReg0x0125", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0125*addrSize);
        f = IIntField::create("LmkReg0x0126", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0126*addrSize);
        f = IIntField::create("LmkReg0x0127", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0127*addrSize);
        f = IIntField::create("LmkReg0x0128", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0128*addrSize);
        f = IIntField::create("LmkReg0x0129", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0129*addrSize);
        f = IIntField::create("LmkReg0x012b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x012b*addrSize);
        f = IIntField::create("LmkReg0x012c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x012c*addrSize);
        f = IIntField::create("LmkReg0x012d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x012d*addrSize);
        f = IIntField::create("LmkReg0x012e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x012e*addrSize);
        f = IIntField::create("LmkReg0x012f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x012f*addrSize);
        f = IIntField::create("LmkReg0x0130", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0130*addrSize);
        f = IIntField::create("LmkReg0x0131", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0131*addrSize);
        f = IIntField::create("LmkReg0x0133", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0133*addrSize);
        f = IIntField::create("LmkReg0x0134", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0134*addrSize);
        f = IIntField::create("LmkReg0x0135", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0135*addrSize);
        f = IIntField::create("LmkReg0x0136", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0136*addrSize);
        f = IIntField::create("LmkReg0x0137", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0137*addrSize);
        f = IIntField::create("LmkReg0x0138", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0138*addrSize);
        f = IIntField::create("LmkReg0x0139", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0139*addrSize);
        f = IIntField::create("LmkReg0x013a", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013a*addrSize);
        f = IIntField::create("LmkReg0x013b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013b*addrSize);
        f = IIntField::create("LmkReg0x013c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013c*addrSize);
        f = IIntField::create("LmkReg0x013d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013d*addrSize);
        f = IIntField::create("LmkReg0x013e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013e*addrSize);
        f = IIntField::create("LmkReg0x013f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x013f*addrSize);
        f = IIntField::create("LmkReg0x0140", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0140*addrSize);
        f = IIntField::create("LmkReg0x0141", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0141*addrSize);
        f = IIntField::create("LmkReg0x0142", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0142*addrSize);
        f = IIntField::create("LmkReg0x0143", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0143*addrSize);
        f = IIntField::create("LmkReg0x0144", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0144*addrSize);
        f = IIntField::create("LmkReg0x0145", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0145*addrSize);
        f = IIntField::create("LmkReg0x0146", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0146*addrSize);
        f = IIntField::create("LmkReg0x0147", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0147*addrSize);
        f = IIntField::create("LmkReg0x0148", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0148*addrSize);
        f = IIntField::create("LmkReg0x0149", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0149*addrSize);
        f = IIntField::create("LmkReg0x014a", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014a*addrSize);
        f = IIntField::create("LmkReg0x014b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014b*addrSize);
        f = IIntField::create("LmkReg0x014c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014c*addrSize);
        f = IIntField::create("LmkReg0x014d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014d*addrSize);
        f = IIntField::create("LmkReg0x014e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014e*addrSize);
        f = IIntField::create("LmkReg0x014f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x014f*addrSize);
        f = IIntField::create("LmkReg0x0150", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0150*addrSize);
        f = IIntField::create("LmkReg0x0151", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0151*addrSize);
        f = IIntField::create("LmkReg0x0152", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0152*addrSize);
        f = IIntField::create("LmkReg0x0153", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0153*addrSize);
        f = IIntField::create("LmkReg0x0154", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0154*addrSize);
        f = IIntField::create("LmkReg0x0155", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0155*addrSize);
        f = IIntField::create("LmkReg0x0156", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0156*addrSize);
        f = IIntField::create("LmkReg0x0157", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0157*addrSize);
        f = IIntField::create("LmkReg0x0158", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0158*addrSize);
        f = IIntField::create("LmkReg0x0159", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0159*addrSize);
        f = IIntField::create("LmkReg0x015a", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015a*addrSize);
        f = IIntField::create("LmkReg0x015b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015b*addrSize);
        f = IIntField::create("LmkReg0x015c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015c*addrSize);
        f = IIntField::create("LmkReg0x015d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015d*addrSize);
        f = IIntField::create("LmkReg0x015e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015e*addrSize);
        f = IIntField::create("LmkReg0x015f", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x015f*addrSize);
        f = IIntField::create("LmkReg0x0160", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0160*addrSize);
        f = IIntField::create("LmkReg0x0161", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0161*addrSize);
        f = IIntField::create("LmkReg0x0162", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0162*addrSize);
        f = IIntField::create("LmkReg0x0163", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0163*addrSize);
        f = IIntField::create("LmkReg0x0164", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0164*addrSize);
        f = IIntField::create("LmkReg0x0165", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0165*addrSize);
        f = IIntField::create("LmkReg0x0166", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0166*addrSize);
        f = IIntField::create("LmkReg0x0167", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0167*addrSize);
        f = IIntField::create("LmkReg0x0168", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0168*addrSize);
        f = IIntField::create("LmkReg0x0169", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0169*addrSize);
        f = IIntField::create("LmkReg0x016a", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x016a*addrSize);
        f = IIntField::create("LmkReg0x016b", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x016b*addrSize);
        f = IIntField::create("LmkReg0x016c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x016c*addrSize);
        f = IIntField::create("LmkReg0x016d", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x016d*addrSize);
        f = IIntField::create("LmkReg0x016e", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x016e*addrSize);
        f = IIntField::create("LmkReg0x0173", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0173*addrSize);
        f = IIntField::create("LmkReg0x0174", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x0174*addrSize);
        f = IIntField::create("LmkReg0x017c", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x017c*addrSize);
        return v;
}

CLmk04828Impl::CLmk04828Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}

