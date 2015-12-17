from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "AmcGenericAdcDacCtrl",
     'registers': [{ 'name'   : "Adc0_t0",
                    'address' : "0x40",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc0_t1",
                    'address' : "0x41",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc0_t2",
                    'address' : "0x42",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc0_t3",
                    'address' : "0x43",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc1_t0",
                    'address' : "0x44",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc1_t1",
                    'address' : "0x45",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc1_t2",
                    'address' : "0x46",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc1_t3",
                    'address' : "0x47",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc2_t0",
                    'address' : "0x48",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc2_t1",
                    'address' : "0x49",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc2_t2",
                    'address' : "0x4A",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc2_t3",
                    'address' : "0x4B",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc3_t0",
                    'address' : "0x4C",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc3_t1",
                    'address' : "0x4D",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc3_t2",
                    'address' : "0x4E",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc3_t3",
                    'address' : "0x4F",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac0_t0",
                    'address' : "0x50",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac0_t1",
                    'address' : "0x51",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac0_t2",
                    'address' : "0x52",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac0_t3",
                    'address' : "0x53",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac1_t0",
                    'address' : "0x54",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac1_t1",
                    'address' : "0x55",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac1_t2",
                    'address' : "0x56",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac1_t3",
                    'address' : "0x57",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "DacVco",
                    'address' : "0x7E",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "AmcClkFreq",
                    'address' : "0x7F",
                    'type'    : "Status" },
                   {'name'    : "LmkClkSel",
                    'address' : "0x80",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "LmkRst",
                    'address' : "0x81",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "lmkSync",
                    'address' : "0x82",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "LmkStatus",
                    'address' : "0x83",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Status" } ]
}

os.mkdir('AmcGenericAdcDacCtrl')
os.mkdir('AmcGenericAdcDacCtrl/deviceLibrary')
os.mkdir('AmcGenericAdcDacCtrl/AmcGenericAdcDacCtrlSrc')
os.mkdir('AmcGenericAdcDacCtrl/Db')
os.mkdir('AmcGenericAdcDacCtrl/ui')

#device library
f=open('AmcGenericAdcDacCtrl/deviceLibrary/AmcGenericAdcDacCtrl.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AmcGenericAdcDacCtrl/deviceLibrary/AmcGenericAdcDacCtrl.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('AmcGenericAdcDacCtrl/AmcGenericAdcDacCtrlSrc/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AmcGenericAdcDacCtrl/AmcGenericAdcDacCtrlSrc/AmcGenericAdcDacCtrlDriver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AmcGenericAdcDacCtrl/AmcGenericAdcDacCtrlSrc/AmcGenericAdcDacCtrlDriver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AmcGenericAdcDacCtrl/AmcGenericAdcDacCtrlSrc/AmcGenericAdcDacCtrlDriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('AmcGenericAdcDacCtrl/Db/AmcGenericAdcDacCtrl.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('AmcGenericAdcDacCtrl/ui/AmcGenericAdcDacCtrl.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
