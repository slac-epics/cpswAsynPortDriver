TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AxiVersion

DBD += AxiVersionDriverSupport.dbd

# The following are compiled and added to the Support library
AxiVersion_SRCS += AxiVersionDriver.cpp

AxiVersion_LIBS += DeviceLibrary
AxiVersion_LIBS += cpswAsynPortDriverSupport
AxiVersion_LIBS += asyn
AxiVersion_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


