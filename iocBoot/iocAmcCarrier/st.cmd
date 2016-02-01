#!../../bin/linux-x86_64/AmcCarrierApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/AmcCarrierApp.dbd")
AmcCarrierApp_registerRecordDeviceDriver(pdbbase)

#create a AmcCarrier
AmcCarrierCreate("192.168.2.10")


JesdRxCreate("JesdRx", "root/AmcCarrier" )
JesdTxCreate("JesdTx", "root/AmcCarrier" )
Lmk04828Create("Lmk04828", "root/AmcCarrier" )
Adc16Dx370Create("Adc16Dx370", "root/AmcCarrier" )
Adc16Dx370Create("Adc16Dx370", "root/AmcCarrier" )
Dac38J84Create("Dac38J84", "root/AmcCarrier" )
AmcGenericAdcDacCtrlCreate("AmcGenericAdcDacCtrl", "root/AmcCarrier" )

dbLoadRecords("db/JesdRx.db", "DEVICE=TEST,PORT=JesdRx")
dbLoadRecords("db/JesdTx.db", "DEVICE=TEST,PORT=JesdTx")
dbLoadRecords("db/Lmk04828.db", "DEVICE=TEST,PORT=Lmk04828")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370")
dbLoadRecords("db/Dac38J84.db", "DEVICE=TEST,PORT=Dac38J84")
dbLoadRecords("db/AmcGenericAdcDacCtrl.db", "DEVICE=TEST,PORT=AmcGenericAdcDacCtrl")

iocInit()

