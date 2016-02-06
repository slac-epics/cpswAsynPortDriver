#!../../bin/linux-x86_64/Kc705TenGigEthApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/Kc705TenGigEthApp.dbd")
Kc705TenGigEthApp_registerRecordDeviceDriver(pdbbase)

#create a Kc705TenGigEth
Kc705TenGigEthCreate("192.168.2.10")


AxiVersionCreate("AxiVersion", "root/Kc705TenGigEth/AxiVersion" )
AxiXadcCreate("AxiXadc", "root/Kc705TenGigEth/AxiXadc" )

dbLoadRecords("db/AxiVersion.db", "DEVICE=TEST,PORT=AxiVersion")
dbLoadRecords("db/AxiXadc.db", "DEVICE=TEST,PORT=AxiXadc")

iocInit()

