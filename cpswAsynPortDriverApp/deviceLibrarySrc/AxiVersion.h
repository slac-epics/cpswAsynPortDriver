#ifndef _AXI_VERSION_H
#define _AXI_VERSION_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAXIVers;
typedef shared_ptr<IAXIVers> AXIVers;

class CAXIVersImpl;
typedef shared_ptr<CAXIVersImpl> AXIVersImpl;

class IAXIVers : public virtual IMMIODev {
public:
        static AXIVers create(const char *name);
};

class CAXIVersImpl : public CMMIODevImpl, public virtual IAXIVers {
public:
        CAXIVersImpl(FKey);
};
#endif
