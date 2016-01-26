#ifndef KCU105NORSSI_DRIVER_H
#define KCU105NORSSI_DRIVER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <device_library.h>

class   IKcu105NoRssi;
typedef shared_ptr<IKcu105NoRssi> Kcu105NoRssi;

class CKcu105NoRssiImpl;
typedef shared_ptr<CKcu105NoRssiImpl> Kcu105NoRssiImpl;


class IKcu105NoRssi : public virtual IMMIODev {
public:
        static Kcu105NoRssi create(const char *name);
};

class CKcu105NoRssiImpl : public CMMIODevImpl, public virtual IKcu105NoRssi {
public:
        CKcu105NoRssiImpl(Key &key, const char *name);
};
#endif

