TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += JesdTx

DBD += JesdTxDriverSupport.dbd

# The following are compiled and added to the Support library
JesdTx_SRCS += JesdTxDriver.cpp

JesdTx_LIBS += DeviceLibrary
JesdTx_LIBS += cpswAsynPortDriverSupport
JesdTx_LIBS += asyn
JesdTx_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += -I/afs/slac/g/lcls/package/cpsw/framework
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


