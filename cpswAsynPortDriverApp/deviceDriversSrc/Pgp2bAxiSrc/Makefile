TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Pgp2bAxi

DBD += Pgp2bAxiDriverSupport.dbd

# The following are compiled and added to the Support library
Pgp2bAxi_SRCS += Pgp2bAxiDriver.cpp

Pgp2bAxi_LIBS += DeviceLibrary
Pgp2bAxi_LIBS += cpswAsynPortDriverSupport
Pgp2bAxi_LIBS += asyn
Pgp2bAxi_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


