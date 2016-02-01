#ifndef _JESDRXDAQ_H
#define _JESDRXDAQ_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IJesdRxDaq;
typedef shared_ptr<IJesdRxDaq> JesdRxDaq;

class CJesdRxDaqImpl;
typedef shared_ptr<CJesdRxDaqImpl> JesdRxDaqImpl;

class IJesdRxDaq : public virtual IMMIODev {
public:
        static JesdRxDaq create(const char *name);
};

class CJesdRxDaqImpl : public CMMIODevImpl, public virtual IJesdRxDaq {
public:
        CJesdRxDaqImpl(Key &key, const char* name);
};
#endif

