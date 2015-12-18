#!../../bin/linux-x86_64/Kcu105NoRssiApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/Kcu105NoRssiApp.dbd")
Kcu105NoRssiApp_registerRecordDeviceDriver(pdbbase)

#create a Kcu105NoRssi
Kcu105NoRssiCreate("192.168.2.10")


AxiVersionCreate("AxiVersion", "root/Kcu105NoRssi" )
TenGigEthRegCreate("TenGigEthReg", "root/Kcu105NoRssi" )
PrbsTxCreate("PrbsTx", "root/Kcu105NoRssi" )

dbLoadRecords("db/AxiVersion.db")
dbLoadRecords("db/TenGigEthReg.db")
dbLoadRecords("db/PrbsTx.db")

iocInit()

