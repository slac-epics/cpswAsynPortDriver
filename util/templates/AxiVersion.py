from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "AxiVersion",
     'registers': [{ 'name'   : "ConfigStatus",
                    'address' : "0x00",
                    'type'    : "Configuration" },
                   { 'name'   : "AxiEn",
                     'address': "0x00",
                     'size'   : "1",
                     'lsBit'  : "0",
                     'type'   : "Configuration"},
                   { 'name'   : "TxEn",
                     'address': "0x00",
                     'size'   : "1",
                     'lsBit'  : "1",
                     'type'   : "Configuration"},
                   { 'name'   : "Busy",
                     'address': "0x00",
                     'size'   : "1",
                     'lsBit'  : "2",
                     'type'   : "Status"},
                   { 'name'   : "Overflow",
                     'address': "0x00",
                     'size'   : "1",
                     'lsBit'  : "3",
                     'type'   : "Status"},
                   {'name'    : "PacketLength",
                    'address' : "0x01",
                    'type'    : "Configuration" },
                   {'name'    : "AxiStreamCfg",
                    'address' : "0x02",
                    'type'    : "Configuration" },
                   { 'name'   : "tDest",
                     'address': "0x02",
                     'size'   : "8",
                     'lsBit'  : "0",
                     'type'   : "Configuration"},
                   { 'name'   : "tId",
                     'address': "0x02",
                     'size'   : "8",
                     'lsBit'  : "8",
                     'type'   : "Configuration"},
                   {'name'    : "DataCount",
                    'address' : "0x03",
                    'type'    : "Status" },
                   {'name'    : "EventCount",
                    'address' : "0x04",
                    'type'    : "Status" },
                   {'name'    : "RandomData",
                    'address' : "0x05",
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
