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
AxiVersionCreate("AxiVersion", "root/Kcu105NoRssi/AxiVersion")
TenGigEthRegCreate("TenGigEthReg", "root/Kcu105NoRssi/TenGigEthReg")
PrbsTxCreate("PrbsTx", "root/Kcu105NoRssi/PrbsTx")

dbLoadRecords("db/AxiVersion.db", "DEVICE=TEST,PORT=AxiVersion")
#dbLoadRecords("db/AxiXadc.db", "DEVICE=TEST,PORT=AxiXadc")
dbLoadRecords("db/TenGigEthReg.db", "DEVICE=TEST,PORT=TenGigEthReg")
dbLoadRecords("db/PrbsTx.db", "DEVICE=TEST,PORT=PrbsTx")

iocInit()
#dbl()
#asynReport 11
