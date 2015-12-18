TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Kcu105NoRssi
DBD += Kcu105NoRssiSupport.dbd
# The following are compiled and added to the Support library
Kcu105NoRssi_SRCS += Kcu105NoRssi.cc 
Kcu105NoRssi_LIBS += cpsw
Kcu105NoRssi_LIBS += DeviceLibrary
Kcu105NoRssi_LIBS += $(EPICS_BASE_IOC_LIBS)

INC += Kcu105NoRssi.h

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../frameworkSrc

PROD_IOC += Kcu105NoRssiApp
DBD += Kcu105NoRssiApp.dbd
Kcu105NoRssiApp_DBD += base.dbd asyn.dbd
Kcu105NoRssiApp_DBD += Kcu105NoRssiSupport.dbd
Kcu105NoRssiApp_DBD += AxiVersionDriverSupport.dbd
Kcu105NoRssiApp_DBD += TenGigEthRegDriverSupport.dbd
Kcu105NoRssiApp_DBD += PrbsTxDriverSupport.dbd

Kcu105NoRssiApp_SRCS_DEFAULT += Kcu105NoRssiApp_registerRecordDeviceDriver.cpp Kcu105NoRssiAppMain.cpp 
Kcu105NoRssiApp_LIBS += Kcu105NoRssi
Kcu105NoRssiApp_LIBS += AxiVersion
Kcu105NoRssiApp_LIBS += TenGigEthReg
Kcu105NoRssiApp_LIBS += PrbsTx
Kcu105NoRssiApp_LIBS += cpsw
Kcu105NoRssiApp_LIBS += asyn
PROD_LIBS += cpsw

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


