d = { 'name': "AmcGenericAdcDacCtrl",
     'addrSize' : "4",
     'registers': [
                   {'name'    : "AdcValid0",
                    'address' : "0x00",
                    'type'    : "Status" },
                   {'name'    : "AdcValid1",
                    'address' : "0x01",
                    'type'    : "Status" },
                   {'name'    : "AdcValid2",
                    'address' : "0x02",
                    'type'    : "Status" },
                   {'name'    : "AdcValid3",
                    'address' : "0x03",
                    'type'    : "Status" },
                   {'name'    : "StatusReg",
                    'address' : "0x3F",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc0",
                    'address' : "0x40",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc1",
                    'address' : "0x41",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc2",
                    'address' : "0x42",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Adc3",
                    'address' : "0x43",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac0",
                    'address' : "0x44",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "Dac1",
                    'address' : "0x45",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "DacVco",
                    'address' : "0x7E",
                    'size'    : "16",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "AmcClkFreq",
                    'address' : "0x7F",
                    'type'    : "Status" },
                   {'name'    : "LmkClkSel",
                    'address' : "0x80",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "LmkRst",
                    'address' : "0x81",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "lmkSync",
                    'address' : "0x82",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "LmkStatus",
                    'address' : "0x83",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "loopback",
                    'address' : "0x84",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "CounterReset",
                    'address' : "0xFF",
                    'type'    : "Configuration" },
                   {'name'    : "LmkMuxSel",
                    'address' : "0x85",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "DebugLogEn",
                    'address' : "0x86",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "DebugLogClr",
                    'address' : "0x87",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Configuration" }
 ]
}
