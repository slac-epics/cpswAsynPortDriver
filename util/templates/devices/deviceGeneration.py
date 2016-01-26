from __future__ import print_function
import os
import sys
from Cheetah.Template import Template

def makeDirectory(d):
	os.mkdir(d['name'])
	os.mkdir(d['name']+'/deviceLibrary')
	os.mkdir(d['name']+'/'+d['name']+'Src')
	os.mkdir(d['name']+'/Db')
	os.mkdir(d['name']+'/ui')

#device library
def makeDeviceLibrary(d):
	f=open(d['name']+'/deviceLibrary/'+d['name']+'.cc', 'w')
	print(Template( file='../deviceTemplate/builder.cc.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/deviceLibrary/'+d['name']+'.h', 'w')
	print(Template( file='../deviceTemplate/builder.h.tmpl', searchList = [d] ), file=f)
	f.close()

#asyn driver
def makeAsynDriver(d):
	f=open(d['name']+'/'+d['name']+'Src/Makefile', 'w')
	print(Template( file='../deviceTemplate/Makefile.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'Driver.cpp', 'w')
	print(Template( file='../deviceTemplate/templateDriver.cpp.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'Driver.h', 'w')
	print(Template( file='../deviceTemplate/templateDriver.h.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'DriverSupportInclude.dbd', 'w')
	print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
	f.close()

#database template
def makeDatabase(d):
	f=open(d['name']+'/Db/'+d['name']+'.template', 'w')
	print(Template( file='../deviceTemplate/database.tmpl', searchList = [d] ), file=f)
	f.close()

#gui
def makeGui(d):
	f=open(d['name']+'/ui/'+d['name']+'.ui', 'w')
	print(Template( file='../deviceTemplate/templateGui.ui.tmpl', searchList = [d] ), file=f)
	f.close()

def usage(progname):
	print("%s:  Make EPICS files for peripheral", progname)

if __name__ == "__main__":
	import getopt
	try:
		optlist, args = getopt.getopt(sys.argv[1:], 'hd:o:',
			['help', 'device=', 'output='])
	except getopt.GetoptError, err:
		print(str(err))
		usage(sys.argv[0])
		sys.exit(2)
	for o,arg in optlist:
		if o in ('-h', '--help'):
			usage(sys.argv[0])
			sys.exit()
		elif o in ('-d', '--device'):
			device = __import__(arg.replace('.py', ''))
			d = device.d
	if not d:
		print("No device specified")
		usage(sys.argv[0])
		sys.exit(1)
	else:
		makeDirectory(d)
		makeDeviceLibrary(d)
		makeAsynDriver(d)
		makeDatabase(d)
		makeGui(d)
