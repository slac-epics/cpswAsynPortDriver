#ifndef _AXIAD5780_H
#define _AXIAD5780_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAxiAd5780;
typedef shared_ptr<IAxiAd5780> AxiAd5780;

class CAxiAd5780Impl;
typedef shared_ptr<CAxiAd5780Impl> AxiAd5780Impl;

class IAxiAd5780 : public virtual IMMIODev {
public:
        static AxiAd5780 create(const char *name);
};

class CAxiAd5780Impl : public CMMIODevImpl, public virtual IAxiAd5780 {
public:
        CAxiAd5780Impl(Key &key, const char* name);
};
#endif

