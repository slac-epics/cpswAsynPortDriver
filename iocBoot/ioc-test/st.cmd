#!../../bin/linux-x86_64/app

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("dbd/app.dbd")
app_registerRecordDeviceDriver(pdbbase)

AxiVersionCreate("AxiVersion", "root/digFpga")
AxiXadcCreate("AxiXadc", "root/digFpga")

dbLoadRecords("db/testAsynPortDriver.db")

iocInit()
#dbl()
asynReport 11
