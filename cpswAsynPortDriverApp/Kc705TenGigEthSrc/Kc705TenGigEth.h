#ifndef _KC705_H
#define _KC705_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <device_library.h>

class   IdigFpga;
typedef shared_ptr<IdigFpga> digFpga;

class CdigFpgaImpl;
typedef shared_ptr<CdigFpgaImpl> digFpgaImpl;


class IdigFpga : public virtual IMMIODev {
public:
        static digFpga create(const char *name);
};

class CdigFpgaImpl : public CMMIODevImpl, public virtual IdigFpga {
public:
        CdigFpgaImpl(FKey);
};
#endif
