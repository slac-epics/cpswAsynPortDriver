#!../../bin/linux-x86_64/Kc705TenGigEthApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/Kc705TenGigEthApp.dbd")
Kc705TenGigEthApp_registerRecordDeviceDriver(pdbbase)

#create a Kc705TenGigEth
Kc705TenGigEthCreate("192.168.2.10")


AxiVersionCreate("AxiVersion", "root/Kc705TenGigEth" )
AxiXadcCreate("AxiXadc", "root/Kc705TenGigEth" )

dbLoadRecords("db/AxiVersion.db")
dbLoadRecords("db/AxiXadc.db")

iocInit()

