#!../../bin/linux-x86_64/app

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("dbd/app.dbd")
app_registerRecordDeviceDriver(pdbbase)

#create a digFpga
Kc705TenGigEthCreate("192.168.2.10")

#find AxiVersion at address root/digFpga
AxiVersionCreate("AxiVersion", "root/digFpga")
AxiXadcCreate("AxiXadc", "root/digFpga")

dbLoadRecords("db/testAsynPortDriver.db")

iocInit()
#dbl()
#asynReport 11
