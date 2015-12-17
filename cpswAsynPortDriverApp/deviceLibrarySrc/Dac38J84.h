#ifndef _DAC38J84_H
#define _DAC38J84_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IDac38J84;
typedef shared_ptr<IDac38J84> Dac38J84;

class CDac38J84Impl;
typedef shared_ptr<CDac38J84Impl> Dac38J84Impl;

class IDac38J84 : public virtual IMMIODev {
public:
        static Dac38J84 create(const char *name);
};

class CDac38J84Impl : public CMMIODevImpl, public virtual IDac38J84 {
public:
        CDac38J84Impl(FKey);
};
#endif

