from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "Kcu105NoRssi",
     'peripherals': [{ 'name'  : "AxiVersion",
                    'address'  : "0x00000000" },
                     { 'name'  : "TenGigEthReg",
                    'address'  : "0x00020000" },
                     { 'name'  : "PrbsTx",
                    'address'  : "0x00030000" }]
   }



os.mkdir('Kcu105NoRssi')
os.mkdir('Kcu105NoRssi/Kcu105NoRssiSrc')
os.mkdir('Kcu105NoRssi/Db')
os.mkdir('Kcu105NoRssi/ui')
os.mkdir('Kcu105NoRssi/iocBoot')
os.mkdir('Kcu105NoRssi/iocBoot/Kcu105NoRssi')

#device library

#driver
f=open('Kcu105NoRssi/Kcu105NoRssiSrc/Makefile', 'w')
print(Template( file='../systemTemplate/Makefile.System.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kcu105NoRssi/Kcu105NoRssiSrc/Kcu105NoRssiDriver.cpp', 'w')
print(Template( file='../systemTemplate/templateSystem.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kcu105NoRssi/Kcu105NoRssiSrc/Kcu105NoRssiDriver.h', 'w')
print(Template( file='../systemTemplate/templateSystem.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kcu105NoRssi/Kcu105NoRssiSrc/Kcu105NoRssiDriverSupportInclude.dbd', 'w')
print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kcu105NoRssi/Kcu105NoRssiSrc/Kcu105NoRssiAppMain.cpp', 'w')
print(Template( file='../systemTemplate/main.cpp.tmpl', searchList = [d] ), file=f)
f.close()

#UI
f=open('Kcu105NoRssi/ui/Kcu105NoRssi.ui', 'w')
print(Template( file='../systemTemplate/templateSystem.ui.tmpl', searchList = [d] ), file=f)
f.close()

#st.cmd
f=open('Kcu105NoRssi/iocBoot/Kcu105NoRssi/st.cmd', 'w')
print(Template( file='../systemTemplate/st.cmd.tmpl', searchList = [d] ), file=f)
f.close()
