#!../../bin/linux-x86_64/Kcu105NoRssiApp

< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("dbd/Kcu105NoRssiApp.dbd")
Kcu105NoRssiApp_registerRecordDeviceDriver(pdbbase)

#create a Kcu105NoRssi
#Kc705TenGigEthCreate("192.168.2.10")
Kcu105NoRssiCreate("192.168.2.10")


#find AxiVersion at address root/Kcu105NoRssi
AxiVersionCreate("AxiVersion", "root/Kcu105NoRssi")
TenGigEthRegCreate("TenGigEthReg", "root/Kcu105NoRssi")
PrbsTxCreate("PrbsTx", "root/Kcu105NoRssi")

dbLoadRecords("db/AxiVersion.db")
#dbLoadRecords("db/AxiXadc.db")
dbLoadRecords("db/TenGigEthReg.db")
dbLoadRecords("db/PrbsTx.db")

iocInit()
#dbl()
#asynReport 11
