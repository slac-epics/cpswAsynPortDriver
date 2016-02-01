#ifndef _PGP2BAXI_H
#define _PGP2BAXI_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IPgp2bAxi;
typedef shared_ptr<IPgp2bAxi> Pgp2bAxi;

class CPgp2bAxiImpl;
typedef shared_ptr<CPgp2bAxiImpl> Pgp2bAxiImpl;

class IPgp2bAxi : public virtual IMMIODev {
public:
        static Pgp2bAxi create(const char *name);
};

class CPgp2bAxiImpl : public CMMIODevImpl, public virtual IPgp2bAxi {
public:
        CPgp2bAxiImpl(Key &key, const char* name);
};
#endif

