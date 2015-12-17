#ifndef _PRBSTX_H
#define _PRBSTX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IPrbsTx;
typedef shared_ptr<IPrbsTx> PrbsTx;

class CPrbsTxImpl;
typedef shared_ptr<CPrbsTxImpl> PrbsTxImpl;

class IPrbsTx : public virtual IMMIODev {
public:
        static PrbsTx create(const char *name);
};

class CPrbsTxImpl : public CMMIODevImpl, public virtual IPrbsTx {
public:
        CPrbsTxImpl(FKey);
};
#endif

