TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AmcGenericAdcDacCtrl

DBD += AmcGenericAdcDacCtrlDriverSupport.dbd

# The following are compiled and added to the Support library
AmcGenericAdcDacCtrl_SRCS += AmcGenericAdcDacCtrlDriver.cpp

AmcGenericAdcDacCtrl_LIBS += DeviceLibrary
AmcGenericAdcDacCtrl_LIBS += cpswAsynPortDriverSupport
AmcGenericAdcDacCtrl_LIBS += asyn
AmcGenericAdcDacCtrl_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


