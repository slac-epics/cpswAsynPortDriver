TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Adc16Dx370

DBD += Adc16Dx370DriverSupport.dbd

# The following are compiled and added to the Support library
Adc16Dx370_SRCS += Adc16Dx370Driver.cpp

Adc16Dx370_LIBS += cpsw
Adc16Dx370_LIBS += DeviceLibrary
Adc16Dx370_LIBS += cpswAsynPortDriverSupport
Adc16Dx370_LIBS += asyn
Adc16Dx370_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


