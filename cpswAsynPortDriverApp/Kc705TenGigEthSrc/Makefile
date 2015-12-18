TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Kc705TenGigEth
DBD += Kc705TenGigEthSupport.dbd
# The following are compiled and added to the Support library
Kc705TenGigEth_SRCS += Kc705TenGigEth.cc 
Kc705TenGigEth_LIBS += cpsw
Kc705TenGigEth_LIBS += DeviceLibrary
Kc705TenGigEth_LIBS += $(EPICS_BASE_IOC_LIBS)

INC += Kc705TenGigEth.h

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../frameworkSrc

PROD_IOC += Kc705TenGigEthApp
DBD += Kc705TenGigEthApp.dbd
Kc705TenGigEthApp_DBD += base.dbd asyn.dbd
Kc705TenGigEthApp_DBD += Kc705TenGigEthSupport.dbd
Kc705TenGigEthApp_DBD += AxiVersionDriverSupport.dbd
Kc705TenGigEthApp_DBD += AxiXadcDriverSupport.dbd

Kc705TenGigEthApp_SRCS_DEFAULT += Kc705TenGigEthApp_registerRecordDeviceDriver.cpp Kc705TenGigEthAppMain.cpp 
Kc705TenGigEthApp_LIBS += Kc705TenGigEth
Kc705TenGigEthApp_LIBS += AxiVersion
Kc705TenGigEthApp_LIBS += AxiXadc
Kc705TenGigEthApp_LIBS += cpsw
Kc705TenGigEthApp_LIBS += asyn
PROD_LIBS += cpsw

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


