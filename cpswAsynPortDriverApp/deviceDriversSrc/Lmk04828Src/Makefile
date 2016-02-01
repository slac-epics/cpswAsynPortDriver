TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Lmk04828

DBD += Lmk04828DriverSupport.dbd

# The following are compiled and added to the Support library
Lmk04828_SRCS += Lmk04828Driver.cpp

Lmk04828_LIBS += DeviceLibrary
Lmk04828_LIBS += cpswAsynPortDriverSupport
Lmk04828_LIBS += asyn
Lmk04828_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


