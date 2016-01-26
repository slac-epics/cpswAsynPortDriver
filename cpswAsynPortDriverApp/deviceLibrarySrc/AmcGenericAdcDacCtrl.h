#ifndef _AMCGENERICADCDACCTRL_H
#define _AMCGENERICADCDACCTRL_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAmcGenericAdcDacCtrl;
typedef shared_ptr<IAmcGenericAdcDacCtrl> AmcGenericAdcDacCtrl;

class CAmcGenericAdcDacCtrlImpl;
typedef shared_ptr<CAmcGenericAdcDacCtrlImpl> AmcGenericAdcDacCtrlImpl;

class IAmcGenericAdcDacCtrl : public virtual IMMIODev {
public:
        static AmcGenericAdcDacCtrl create(const char *name);
};

class CAmcGenericAdcDacCtrlImpl : public CMMIODevImpl, public virtual IAmcGenericAdcDacCtrl {
public:
        CAmcGenericAdcDacCtrlImpl(Key &key, const char* name);
};
#endif

