TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += JesdRxDaq

DBD += JesdRxDaqDriverSupport.dbd

# The following are compiled and added to the Support library
JesdRxDaq_SRCS += JesdRxDaqDriver.cpp

JesdRxDaq_LIBS += DeviceLibrary
JesdRxDaq_LIBS += cpswAsynPortDriverSupport
JesdRxDaq_LIBS += asyn
JesdRxDaq_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


