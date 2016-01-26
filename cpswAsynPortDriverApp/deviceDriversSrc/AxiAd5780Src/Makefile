TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AxiAd5780

DBD += AxiAd5780DriverSupport.dbd

# The following are compiled and added to the Support library
AxiAd5780_SRCS += AxiAd5780Driver.cpp

AxiAd5780_LIBS += DeviceLibrary
AxiAd5780_LIBS += cpswAsynPortDriverSupport
AxiAd5780_LIBS += asyn
AxiAd5780_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


