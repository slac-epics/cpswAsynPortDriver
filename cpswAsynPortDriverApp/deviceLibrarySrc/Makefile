TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += DeviceLibrary

# motorRecord.h will be created from motorRecord.dbd
# install devMotorSoft.dbd into <top>/dbd
#DBD += DeviceLibrary.dbd

# The following are compiled and added to the Support library
#DeviceLibrary_SRCS += device_library.cc AxiAd5780.cc  AxiCommon.cc  AxiLtc2270.cc  AxiMicronP30.cc  AxiVersion.cc  AxiXadc.cc PrbsTx.cc TenGigEthReg.cc
DeviceLibrary_SRCS += $(wildcard ../*.cc)
DeviceLibrary_LIBS += cpsw
DeviceLibrary_LIBS += $(EPICS_BASE_IOC_LIBS)

#INC += device_library.h AxiAd5780.h  AxiCommon.h  AxiLtc2270.h  AxiMicronP30.h  AxiVersion.h  AxiXadc.h PrbsTx.h TenGigEthReg.h
INC += $(wildcard ../*.h)

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../frameworkSrc

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

