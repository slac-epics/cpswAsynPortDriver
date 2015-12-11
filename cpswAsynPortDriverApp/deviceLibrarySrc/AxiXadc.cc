#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiXadc.h"

#define addrSize 0x04

#define ENABLE_AxiXadc_CONFIG false

AXIXadc IAXIXadc::create(const char *name)
{
AXIXadcImpl v = CEntryImpl::create<AXIXadcImpl::element_type>(name);
Field f;
std::stringstream tmp;
        f = IIntField::create("Temperature", 24, false, 4);  // this is the same as ( REG>>4 ) | 0xFFF
        v->CMMIODevImpl::addAtAddress( f , ( 0x200 >> 2 )*addrSize );
        f = IIntField::create("VccInt", 24, false,  4);
        v->CMMIODevImpl::addAtAddress( f,   ( 0x204 >> 2 )*addrSize );
        f = IIntField::create("VccAux", 24, false, 4);
        v->CMMIODevImpl::addAtAddress( f , ( 0x208 >> 2 )*addrSize );
        f = IIntField::create("Vin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , ( 0x20C >> 2 )*addrSize );
        f = IIntField::create("VrefP", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x210 >> 2 )*addrSize );
        f = IIntField::create("VrefN", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x214 >> 2 )*addrSize );
        f = IIntField::create("VccBram", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x218 >> 2 )*addrSize );
        f = IIntField::create("SupplyOffsetA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x220 >> 2 )*addrSize );
        f = IIntField::create("AdcOffsetA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x224 >> 2 )*addrSize );
        f = IIntField::create("AdcGainA", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x228 >> 2 )*addrSize );
        f = IIntField::create("VccpInt", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x234 >> 2 )*addrSize );
        f = IIntField::create("VccpAux", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x238 >> 2 )*addrSize );
        f = IIntField::create("VccpDdr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x23C >> 2 )*addrSize );
	for ( int i = 0; i < 16; i++ ) { //0x10:0x1F 0x240:0x27C
		tmp.str("");
		tmp << "VinAux" << std::dec << std::setw(2) << std::setfill('0') << i;// VauxP/VauxN[15:0]
        	f = IIntField::create( (const char*) tmp.str().c_str(), 32, false, 0);
	        v->CMMIODevImpl::addAtAddress( f, ( ( i*4 + 0x240 ) >> 2 )*addrSize );	
	}
        f = IIntField::create("TemperatureMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x280 >> 2 )*addrSize );
        f = IIntField::create("VccIntMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x284 >> 2 )*addrSize );
        f = IIntField::create("VccAuxMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x288 >> 2 )*addrSize );
        f = IIntField::create("VccBramMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x28C >> 2 )*addrSize   );
        f = IIntField::create("TemperatureMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x290 >> 2 )*addrSize  );
        f = IIntField::create("VccIntMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x294 >> 2 )*addrSize  );
        f = IIntField::create("VccAuxMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x298 >> 2 )*addrSize  );
        f = IIntField::create("VccBramMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x29C >> 2 )*addrSize  );
        f = IIntField::create("VccpIntMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2A0 >> 2 )*addrSize  );
	f = IIntField::create("VccpAuxMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2A4 >> 2 )*addrSize  );
	f = IIntField::create("VccpDdrMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2A8 >> 2 )*addrSize  );
	
	//0x2AC is undefined
	
	f = IIntField::create("VccpIntMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2B0 >> 2 )*addrSize  );
	f = IIntField::create("VccpAuxMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2B4 >> 2 )*addrSize  );
	f = IIntField::create("VccpDdrMin", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2B8 >> 2 )*addrSize  );
	f = IIntField::create("Flag", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );

/* Individual bits of flag */
        f = IIntField::create("Flag_JTGD", 1, false, 11)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_JTGR", 1, false, 10)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_REF", 1, false, 9)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccDdr", 1, false, 7)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccAux", 1, false, 6)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccpInt", 1, false, 5)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccBram", 1, false, 4)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccBram", 1, false, 3)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccAux", 1, false, 2)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_VccInt", 1, false, 1)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );
        f = IIntField::create("Flag_Temperature", 1, false, 0)
        v->CMMIODevImpl::addAtAddress( f, ( 0x2FC >> 2 )*addrSize  );

	
#if ENABLE_AxiXadc_CONFIG
	for (int i = 0; i < 8; i++ ) {
	 tmp.str("");
	 tmp << "INIT_" << hex << uppercase << std::setw(1) << std::setfill('0') << (i + 0x48);// Sequence Registers[7:0]
	 f = IIntField::create( (const char*) tmp.str().c_str(), 32, false, 0);
	 v->CMMIODevImpl::addAtAddress( f, ( ( i*4 + 0x320 ) >> 2 )*addrSize  );	
	}
	for (int i = 0; i < 16; i++ ) {
	 tmp.str("");
	 tmp << "INIT_" << hex << uppercase << std::setw(1) << std::setfill('0') << (i + 0x50);// Alarm Registers[15:0]
	 f = IIntField::create( (const char*) tmp.str().c_str(), 32, false, 0);
	 v->CMMIODevImpl::addAtAddress( f, ( ( i*4 + 0x340 ) >> 2 )*addrSize  );	
	}
	f = IIntField::create("VccpIntMax", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, ( 0x2A0 >> 2 )*addrSize  );
#endif
	
        return v;
}

CAXIXadcImpl::CAXIXadcImpl(FKey key) : CMMIODevImpl(key, 0x00010000 >> 2, LE)
{
}
