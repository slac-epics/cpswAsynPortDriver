TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += Kc705TenGigEth

# motorRecord.h will be created from motorRecord.dbd
# install devMotorSoft.dbd into <top>/dbd
DBD += Kc705TenGigEthSupport.dbd

# The following are compiled and added to the Support library
Kc705TenGigEth_SRCS += Kc705TenGigEth.cc 
Kc705TenGigEth_LIBS += cpsw
Kc705TenGigEth_LIBS += DeviceLibrary
Kc705TenGigEth_LIBS += $(EPICS_BASE_IOC_LIBS)

INC += Kc705TenGigEth.h

USER_INCLUDES += ../../frameworkSrc
USER_INCLUDES += ../frameworkSrc

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

