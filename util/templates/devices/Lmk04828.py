from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "Lmk04828",
     'registers': [{ 'name'   : "ID_DEVICE_TYPE",
                    'address' : "0x003",
                    'type'    : "Status" },
                   {'name'    : "ID_PROD_UPPER",
                    'address' : "0x004",
                    'type'    : "Status" },
                   {'name'    : "ID_PROD_LOWER",
                    'address' : "0x005",
                    'type'    : "Status" },
                   {'name'    : "ID_MASKREV",
                    'address' : "0x006",
                    'type'    : "Status" },
                   {'name'    : "ID_VNDR_UPPER",
                    'address' : "0x00C",
                    'type'    : "Status" },
                   {'name'    : "ID_VNDR_LOWER",
                    'address' : "0x00D",
                    'type'    : "Status" } ] ,
     'commands': [{ 'name'   : "SyncClks"} ]
}


for i in range(0x100, 0x17D):
	if (i == 0x102):
		pass
	elif (i == 0x10A):
		pass
	elif (i == 0x112):
		pass
	elif (i == 0x122):
		pass
	elif (i == 0x12A):
		pass
	elif (i == 0x132):
		pass
	elif (i >= 0x16F and i<=0x172):
		pass
	elif(i >= 0x175 and i<=0x17B):
		pass
	else:
		nme = "LmkReg"
		addr = "{0:#0{1}x}".format(i,6)
		nme += str(addr)
		d['registers'].append(
                   {'name'    : nme,
                    'address' : addr,
                    'type'    : "Configuration" } )

os.mkdir('Lmk04828')
os.mkdir('Lmk04828/deviceLibrary')
os.mkdir('Lmk04828/Lmk04828Src')
os.mkdir('Lmk04828/Db')
os.mkdir('Lmk04828/ui')

#device library
f=open('Lmk04828/deviceLibrary/Lmk04828.cc', 'w')
print(Template( file='builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Lmk04828/deviceLibrary/Lmk04828.h', 'w')
print(Template( file='builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('Lmk04828/Lmk04828Src/Makefile', 'w')
print(Template( file='Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Lmk04828/Lmk04828Src/Lmk04828Driver.cpp', 'w')
print(Template( file='templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Lmk04828/Lmk04828Src/Lmk04828Driver.h', 'w')
print(Template( file='templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Lmk04828/Lmk04828Src/Lmk04828DriverSupportInclude.dbd', 'w')
print(Template( file='templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('Lmk04828/Db/Lmk04828.substitutions', 'w')
print(Template( file='template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('Lmk04828/ui/Lmk04828.ui', 'w')
print(Template( file='templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
