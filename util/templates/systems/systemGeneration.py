from __future__ import print_function
import os
import sys
from Cheetah.Template import Template

def makeDirectory(d):
	os.mkdir(d['name'])
	os.mkdir(d['name']+'/'+d['name']+'Src')
	os.mkdir(d['name']+'/Db')
	os.mkdir(d['name']+'/ui')
	os.mkdir(d['name']+'/iocBoot')
	os.mkdir(d['name']+'/iocBoot/ioc'+d['name'])

#device library

#driver
def makeDriver(d):
	f=open(d['name']+'/'+d['name']+'Src/Makefile', 'w')
	print(Template( file='../systemTemplate/Makefile.System.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'.cpp', 'w')
	print(Template( file='../systemTemplate/templateSystem.cpp.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'.h', 'w')
	print(Template( file='../systemTemplate/templateSystem.h.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'SupportInclude.dbd', 'w')
	print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
	f.close()
	
	f=open(d['name']+'/'+d['name']+'Src/'+d['name']+'AppMain.cpp', 'w')
	print(Template( file='../systemTemplate/main.cpp.tmpl', searchList = [d] ), file=f)
	f.close()

#UI
def makeGui(d):
	f=open(d['name']+'/ui/'+d['name']+'.ui', 'w')
	print(Template( file='../systemTemplate/templateSystem.ui.tmpl', searchList = [d] ), file=f)
	f.close()

#st.cmd
def makeSt(d):
	f=open(d['name']+'/iocBoot/ioc'+d['name']+'/st.cmd', 'w')
	print(Template( file='../systemTemplate/st.cmd.tmpl', searchList = [d] ), file=f)
	f.close()

	f=open(d['name']+'/iocBoot/ioc'+d['name']+'/Makefile', 'w')
	print(Template( file='../systemTemplate/iocBoot.Makefile.tmpl', searchList = [d] ), file=f)
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
		makeDriver(d)
		makeSt(d)
		makeGui(d)
