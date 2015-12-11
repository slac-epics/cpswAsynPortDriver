#ifndef _AXI_XADC_H
#define _AXI_XADC_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiXadc
class   IAXIXadc;
typedef shared_ptr<IAXIXadc> AXIXadc;

class CAXIXadcImpl;
typedef shared_ptr<CAXIXadcImpl> AXIXadcImpl;


class IAXIXadc : public virtual IMMIODev {
public:
        static AXIXadc create(const char *name);
};

class CAXIXadcImpl : public CMMIODevImpl, public virtual IAXIXadc {
public:
        CAXIXadcImpl(FKey);
};

#endif
