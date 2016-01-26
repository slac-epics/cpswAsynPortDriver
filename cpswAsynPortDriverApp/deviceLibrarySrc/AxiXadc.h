#ifndef _AXIXADC_H
#define _AXIXADC_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAxiXadc;
typedef shared_ptr<IAxiXadc> AxiXadc;

class CAxiXadcImpl;
typedef shared_ptr<CAxiXadcImpl> AxiXadcImpl;

class IAxiXadc : public virtual IMMIODev {
public:
        static AxiXadc create(const char *name);
};

class CAxiXadcImpl : public CMMIODevImpl, public virtual IAxiXadc {
public:
        CAxiXadcImpl(Key &key, const char* name);
};
#endif

