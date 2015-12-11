#ifndef _AXI_AD_5780_H
#define _AXI_AD_5780_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

class   IAXIAd5780;
typedef shared_ptr<IAXIAd5780> AXIAd5780;

class CAXIAd5780Impl;
typedef shared_ptr<CAXIAd5780Impl> AXIAd5780Impl;


class IAXIAd5780 : public virtual IMMIODev {
public:
        static AXIAd5780 create(const char *name);
};

class CAXIAd5780Impl : public CMMIODevImpl, public virtual IAXIAd5780 {
public:
        CAXIAd5780Impl(FKey);
};
#endif
