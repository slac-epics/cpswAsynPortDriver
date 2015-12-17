from __future__ import print_function
import os
from Cheetah.Template import Template

d = { 'name': "TenGigEthReg",
     'registers': [{ 'name'   : "PhyReadyCnt",
                    'address' : "0x00",
                    'type'    : "Status" },
                   {'name'    : "RxPauseCnt",
                    'address' : "0x01",
                    'type'    : "Status" },
                   {'name'    : "TxPauseCnt",
                    'address' : "0x02",
                    'type'    : "Status" },
                   {'name'    : "RxCountEnCnt",
                    'address' : "0x03",
                    'type'    : "Status" },
                   {'name'    : "RxOverFlowCnt",
                    'address' : "0x04",
                    'type'    : "Status" },
                   {'name'    : "RxCrcErrorCnt",
                    'address' : "0x05",
                    'type'    : "Status" },
                   {'name'    : "TxCountEnCnt",
                    'address' : "0x06",
                    'type'    : "Status" },
                   {'name'    : "TxUnderRunCnt",
                    'address' : "0x07",
                    'type'    : "Status" },
                   {'name'    : "TxNotReadyCnt",
                    'address' : "0x08",
                    'type'    : "Status" },
                   {'name'    : "TxDisable",
                    'address' : "0x09",
                    'type'    : "Status" },
                   {'name'    : "SigDet",
                    'address' : "0x0A",
                    'type'    : "Status" },
                   {'name'    : "TxFault",
                    'address' : "0x0B",
                    'type'    : "Status" },
                   {'name'    : "GtTxRst",
                    'address' : "0x0C",
                    'type'    : "Status" },
                   {'name'    : "GtRxRst",
                    'address' : "0x0D",
                    'type'    : "Status" },
                   {'name'    : "RstCntDone",
                    'address' : "0x0E",
                    'type'    : "Status" },
                   {'name'    : "Qplllock",
                    'address' : "0x0F",
                    'type'    : "Status" },
                   {'name'    : "TxRstdone",
                    'address' : "0x10",
                    'type'    : "Status" },
                   {'name'    : "RxRstdone",
                    'address' : "0x11",
                    'type'    : "Status" },
                   {'name'    : "TxUsrRdy",
                    'address' : "0x12",
                    'type'    : "Status" },

                   {'name'    : "Status",
                    'address' : "0x40",
                    'type'    : "Status" },
                   {'name'    : "FLAG_PhyReady",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RxPause",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxPause",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "2",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RxCountEn",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "3",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RxOverFlow",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RxCrcError",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "5",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxCountEn",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "6",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxUnderRun",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "7",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxNotReady",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxDisable",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "9",
                    'type'    : "Status" },
                   {'name'    : "FLAG_SigDet",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "10",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxFault",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "11",
                    'type'    : "Status" },
                   {'name'    : "FLAG_GtTxRst",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "12",
                    'type'    : "Status" },
                   {'name'    : "FLAG_GtRxRst",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "13",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RstCntDone",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "14",
                    'type'    : "Status" },
                   {'name'    : "FLAG_Qplllock",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "15",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxRstdone",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "16",
                    'type'    : "Status" },
                   {'name'    : "FLAG_RxRstdone",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "17",
                    'type'    : "Status" },
                   {'name'    : "FLAG_TxUsrRdy",
                    'address' : "0x40",
                    'size'    : "1",
                    'lsBit'   : "18",
                    'type'    : "Status" }]
   }



os.mkdir('TenGigEthReg')
os.mkdir('TenGigEthReg/deviceLibrary')
os.mkdir('TenGigEthReg/TenGigEthRegSrc')
os.mkdir('TenGigEthReg/Db')
os.mkdir('TenGigEthReg/ui')

#device library
f=open('TenGigEthReg/deviceLibrary/TenGigEthReg.cc', 'w')
print(Template( file='../deviceTemplate/builder.cc.tmpl', searchList = [d] ), file=f)
f.close()

f=open('TenGigEthReg/deviceLibrary/TenGigEthReg.h', 'w')
print(Template( file='../deviceTemplate/builder.h.tmpl', searchList = [d] ), file=f)
f.close()

#asyn driver
f=open('TenGigEthReg/TenGigEthRegSrc/Makefile', 'w')
print(Template( file='../deviceTemplate/Makefile.tmpl', searchList = [d] ), file=f)
f.close()

f=open('TenGigEthReg/TenGigEthRegSrc/TenGigEthRegDriver.cpp', 'w')
print(Template( file='../deviceTemplate/templateDriver.cpp.tmpl', searchList = [d] ), file=f)
f.close()

f=open('TenGigEthReg/TenGigEthRegSrc/TenGigEthRegDriver.h', 'w')
print(Template( file='../deviceTemplate/templateDriver.h.tmpl', searchList = [d] ), file=f)
f.close()

f=open('TenGigEthReg/TenGigEthRegSrc/TenGigEthRegDriverSupportInclude.dbd', 'w')
print(Template( file='../deviceTemplate/templateDriverSupportInclude.dbd.tmpl', searchList = [d] ), file=f)
f.close()

#database substitutions
f=open('TenGigEthReg/Db/TenGigEthReg.substitutions', 'w')
print(Template( file='../deviceTemplate/template.substitutions.tmpl', searchList = [d] ), file=f)
f.close()

#gui
f=open('TenGigEthReg/ui/TenGigEthReg.ui', 'w')
print(Template( file='../deviceTemplate/templateGui.ui.tmpl', searchList = [d] ), file=f)
f.close()
