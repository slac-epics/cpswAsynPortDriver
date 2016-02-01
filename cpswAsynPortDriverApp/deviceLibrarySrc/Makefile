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
DeviceLibrary_SRCS += Adc16Dx370.cc            AxiAd5780.cc  AxiLtc2270.cc    AxiVersion.cc  Dac38J84.cc  JesdTx.cc    PrbsTx.cc
DeviceLibrary_SRCS += AmcGenericAdcDacCtrl.cc  AxiCommon.cc  AxiMicronP30.cc  AxiXadc.cc     JesdRx.cc    Lmk04828.cc  TenGigEthReg.cc 
DeviceLibrary_SRCS += Pgp2bAxi.cc JesdRxDaq.cc
#DeviceLibrary_SRCS = $(wildcard ../*.cc)

INC += Adc16Dx370.h  AmcGenericAdcDacCtrl.h  AxiAd5780.h  AxiCommon.h  AxiLtc2270.h  AxiMicronP30.h  AxiVersion.h  AxiXadc.h  
INC += Dac38J84.h  JesdRx.h  JesdTx.h  Lmk04828.h  PrbsTx.h  TenGigEthReg.h  device_library.h
INC += Pgp2bAxi.h JesdRxDaq.h
#INC += $(wildcard ../*.h)

USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

