TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Dac38J84

DBD += Dac38J84DriverSupport.dbd

# The following are compiled and added to the Support library
Dac38J84_SRCS += Dac38J84Driver.cpp

Dac38J84_LIBS += DeviceLibrary
Dac38J84_LIBS += cpswAsynPortDriverSupport
Dac38J84_LIBS += asyn
Dac38J84_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


