#ifndef _ADC16DX370_H
#define _ADC16DX370_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAdc16Dx370;
typedef shared_ptr<IAdc16Dx370> Adc16Dx370;

class CAdc16Dx370Impl;
typedef shared_ptr<CAdc16Dx370Impl> Adc16Dx370Impl;

class IAdc16Dx370 : public virtual IMMIODev {
public:
        static Adc16Dx370 create(const char *name);
};

class CAdc16Dx370Impl : public CMMIODevImpl, public virtual IAdc16Dx370 {
public:
        CAdc16Dx370Impl(Key &key, const char* name);
};
#endif

