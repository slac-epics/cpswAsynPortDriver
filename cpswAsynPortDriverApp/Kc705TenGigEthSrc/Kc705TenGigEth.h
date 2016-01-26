#ifndef KC705TENGIGETH_DRIVER_H
#define KC705TENGIGETH_DRIVER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <device_library.h>

class   IKc705TenGigEth;
typedef shared_ptr<IKc705TenGigEth> Kc705TenGigEth;

class CKc705TenGigEthImpl;
typedef shared_ptr<CKc705TenGigEthImpl> Kc705TenGigEthImpl;


class IKc705TenGigEth : public virtual IMMIODev {
public:
        static Kc705TenGigEth create(const char *name);
};

class CKc705TenGigEthImpl : public CMMIODevImpl, public virtual IKc705TenGigEth {
public:
        CKc705TenGigEthImpl(Key &key, const char *name);
};
#endif

