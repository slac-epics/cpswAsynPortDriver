#ifndef _JESDTX_H
#define _JESDTX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IJesdTx;
typedef shared_ptr<IJesdTx> JesdTx;

class CJesdTxImpl;
typedef shared_ptr<CJesdTxImpl> JesdTxImpl;

class IJesdTx : public virtual IMMIODev {
public:
        static JesdTx create(const char *name);
};

class CJesdTxImpl : public CMMIODevImpl, public virtual IJesdTx {
public:
        CJesdTxImpl(Key &key, const char* name);
};
#endif

