from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "Kc705TenGigEth",
     'peripherals': [{ 'name'  : "AxiVersion",
                    'address'  : "0x00000000" },
                     { 'name'  : "AxiXadc",
                    'address'  : "0x00010000" }]
   }



os.mkdir('Kc705TenGigEth')
os.mkdir('Kc705TenGigEth/Kc705TenGigEthSrc')
os.mkdir('Kc705TenGigEth/Db')
os.mkdir('Kc705TenGigEth/ui')
os.mkdir('Kc705TenGigEth/iocBoot')
os.mkdir('Kc705TenGigEth/iocBoot/iocKc705TenGigEth')

#device library

#driver
f=open('Kc705TenGigEth/Kc705TenGigEthSrc/Makefile', 'w')
print(Template( file='../systemTemplate/Makefile.System.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kc705TenGigEth/Kc705TenGigEthSrc/Kc705TenGigEth.cpp', 'w')
print(Template( file='../systemTemplate/templateSystem.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kc705TenGigEth/Kc705TenGigEthSrc/Kc705TenGigEth.h', 'w')
print(Template( file='../systemTemplate/templateSystem.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kc705TenGigEth/Kc705TenGigEthSrc/Kc705TenGigEthSupportInclude.dbd', 'w')
print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kc705TenGigEth/Kc705TenGigEthSrc/Kc705TenGigEthAppMain.cpp', 'w')
print(Template( file='../systemTemplate/main.cpp.tmpl', searchList = [d] ), file=f)
f.close()

#UI
f=open('Kc705TenGigEth/ui/Kc705TenGigEth.ui', 'w')
print(Template( file='../systemTemplate/templateSystem.ui.tmpl', searchList = [d] ), file=f)
f.close()

#st.cmd
f=open('Kc705TenGigEth/iocBoot/iocKc705TenGigEth/st.cmd', 'w')
print(Template( file='../systemTemplate/st.cmd.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Kc705TenGigEth/iocBoot/iocKc705TenGigEth/Makefile', 'w')
print(Template( file='../systemTemplate/iocBoot.Makefile.tmpl', searchList = [d] ), file=f)
f.close()
