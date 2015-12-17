from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "AxiAd5780",
     'registers': [{ 'name'   : "dacRefreshRate",
                    'address' : "0x10",
                    'type'    : "Status" },
                   {'name'    : "dacData",
                    'address' : "0x30",
                    'type'    : "Status" },
                   {'name'    : "debugMux",
                    'address' : "0x80",
                    'type'    : "Configuration" },
                   {'name'    : "debugData",
                    'address' : "0x90",
                    'type'    : "Configuration" },
                   {'name'    : "sdoDisable",
                    'address' : "0xA0",
                    'type'    : "Configuration" },
                   {'name'    : "binaryOffset",
                    'address' : "0xA1",
                    'type'    : "Configuration" },
                   {'name'    : "dacTriState",
                    'address' : "0xA2",
                    'type'    : "Configuration" },
                   {'name'    : "opGnd",
                    'address' : "0xA3",
                    'type'    : "Conifiguration" },
                   {'name'    : "rbuf",
                    'address' : "0xA4",
                    'type'    : "Configuration" },
                   {'name'    : "halfSckPeriod",
                    'address' : "0xA5",
                    'type'    : "Status" },
                   {'name'    : "dacRst",
                    'address' : "0xFE",
                    'type'    : "Configuration" } ],
     'commands': [{ 'name'   : "dacRst"} ]
   }



os.mkdir('AxiAd5780')
os.mkdir('AxiAd5780/deviceLibrary')
os.mkdir('AxiAd5780/AxiAd5780Src')
os.mkdir('AxiAd5780/Db')
os.mkdir('AxiAd5780/ui')

#device library
f=open('AxiAd5780/deviceLibrary/AxiAd5780.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiAd5780/deviceLibrary/AxiAd5780.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('AxiAd5780/AxiAd5780Src/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiAd5780/AxiAd5780Src/AxiAd5780Driver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiAd5780/AxiAd5780Src/AxiAd5780Driver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('AxiAd5780/AxiAd5780Src/AxiAd5780DriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('AxiAd5780/Db/AxiAd5780.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('AxiAd5780/ui/AxiAd5780.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
