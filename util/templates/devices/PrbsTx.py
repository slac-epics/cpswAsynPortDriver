from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "PrbsTx",
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
                    'type'    : "Status" } ],
     'commands': [{ 'name'   : "OneShot"} ]
   }



os.mkdir('PrbsTx')
os.mkdir('PrbsTx/deviceLibrary')
os.mkdir('PrbsTx/PrbsTxSrc')
os.mkdir('PrbsTx/Db')
os.mkdir('PrbsTx/ui')

#device library
f=open('PrbsTx/deviceLibrary/PrbsTx.cc', 'w')
print(Template( file='../deviceTemplate/builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('PrbsTx/deviceLibrary/PrbsTx.h', 'w')
print(Template( file='../deviceTemplate/builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('PrbsTx/PrbsTxSrc/Makefile', 'w')
print(Template( file='../deviceTemplate/Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('PrbsTx/PrbsTxSrc/PrbsTxDriver.cpp', 'w')
print(Template( file='../deviceTemplate/templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('PrbsTx/PrbsTxSrc/PrbsTxDriver.h', 'w')
print(Template( file='../deviceTemplate/templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('PrbsTx/PrbsTxSrc/PrbsTxDriverSupportInclude.dbd', 'w')
print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('PrbsTx/Db/PrbsTx.substitutions', 'w')
print(Template( file='../deviceTemplate/template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('PrbsTx/ui/PrbsTx.ui', 'w')
print(Template( file='../deviceTemplate/templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
