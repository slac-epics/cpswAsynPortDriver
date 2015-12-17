#ifndef _TENGIGETHREG_H
#define _TENGIGETHREG_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   ITenGigEthReg;
typedef shared_ptr<ITenGigEthReg> TenGigEthReg;

class CTenGigEthRegImpl;
typedef shared_ptr<CTenGigEthRegImpl> TenGigEthRegImpl;

class ITenGigEthReg : public virtual IMMIODev {
public:
        static TenGigEthReg create(const char *name);
};

class CTenGigEthRegImpl : public CMMIODevImpl, public virtual ITenGigEthReg {
public:
        CTenGigEthRegImpl(FKey);
};
#endif

