#ifndef _DEVICE_LIBRARY_H
#define _DEVICE_LIBRARY_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <AxiXadc.h>
#include <AxiVersion.h>
#include <AxiCommon.h>
#include <AxiAd5780.h>
#include <AxiLtc2270.h>
#include <AxiMicronP30.h>

class   IdigFpga;
typedef shared_ptr<IdigFpga> digFpga;

class CdigFpgaImpl;
typedef shared_ptr<CdigFpgaImpl> digFpgaImpl;


class IdigFpga : public virtual IMMIODev {
public:
        static digFpga create(const char *name);
};

class CdigFpgaImpl : public CMMIODevImpl, public virtual IdigFpga {
public:
        CdigFpgaImpl(FKey);
};



class   IrootDev;
typedef shared_ptr<IrootDev> rootDev;

class CrootDevImpl;
typedef shared_ptr<CrootDevImpl> rootDevImpl;


class IrootDev : public virtual IDev {
private:
        static rootDev m_instance;
public:
	static rootDev Instance();
};

class CrootDevImpl : public CDevImpl, public virtual IrootDev {
public:
        CrootDevImpl(FKey);
};


#endif
