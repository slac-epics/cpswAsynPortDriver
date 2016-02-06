#!/bin/bash
caput TEST:Adc16Dx370[0]:C_CalibrateADC.PROC 1
caput TEST:Adc16Dx370[1]:C_CalibrateADC.PROC 1
sleep 0.1
# sysrefON
caput TEST:Adc16Dx370[0]:SYS_EN 1
caput TEST:Adc16Dx370[1]:SYS_EN 1
caput TEST:Lmk04828:SYNC_MODE 3
sleep 0.1
caput TEST:Dac38J84:C_InitDAC_JESD.PROC 1
caput TEST:Dac38J84:C_ClearDACAlarms.PROC 1
sleep 0.1
caput TEST:Lmk04828:C_SyncClks.PROC 1
sleep 0.1
#sysrefOff
caput TEST:Adc16Dx370[0]:SYS_EN 0
caput TEST:Adc16Dx370[1]:SYS_EN 0
caput TEST:Lmk04828:SYNC_MODE 0
sleep 0.1
caput TEST:Dac38J84:C_InitDAC_JESD.PROC 1
sleep 0.1
caput TEST:Dac38J84:C_ClearDACAlarms.PROC 1
sleep 0.1
caput TEST:Lmk04828:C_SyncClks.PROC 1
