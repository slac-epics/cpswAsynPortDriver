from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "AxiXadc",
     'registers': [{'name'    : "Temperature",
                    'address' : "0x200",
                    'size'    : "24",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "VccInt",
                    'address' : "0x204",
                    'size'    : "24",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "VccAux",
                    'address' : "0x208",
                    'size'    : "24",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "VrefP",
                    'address' : "0x210",
                    'type'    : "Status" },
                   {'name'    : "VrefN",
                    'address' : "0x214",
                    'type'    : "Status" },
                   {'name'    : "VccBram",
                    'address' : "0x218",
                    'type'    : "Status" },
                   {'name'    : "SupplyOffsetA",
                    'address' : "0x220",
                    'type'    : "Status" },
                   {'name'    : "AdcOffsetA",
                    'address' : "0x224",
                    'type'    : "Status" },
                   {'name'    : "AdcGainA",
                    'address' : "0x228",
                    'type'    : "Status" },
                   {'name'    : "VccpInt",
                    'address' : "0x234",
                    'type'    : "Status" },
                   {'name'    : "VccpAux",
                    'address' : "0x238",
                    'type'    : "Status" },
                   {'name'    : "VccpDdr",
                    'address' : "0x23C",
                    'type'    : "Status" },

#
                   {'name'    : "VinAux_0",
                    'address' : "0x240",
                    'type'    : "Status"},
                   {'name'    : "VinAux_1",
                    'address' : "0x244",
                    'type'    : "Status"},
                   {'name'    : "VinAux_2",
                    'address' : "0x248",
                    'type'    : "Status"},
                   {'name'    : "VinAux_3",
                    'address' : "0x24C",
                    'type'    : "Status"},
                   {'name'    : "VinAux_4",
                    'address' : "0x250",
                    'type'    : "Status"},
                   {'name'    : "VinAux_5",
                    'address' : "0x254",
                    'type'    : "Status"},
                   {'name'    : "VinAux_6",
                    'address' : "0x258",
                    'type'    : "Status"},
                   {'name'    : "VinAux_7",
                    'address' : "0x25C",
                    'type'    : "Status"},
                   {'name'    : "VinAux_8",
                    'address' : "0x260",
                    'type'    : "Status"},
                   {'name'    : "VinAux_9",
                    'address' : "0x264",
                    'type'    : "Status"},
                   {'name'    : "VinAux_10",
                    'address' : "0x268",
                    'type'    : "Status"},
                   {'name'    : "VinAux_11",
                    'address' : "0x26C",
                    'type'    : "Status"},
                   {'name'    : "VinAux_12",
                    'address' : "0x270",
                    'type'    : "Status"},
                   {'name'    : "VinAux_13",
                    'address' : "0x274",
                    'type'    : "Status"},
                   {'name'    : "VinAux_14",
                    'address' : "0x278",
                    'type'    : "Status"},
                   {'name'    : "VinAux_15",
                    'address' : "0x27C",
                    'type'    : "Status"},

#                   {'name'    : "halfSckPeriod",
#                    'address' : "0xA5",
#                    'type'    : "Status" },

                   {'name'    : "TemperatureMax",
                    'address' : "0x280",
                    'type'    : "Status" },
                   {'name'    : "VccIntMax",
                    'address' : "0x288",
                    'type'    : "Status" },
                   {'name'    : "VccAuxMax",
                    'address' : "0x284",
                    'type'    : "Status" },
                   {'name'    : "VccBramMax",
                    'address' : "0x28C",
                    'type'    : "Status" },
                   {'name'    : "TemperatureMin",
                    'address' : "0x290",
                    'type'    : "Status" },
                   {'name'    : "VccIntMin",
                    'address' : "0x294",
                    'type'    : "Status" },
                   {'name'    : "VccAuxMin",
                    'address' : "0x298",
                    'type'    : "Status" },
                   {'name'    : "VccBramMin",
                    'address' : "0x29C",
                    'type'    : "Status" },
                   {'name'    : "VccpIntMax",
                    'address' : "0x2A0",
                    'type'    : "Status" },
                   {'name'    : "VccpAuxMax",
                    'address' : "0x2A4",
                    'type'    : "Status" },
                   {'name'    : "VccpDdrMax",
                    'address' : "0x2A8",
                    'type'    : "Status" },
                   {'name'    : "VccpIntMin",
                    'address' : "0x2B0",
                    'type'    : "Status" },
                   {'name'    : "VccpAuxMin",
                    'address' : "0x2B4",
                    'type'    : "Status" },
                   {'name'    : "VccpDdrMin",
                    'address' : "0x2B8",
                    'type'    : "Status" },
                   {'name'    : "Flag",
                    'address' : "0x2FC",
                    'type'    : "Status" },
                   {'name'    : "Flag_JTGD",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "11",
                    'type'    : "Status" },
                   {'name'    : "Flag_JTGR",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "Flag_REF",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccpDdr",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccpAux",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccpInt",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccBram",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccAux",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "Flag_VccInt",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "Flag_Temperature",
                    'address' : "0x2FC",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "VccBramMin",
                    'address' : "0x29C",
                    'type'    : "Status" } ]

   }



os.mkdir('AxiXadc')
os.mkdir('AxiXadc/deviceLibrary')
os.mkdir('AxiXadc/AxiXadcSrc')
os.mkdir('AxiXadc/Db')
os.mkdir('AxiXadc/ui')

#device library
f=open('AxiXadc/deviceLibrary/AxiXadc.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiXadc/deviceLibrary/AxiXadc.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('AxiXadc/AxiXadcSrc/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiXadc/AxiXadcSrc/AxiXadcDriver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiXadc/AxiXadcSrc/AxiXadcDriver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiXadc/AxiXadcSrc/AxiXadcDriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('AxiXadc/Db/AxiXadc.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('AxiXadc/ui/AxiXadc.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
