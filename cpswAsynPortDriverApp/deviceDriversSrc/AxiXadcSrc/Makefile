TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AxiXadc

DBD += AxiXadcDriverSupport.dbd

# The following are compiled and added to the Support library
AxiXadc_SRCS += AxiXadcDriver.cpp

AxiXadc_LIBS += DeviceLibrary
AxiXadc_LIBS += cpswAsynPortDriverSupport
AxiXadc_LIBS += asyn
AxiXadc_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


