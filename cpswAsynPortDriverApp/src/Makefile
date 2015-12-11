TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

DBD += cpswAsynPortDriverInclude.dbd

LIBRARY_IOC += cpswAsynPortDriverSupport
cpswAsynPortDriverSupport_SRCS += cpswAsynPortDriver.cpp
cpswAsynPortDriverSupport_LIBS += cpsw
cpswAsynPortDriverSupport_LIBS += asyn
cpswAsynPortDriverSupport_LIBS += $(EPICS_BASE_IOC_LIBS)
PROD_LIBS += cpsw
INC += cpswAsynPortDriver.h
USR_INCLUDES += ../../frameworkSrc
#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
