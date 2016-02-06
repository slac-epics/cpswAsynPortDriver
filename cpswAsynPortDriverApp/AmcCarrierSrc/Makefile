TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AmcCarrier
DBD += AmcCarrierSupport.dbd
# The following are compiled and added to the Support library
AmcCarrier_SRCS += AmcGenericAdcDac.cc 
AmcCarrier_SRCS += AmcCarrier.cc 
AmcCarrier_LIBS += DeviceLibrary
AmcCarrier_LIBS += $(EPICS_BASE_IOC_LIBS)

INC += AmcCarrier.h

USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
cpsw_DIR += $(CPSW_FRAMEWORK_LIB)

USR_INCLUDES += $(BOOST_INCLUDE)
boost_system_DIR += $(BOOST_LIB)

PROD_IOC += AmcCarrierApp
DBD += AmcCarrierApp.dbd
AmcCarrierApp_DBD += base.dbd asyn.dbd
AmcCarrierApp_DBD += AmcCarrierSupport.dbd
AmcCarrierApp_DBD += AxiVersionDriverSupport.dbd
AmcCarrierApp_DBD += Pgp2bAxiDriverSupport.dbd
AmcCarrierApp_DBD += JesdRxDriverSupport.dbd
AmcCarrierApp_DBD += JesdTxDriverSupport.dbd
AmcCarrierApp_DBD += Lmk04828DriverSupport.dbd
AmcCarrierApp_DBD += Adc16Dx370DriverSupport.dbd
AmcCarrierApp_DBD += Adc16Dx370DriverSupport.dbd
AmcCarrierApp_DBD += Dac38J84DriverSupport.dbd
AmcCarrierApp_DBD += AmcGenericAdcDacCtrlDriverSupport.dbd
AmcCarrierApp_DBD += JesdRxDaqDriverSupport.dbd
AmcCarrierApp_DBD += RingBufferDriverSupport.dbd

AmcCarrierApp_SRCS_DEFAULT += AmcCarrierApp_registerRecordDeviceDriver.cpp AmcCarrierAppMain.cpp 
AmcCarrierApp_LIBS += AmcCarrier
AmcCarrierApp_LIBS += AxiVersion
AmcCarrierApp_LIBS += Pgp2bAxi
AmcCarrierApp_LIBS += JesdRx
AmcCarrierApp_LIBS += JesdTx
AmcCarrierApp_LIBS += Lmk04828
AmcCarrierApp_LIBS += Adc16Dx370
AmcCarrierApp_LIBS += Adc16Dx370
AmcCarrierApp_LIBS += Dac38J84
AmcCarrierApp_LIBS += AmcGenericAdcDacCtrl
AmcCarrierApp_LIBS += JesdRxDaq
AmcCarrierApp_LIBS += RingBuffer
AmcCarrierApp_LIBS += DeviceLibrary
AmcCarrierApp_LIBS += cpswAsynPortDriverSupport
AmcCarrierApp_LIBS += asyn

AmcCarrierApp_LIBS += cpsw
AmcCarrierApp_LIBS += boost_system

AmcCarrierApp_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


