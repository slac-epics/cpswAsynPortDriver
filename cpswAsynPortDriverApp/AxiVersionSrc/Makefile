TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += AxiVersion

# motorRecord.h will be created from motorRecord.dbd
# install devMotorSoft.dbd into <top>/dbd
DBD += AxiVersionDriverSupport.dbd

# The following are compiled and added to the Support library
AxiVersion_SRCS += AxiVersionDriver.cpp

AxiVersion_LIBS += cpsw
AxiVersion_LIBS += DeviceLibrary
AxiVersion_LIBS += cpswAsynPortDriverSupport
AxiVersion_LIBS += asyn
AxiVersion_LIBS += $(EPICS_BASE_IOC_LIBS)

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../../src
USER_INCLUDES += ../src
USER_INCLUDES += ../../deviceLibrarySrc

PROD_IOC += axiv
axiv_DBD += base.dbd asyn.dbd AxiVersionDriverSupport.dbd
axiv_SRCS_DEFAULT += axiv_registerRecordDeviceDriver.cpp axivMain.cpp
axiv_LIBS += AxiVersion
axiv_LIBS += cpsw
axiv_LIBS += asyn
PROD_LIBS += cpsw
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

