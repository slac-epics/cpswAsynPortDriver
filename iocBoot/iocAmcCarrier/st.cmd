#!../../bin/linuxRT_glibc-x86_64/AmcCarrierApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/AmcCarrierApp.dbd")
AmcCarrierApp_registerRecordDeviceDriver(pdbbase)

#create a AmcCarrier
AmcCarrierCreate("192.168.2.10")

epicsThreadSleep(1)

AxiVersionCreate("AxiVersion", "root/AmcCarrier" )
Pgp2bAxiCreate("Pgp2bAxi", "root/AmcCarrier" )
JesdRxCreate("JesdRx", "root/AmcCarrier" )
JesdTxCreate("JesdTx", "root/AmcCarrier" )
Lmk04828Create("Lmk04828", "root/AmcCarrier" )
Adc16Dx370Create("Adc16Dx370_0", "root/AmcCarrier" )
Adc16Dx370Create("Adc16Dx370_1", "root/AmcCarrier" )
Dac38J84Create("Dac38J84", "root/AmcCarrier" )
AmcGenericAdcDacCtrlCreate("AmcGenericAdcDacCtrl", "root/AmcCarrier" )
JesdRxDaqCreate("JesdRxDaq", "root/AmcCarrier" )

dbLoadRecords("db/AxiVersion.db", "DEVICE=TEST,PORT=AxiVersion")
dbLoadRecords("db/Pgp2bAxi.db", "DEVICE=TEST,PORT=Pgp2bAxi")
dbLoadRecords("db/JesdRx.db", "DEVICE=TEST,PORT=JesdRx")
dbLoadRecords("db/JesdTx.db", "DEVICE=TEST,PORT=JesdTx")
dbLoadRecords("db/Lmk04828.db", "DEVICE=TEST,PORT=Lmk04828")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370_0")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370_1")
dbLoadRecords("db/Dac38J84.db", "DEVICE=TEST,PORT=Dac38J84")
dbLoadRecords("db/AmcGenericAdcDacCtrl.db", "DEVICE=TEST,PORT=AmcGenericAdcDacCtrl")
dbLoadRecords("db/JesdRxDaq.db", "DEVICE=TEST,PORT=JesdRxDaq")

iocInit()

