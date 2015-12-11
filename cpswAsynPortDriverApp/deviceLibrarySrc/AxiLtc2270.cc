#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiLtc2270.h"

#define addrSize 4

AXILtc2270 IAXILtc2270::create(const char *name)
{
AXILtc2270Impl v = CEntryImpl::create<AXILtc2270Impl::element_type>(name);
Field f;
std::stringstream tmp;
        f = IIntField::create("Reg00", false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00 );
        f = IIntField::create("Reg01", 32, false,  0);
        v->CMMIODevImpl::addAtAddress( f,   0x01 );
        f = IIntField::create("Reg02", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02 );
        f = IIntField::create("Reg03", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03 );
        f = IIntField::create("Reg04", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x04 );
	for ( int i = 0; i < 2; i++ ) {
		for (int j = 0; j < 8; j++ ) {
			tmp.str("");
			tmp << "adcData_"  << std::dec << i << "_" << j; 
        		f = IIntField::create((const char*) tmp.str().c_str(), 32, false, 0);
		        v->CMMIODevImpl::addAtAddress( f, ( 0x60 + ( 8*i ) + j ) );
			tmp.str("");
			tmp << "delayOut_data_"  << std::dec << i << "_" << j; 
        		f = IIntField::create((const char*) tmp.str().c_str(), 32, false, 0);
		        v->CMMIODevImpl::addAtAddress( f, ( 0x80 + ( 8*i ) + j ) );
		}
	}
	f = IIntField::create("delayOut_rdy", 32, false, 0);
	v->CMMIODevImpl::addAtAddress( f, 0x7F );
        f = IIntField::create("dmode", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x90 );
        f = IIntField::create("debug", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xA0 );

        return v;
}

CAXILtc2270Impl::CAXILtc2270Impl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}
