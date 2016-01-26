TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += PrbsTx

DBD += PrbsTxDriverSupport.dbd

# The following are compiled and added to the Support library
PrbsTx_SRCS += PrbsTxDriver.cpp

PrbsTx_LIBS += DeviceLibrary
PrbsTx_LIBS += cpswAsynPortDriverSupport
PrbsTx_LIBS += asyn
PrbsTx_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


