from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "JesdTx",
     'registers': [{ 'name'   : "Enable",
                    'address' : "0x00",
                    'type'    : "Configuration" },
#                   {'name'    : "SysrefDelay",
#                    'address' : "0x01",
#                    'type'    : "Configuration" },
#                   {'name'    : "AXISTrigger",
#                    'address' : "0x02",
#                    'type'    : "Configuration" },
#                   {'name'    : "AXISpacketSize",
#                    'address' : "0x03",
#                    'type'    : "Configuration" },

#CommonControl
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
#                   {'name'    : "ClearErrors",
#                    'address' : "0x04",
#                    'size'    : "1",
#                    'lsBit'   : "3",
#                    'type'    : "Configuration" },
                   {'name'    : "InvertSync",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Configuration" },
                   {'name'    : "EnableTestSig",
                    'address' : "0x04",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Configuration" },

                   {'name'    : "PeriodRampStep",
                    'address' : "0x05",
                    'type'    : "Configuration" },
                   {'name'    : "RampStep",
                    'address' : "0x05",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "SquarePeriod",
                    'address' : "0x05",
                    'size'    : "16",
                    'lsBit'   : "16",
                    'type'    : "Configuration" },

                   {'name'    : "LowAmplitudeVal",
                    'address' : "0x06",
                    'type'    : "Configuration" },
                   {'name'    : "HighAmplitudeVal",
                    'address' : "0x07",
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
                   {'name'    : "L1_IlasActive",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L1_nSync",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L1_TxEnabled",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L1_SysRefDetected",
                    'address' : "0x10",
                    'size'    : "1",
                    'lsBit'   : "5",
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
                   {'name'    : "L2_IlasActive",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "L2_nSync",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "L2_TxEnabled",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "L2_SysRefDetected",
                    'address' : "0x11",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },

                   {'name'    : "L1_SignalSelect",
                    'address' : "0x20",
                    'type'    : "Configuration" },
                   {'name'    : "L1_data_out_mux",
                    'address' : "0x20",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "L1_test_out_mux",
                    'address' : "0x20",
                    'size'    : "4",
                    'lsBit'   : "4",
                    'type'    : "Configuration" },

                   {'name'    : "L2_SignalSelect",
                    'address' : "0x21",
                    'type'    : "Configuration" },
                   {'name'    : "L2_data_out_mux",
                    'address' : "0x21",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "L2_test_out_mux",
                    'address' : "0x21",
                    'size'    : "4",
                    'lsBit'   : "4",
                    'type'    : "Configuration" } ]
   }



os.mkdir('JesdTx')
os.mkdir('JesdTx/deviceLibrary')
os.mkdir('JesdTx/JesdTxSrc')
os.mkdir('JesdTx/Db')
os.mkdir('JesdTx/ui')

#device library
f=open('JesdTx/deviceLibrary/JesdTx.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdTx/deviceLibrary/JesdTx.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('JesdTx/JesdTxSrc/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdTx/JesdTxSrc/JesdTxDriver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdTx/JesdTxSrc/JesdTxDriver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('JesdTx/JesdTxSrc/JesdTxDriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('JesdTx/Db/JesdTx.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('JesdTx/ui/JesdTx.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
