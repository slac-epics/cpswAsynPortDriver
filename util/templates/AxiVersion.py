from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "AxiVersion",
     'registers': [{ 'name'   : "FpgaVersion",
                    'address' : "0x00",
                    'type'    : "Status" },
                   {'name'    : "ScratchPad",
                    'address' : "0x01",
                    'type'    : "Configuration" },
                   {'name'    : "DeviceDnaHigh",
                    'address' : "0x02",
                    'type'    : "Status" },
                   {'name'    : "DeviceDnaLow",
                    'address' : "0x03",
                    'type'    : "Status" },
                   {'name'    : "FdSerialHigh",
                    'address' : "0x04",
                    'type'    : "Status" },
                   {'name'    : "FdSerialLow",
                    'address' : "0x05",
                    'type'    : "Status" },
                   {'name'    : "MasterReset",
                    'address' : "0x06",
                    'type'    : "Configuration" },
                   {'name'    : "FpgaReload",
                    'address' : "0x07",
                    'type'    : "Configuration" },
                   {'name'    : "FpgaReloadAddress",
                    'address' : "0x08",
                    'type'    : "Configuration" },
                   {'name'    : "Counter",
                    'address' : "0x09",
                    'type'    : "Status" },
                   {'name'    : "FpgaReloadHalt",
                    'address' : "0x0A",
                    'type'    : "Configuration" },
                   {'name'    : "UserConstants",
                    'address' : "0x100",
                    'nelms'   : "64",
                    'type'    : "Configuration" },
                   {'name'    : "BuildStamp",
                    'address' : "0x200",
                    'size'    : "8",
                    'nelms'   : "64",
                    'dtype'   : "string",
                    'type'    : "Status" } ]
   }



os.mkdir('AxiVersion')
os.mkdir('AxiVersion/deviceLibrary')
os.mkdir('AxiVersion/AxiVersionSrc')
os.mkdir('AxiVersion/Db')
os.mkdir('AxiVersion/ui')

#device library
f=open('AxiVersion/deviceLibrary/AxiVersion.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiVersion/deviceLibrary/AxiVersion.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('AxiVersion/AxiVersionSrc/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiVersion/AxiVersionSrc/AxiVersionDriver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiVersion/AxiVersionSrc/AxiVersionDriver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiVersion/AxiVersionSrc/PrbsDriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('AxiVersion/Db/AxiVersion.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('AxiVersion/ui/AxiVersion.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
