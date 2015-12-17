#ifndef _JESDRX_H
#define _JESDRX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IJesdRx;
typedef shared_ptr<IJesdRx> JesdRx;

class CJesdRxImpl;
typedef shared_ptr<CJesdRxImpl> JesdRxImpl;

class IJesdRx : public virtual IMMIODev {
public:
        static JesdRx create(const char *name);
};

class CJesdRxImpl : public CMMIODevImpl, public virtual IJesdRx {
public:
        CJesdRxImpl(FKey);
};
#endif

