TOP=../../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#==================================================
# Build an IOC support library

LIBRARY_IOC += RingBuffer

DBD += RingBufferDriverSupport.dbd

# The following are compiled and added to the Support library
RingBuffer_SRCS += RingBufferDriver.cpp

RingBuffer_LIBS += DeviceLibrary
RingBuffer_LIBS += cpswAsynPortDriverSupport
RingBuffer_LIBS += asyn
RingBuffer_LIBS += $(EPICS_BASE_IOC_LIBS)
USR_INCLUDES += $(CPSW_FRAMEWORK_INCLUDE)
USR_INCLUDES += $(BOOST_INCLUDE)
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


