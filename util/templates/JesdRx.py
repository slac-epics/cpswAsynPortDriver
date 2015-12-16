from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "JesdRx",
     'registers': [{ 'name'   : "Enable",
                    'address' : "0x00",
                    'type'    : "Configuration" },
                   {'name'    : "SysrefDelay",
                    'address' : "0x01",
                    'type'    : "Configuration" },
#                   {'name'    : "AXISTrigger",
#                    'address' : "0x02",
#                    'type'    : "Configuration" },
#                   {'name'    : "AXISpacketSize",
#                    'address' : "0x03",
#                    'type'    : "Configuration" },
                   {'name'    : "CommonControl",
                    'address' : "0x04",
                    'type'    : "Configuration" },
                   {'name'    : "SubClass",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "ReplaceEnable",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Configuration" },
                   {'name'    : "ResetGTs",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Configuration" },
                   {'name'    : "ClearErrors",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Configuration" },
                   {'name'    : "InvertSync",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Configuration" },

                   {'name'    : "L1_Test_thr",
                    'address' : "0x30",
                    'type'    : "Configuration" },
                   {'name'    : "L1_Threshold_Low",
                    'address' : "0x30",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "L1_Threshold_High",
                    'address' : "0x30",
                    'size'    : "16",
                    'lsBit'   : "16",
                    'type'    : "Configuration" },

                   {'name'    : "L2_Test_thr",
                    'address' : "0x31",
                    'type'    : "Configuration" },
                   {'name'    : "L2_Threshold_Low",
                    'address' : "0x31",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "L2_Threshold_High",
                    'address' : "0x31",
                    'size'    : "16",
                    'lsBit'   : "16",
                    'type'    : "Configuration" },
#L1 Status
                   {'name'    : "L1_Status",
                    'address' : "0x10",
                    'type'    : "Status" },
                   {'name'    : "L1_GTXReady",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L1_DataValid",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L1_AlignErr",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L1_nSync",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L1_RxBuffUfl",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L1_RxBuffOfl",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L1_PositionErr",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L1_RxEnabled",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L1_SysRefDetected",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L1_CommaDetected",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L1_DisparityErr",
                    'address' : "0x10",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L1_DecErr",
                    'address' : "0x10",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status" },
                   {'name'    : "L1_ElBuffLatency",
                    'address' : "0x10",
                    'size'    : "8",
                    'lsBit'   : "18",
                    'type'    : "Status" },
# L2 Status
                   {'name'    : "L2_Status",
                    'address' : "0x11",
                    'type'    : "Status" },
                   {'name'    : "L2_GTXRdy",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L2_DataValid",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L2_AlignErr",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L2_nSync",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L2_RxBuffUfl",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L2_RxBuffOfl",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L2_PositionErr",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L2_RxEnabled",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L2_SysRefDetected",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L2_CommaDetected",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L2_DisparityErr",
                    'address' : "0x11",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L2_DecErr",
                    'address' : "0x11",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status" },
# L3 Status
                   {'name'    : "L3_Status",
                    'address' : "0x12",
                    'type'    : "Status" },
                   {'name'    : "L3_GTXRdy",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L3_DataValid",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L3_AlignErr",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L3_nSync",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L3_RxBuffUfl",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L3_RxBuffOfl",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L3_PositionErr",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L3_RxEnabled",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L3_SysRefDetected",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L3_CommaDetected",
                    'address' : "0x12",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L3_DisparityErr",
                    'address' : "0x12",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L3_DecErr",
                    'address' : "0x12",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status"},
# L4 Status
                   {'name'    : "L4_Status",
                    'address' : "0x13",
                    'type'    : "Status" },
                   {'name'    : "L4_GTXRdy",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L4_DataValid",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L4_AlignErr",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L4_nSync",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L4_RxBuffUfl",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L4_RxBuffOfl",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L4_PositionErr",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L4_RxEnabled",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L4_SysRefDetected",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L4_CommaDetected",
                    'address' : "0x13",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L4_DisparityErr",
                    'address' : "0x13",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L4_DecErr",
                    'address' : "0x13",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status" },
# L5 Status
                   {'name'    : "L5_Status",
                    'address' : "0x14",
                    'type'    : "Status" },
                   {'name'    : "L5_GTXRdy",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L5_DataValid",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L5_AlignErr",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L5_nSync",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L5_RxBuffUfl",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L5_RxBuffOfl",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L5_PositionErr",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L5_RxEnabled",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L5_SysRefDetected",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L5_CommaDetected",
                    'address' : "0x14",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L5_DisparityErr",
                    'address' : "0x14",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L5_DecErr",
                    'address' : "0x14",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status" },
# L6 Status
                   {'name'    : "L6_Status",
                    'address' : "0x15",
                    'type'    : "Status" },
                   {'name'    : "L6_GTXRdy",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "L6_DataValid",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "L6_AlignErr",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L6_nSync",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L6_RxBuffUfl",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L6_RxBuffOfl",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "L6_PositionErr",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "L6_RxEnabled",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "L6_SysRefDetected",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "L6_CommaDetected",
                    'address' : "0x15",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "L6_DisparityErr",
                    'address' : "0x15",
                    'size'    : "4",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "L6_DecErr",
                    'address' : "0x15",
                    'size'    : "4",
                    'lsBit'   : "14",
                    'type'    : "Status" }],
     'commands': [{ 'name'   : "ClearErrors "},
                  { 'name'   : "RestartGTs" }]
   }



os.mkdir('JesdRx')
os.mkdir('JesdRx/deviceLibrary')
os.mkdir('JesdRx/JesdRxSrc')
os.mkdir('JesdRx/Db')
os.mkdir('JesdRx/ui')

#device library
f=open('JesdRx/deviceLibrary/JesdRx.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdRx/deviceLibrary/JesdRx.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('JesdRx/JesdRxSrc/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdRx/JesdRxSrc/JesdRxDriver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdRx/JesdRxSrc/JesdRxDriver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdRx/JesdRxSrc/JesdRxDriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('JesdRx/Db/JesdRx.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('JesdRx/ui/JesdRx.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()