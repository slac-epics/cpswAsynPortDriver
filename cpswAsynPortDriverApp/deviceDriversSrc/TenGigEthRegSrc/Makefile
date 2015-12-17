TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += TenGigEthReg

DBD += TenGigEthRegDriverSupport.dbd

# The following are compiled and added to the Support library
TenGigEthReg_SRCS += TenGigEthRegDriver.cpp

TenGigEthReg_LIBS += cpsw
TenGigEthReg_LIBS += DeviceLibrary
TenGigEthReg_LIBS += cpswAsynPortDriverSupport
TenGigEthReg_LIBS += asyn
TenGigEthReg_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


