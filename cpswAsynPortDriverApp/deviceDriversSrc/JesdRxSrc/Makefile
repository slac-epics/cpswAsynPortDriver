TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += JesdRx

DBD += JesdRxDriverSupport.dbd

# The following are compiled and added to the Support library
JesdRx_SRCS += JesdRxDriver.cpp

JesdRx_LIBS += DeviceLibrary
JesdRx_LIBS += cpswAsynPortDriverSupport
JesdRx_LIBS += asyn
JesdRx_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


