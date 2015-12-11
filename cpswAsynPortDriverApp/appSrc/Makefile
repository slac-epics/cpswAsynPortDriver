TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library
DBD += app.dbd

PROD_IOC += app
app_DBD += base.dbd asyn.dbd AxiVersionDriverSupport.dbd AxiXadcDriverSupport.dbd Kc705TenGigEthSupport.dbd
app_SRCS_DEFAULT += app_registerRecordDeviceDriver.cpp appMain.cpp
app_LIBS += Kc705TenGigEth
app_LIBS += AxiVersion
app_LIBS += AxiXadc
app_LIBS += cpsw
app_LIBS += asyn
PROD_LIBS += cpsw
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

