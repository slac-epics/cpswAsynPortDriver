TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AxiXadc

# motorRecord.h will be created from motorRecord.dbd
# install devMotorSoft.dbd into <top>/dbd
DBD += AxiXadcDriverSupport.dbd

# The following are compiled and added to the Support library
AxiXadc_SRCS += AxiXadcDriver.cpp

AxiXadc_LIBS += cpsw
AxiXadc_LIBS += DeviceLibrary 
AxiXadc_LIBS += cpswAsynPortDriverSupport
AxiXadc_LIBS += asyn
AxiXadc_LIBS += $(EPICS_BASE_IOC_LIBS)

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../../src
USER_INCLUDES += ../src
USER_INCLUDES += ../../deviceLibrarySrc

PROD_IOC += axixadc
axixadc_DBD += base.dbd asyn.dbd AxiXadcDriverSupport.dbd
axixadc_SRCS_DEFAULT += axixadc_registerRecordDeviceDriver.cpp axixadcMain.cpp
axixadc_LIBS += AxiXadc
axixadc_LIBS += cpsw
axixadc_LIBS += asyn
PROD_LIBS += cpsw
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

