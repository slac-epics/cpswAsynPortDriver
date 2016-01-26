#ifndef _AXIVERSION_H
#define _AXIVERSION_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAxiVersion;
typedef shared_ptr<IAxiVersion> AxiVersion;

class CAxiVersionImpl;
typedef shared_ptr<CAxiVersionImpl> AxiVersionImpl;

class IAxiVersion : public virtual IMMIODev {
public:
        static AxiVersion create(const char *name);
};

class CAxiVersionImpl : public CMMIODevImpl, public virtual IAxiVersion {
public:
        CAxiVersionImpl(Key &key, const char* name);
};
#endif

