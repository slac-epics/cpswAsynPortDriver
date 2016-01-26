#ifndef _LMK04828_H
#define _LMK04828_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   ILmk04828;
typedef shared_ptr<ILmk04828> Lmk04828;

class CLmk04828Impl;
typedef shared_ptr<CLmk04828Impl> Lmk04828Impl;

class ILmk04828 : public virtual IMMIODev {
public:
        static Lmk04828 create(const char *name);
};

class CLmk04828Impl : public CMMIODevImpl, public virtual ILmk04828 {
public:
        CLmk04828Impl(Key &key, const char* name);
};
#endif

