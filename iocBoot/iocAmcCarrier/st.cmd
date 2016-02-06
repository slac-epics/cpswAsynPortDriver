#!../../bin/linuxRT_glibc-x86_64/AmcCarrierApp

< envPaths

cd ${TOP}

dbLoadDatabase("dbd/AmcCarrierApp.dbd")
AmcCarrierApp_registerRecordDeviceDriver(pdbbase)

#create a AmcCarrier
AmcCarrierCreate("192.168.2.20")

epicsThreadSleep(1)

## $(device)Create
# (1) asynPortName  port name that will be used to connect records, etc.
# (2) path          path to device in hierarchy

AxiVersionCreate("AxiVersion", "root/AmcCarrier/AxiVersion" )
Pgp2bAxiCreate("Pgp2bAxi", "root/AmcCarrier/Pgp2bAxi" )
JesdRxCreate("JesdRx", "root/AmcCarrier/AmcGenericAdcDac[1]/JesdRx" )
JesdTxCreate("JesdTx", "root/AmcCarrier/AmcGenericAdcDac[1]/JesdTx" )
Lmk04828Create("Lmk04828", "root/AmcCarrier/AmcGenericAdcDac[1]/Lmk04828" )
Adc16Dx370Create("Adc16Dx370[0]", "root/AmcCarrier/AmcGenericAdcDac[1]/Adc16Dx370[0]" )
Adc16Dx370Create("Adc16Dx370[1]", "root/AmcCarrier/AmcGenericAdcDac[1]/Adc16Dx370[1]" )
Dac38J84Create("Dac38J84", "root/AmcCarrier/AmcGenericAdcDac[1]/Dac38J84" )
AmcGenericAdcDacCtrlCreate("AmcGenericAdcDacCtrl", "root/AmcCarrier/AmcGenericAdcDac[1]/AmcGenericAdcDacCtrl" )
JesdRxDaqCreate("JesdRxDaq", "root/AmcCarrier/JesdRxDaq" )

####### DEBUG ###############
RingBufferCreate("AdcDebug[0]", "root/AmcCarrier/AmcGenericAdcDac[1]/AdcDebug[0]")
RingBufferCreate("AdcDebug[1]", "root/AmcCarrier/AmcGenericAdcDac[1]/AdcDebug[1]")
RingBufferCreate("AdcDebug[2]", "root/AmcCarrier/AmcGenericAdcDac[1]/AdcDebug[2]")
RingBufferCreate("AdcDebug[3]", "root/AmcCarrier/AmcGenericAdcDac[1]/AdcDebug[3]")
RingBufferCreate("DacDebug[0]", "root/AmcCarrier/AmcGenericAdcDac[1]/DacDebug[0]")
RingBufferCreate("DacDebug[1]", "root/AmcCarrier/AmcGenericAdcDac[1]/DacDebug[1]")
#############################

dbLoadRecords("db/AxiVersion.db", "DEVICE=TEST,PORT=AxiVersion")
dbLoadRecords("db/Pgp2bAxi.db", "DEVICE=TEST,PORT=Pgp2bAxi")
dbLoadRecords("db/JesdRx.db", "DEVICE=TEST,PORT=JesdRx")
dbLoadRecords("db/JesdTx.db", "DEVICE=TEST,PORT=JesdTx")
dbLoadRecords("db/Lmk04828.db", "DEVICE=TEST,PORT=Lmk04828")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370[0]")
dbLoadRecords("db/Adc16Dx370.db", "DEVICE=TEST,PORT=Adc16Dx370[1]")
dbLoadRecords("db/Dac38J84.db", "DEVICE=TEST,PORT=Dac38J84")
dbLoadRecords("db/AmcGenericAdcDacCtrl.db", "DEVICE=TEST,PORT=AmcGenericAdcDacCtrl")
dbLoadRecords("db/JesdRxDaq.db", "DEVICE=TEST,PORT=JesdRxDaq")

####### DEBUG ###############
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=AdcDebug[0]")
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=AdcDebug[1]")
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=AdcDebug[2]")
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=AdcDebug[3]")
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=DacDebug[0]")
dbLoadRecords("db/RingBuffer.db", "DEVICE=TEST,PORT=DacDebug[1]")
############################

iocInit()
