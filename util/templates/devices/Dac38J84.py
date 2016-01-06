from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "Dac38J84",
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
                    'type'    : "Status" },
                   {'name'    : "ADC_Status",
                    'address' : "0x6C",
                    'type'    : "Status"},
                   {'name'    : "Clock_ready",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status"},
                   {'name'    : "Calibration_done",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status"},
                   {'name'    : "PLL_lock",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status"},
                   {'name'    : "Aligned_to_sysref",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status"},
                   {'name'    : "Realigned_to_sysref",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status"},
                   {'name'    : "Sync_form_FPGA",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status"},
                   {'name'    : "Link_active",
                    'address' : "0x6C",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status"}  ] ,
     'commands': [{ 'name'   : "ClearDACAlarms"},
                  { 'name'   : "InitDAC_JESD"} ]
}


for i in range(0x100, 0x17D):
	if (i == 0x01):
		pass
	elif (i>= 0x7 and i<= 0xB):
		pass
	elif (i>= 0x16 and i<= 0x18):
		pass
	elif (i >= 0x1A and i<=0x3A):
		pass
	elif(i >= 0x3E and i<=0x46):
		pass
	elif(i >= 0x48 and i<=0x5F):
		pass
	elif(i >= 0x64 and i<=0x6B):
		pass
	elif(i >= 0x6C and i<=0x6F):
		pass
	elif(i == 0x71):
		pass
	else:
		nme = "AdcReg"
		addr = "{0:#0{1}x}".format(i,6)
		nme += str(addr)
		d['registers'].append(
                   {'name'    : nme,
                    'address' : addr,
                    'type'    : "Configuration" } )

os.mkdir('Dac38J84')
os.mkdir('Dac38J84/deviceLibrary')
os.mkdir('Dac38J84/Dac38J84Src')
os.mkdir('Dac38J84/Db')
os.mkdir('Dac38J84/ui')

#device library
f=open('Dac38J84/deviceLibrary/Dac38J84.cc', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Dac38J84/deviceLibrary/Dac38J84.h', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('Dac38J84/Dac38J84Src/Makefile', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Dac38J84/Dac38J84Src/Dac38J84Driver.cpp', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Dac38J84/Dac38J84Src/Dac38J84Driver.h', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('Dac38J84/Dac38J84Src/Dac38J84DriverSupportInclude.dbd', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database.template
f=open('Dac38J84/Db/Dac38J84.template', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/database.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('Dac38J84/ui/Dac38J84.ui', 'w')
print(Template( file='../deviceTemplate/../deviceTemplate/templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
