#ifndef _DEVICE_LIBRARY_H
#define _DEVICE_LIBRARY_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>
#include <AxiXadc.h>
#include <AxiVersion.h>
#include <AxiCommon.h>
#include <AxiAd5780.h>
#include <AxiLtc2270.h>
#include <AxiMicronP30.h>
#include <PrbsTx.h>
#include <TenGigEthReg.h>
#include <Adc16Dx370.h>
#include <AmcGenericAdcDacCtrl.h>
#include <Dac38J84.h>
#include <JesdTx.h>
#include <JesdRx.h>
#include <Lmk04828.h>

class   IrootDev;
typedef shared_ptr<IrootDev> rootDev;

class CrootDevImpl;
typedef shared_ptr<CrootDevImpl> rootDevImpl;


class IrootDev : public virtual IDev {
private:
        static rootDev m_instance;
public:
	static rootDev Instance();
};

class CrootDevImpl : public CDevImpl, public virtual IrootDev {
public:
        CrootDevImpl(FKey);
};


#endif
