d = { 'name': "Pgp2bAxi",
     'registers': [{ 'name'   : "CountReset",
                    'address' : "0x00",
                    'type'    : "Configuration" },
                   {'name'    : "ResetRx",
                    'address' : "0x01",
                    'type'    : "Configuration" },
                   {'name'    : "Flush",
                    'address' : "0x02",
                    'type'    : "Configuration" },
                   {'name'    : "Loopback",
                    'address' : "0x03",
                    'type'    : "Configuration" },
                   {'name'    : "LocData",
                    'address' : "0x04",
                    'type'    : "Configuration" },
                   {'name'    : "AutoStatus",
                    'address' : "0x05",
                    'type'    : "Configuration" },
                   {'name'    : "Status",
                    'address' : "0x08",
                    'type'    : "Status" },
                   {'name'    : "RxPhyReady",
                    'address' : "0x08",
                    'size'    : "1",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "TxPhyReady",
                    'address' : "0x08",
                    'size'    : "1",
                    'lsBit'   : "1",
                    'type'    : "Status" },
                   {'name'    : "RxLocalLinkReady",
                    'address' : "0x08",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "RxRemLinkReady",
                    'address' : "0x08",
                    'size'    : "3",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "TxLinkReady",
                    'address' : "0x08",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "RxLinkPolarity",
                    'address' : "0x08",
                    'size'    : "2",
                    'lsBit'   : "8",
                    'type'    : "Status" },
                   {'name'    : "RxRemPause",
                    'address' : "0x08",
                    'size'    : "4",
                    'lsBit'   : "12",
                    'type'    : "Status" },
                   {'name'    : "TxLocPause",
                    'address' : "0x08",
                    'size'    : "4",
                    'lsBit'   : "16",
                    'type'    : "Status" },
                   {'name'    : "RxRemOverflow",
                    'address' : "0x08",
                    'size'    : "4",
                    'lsBit'   : "20",
                    'type'    : "Status" },
                   {'name'    : "TxLocOverflow",
                    'address' : "0x08",
                    'size'    : "4",
                    'lsBit'   : "24",
                    'type'    : "Status" },
                   {'name'    : "RxRemLinkData",
                    'address' : "0x09",
                    'type'    : "Status" },
                   {'name'    : "RxCellErrorCount",
                    'address' : "0x0A",
                    'type'    : "Status" },
                   {'name'    : "RxLinkDownCount",
                    'address' : "0x0B",
                    'type'    : "Status" },
                   {'name'    : "RxLinkErrorCount",
                    'address' : "0x0C",
                    'type'    : "Status" },
                   {'name'    : "RxRemOverflow0Count",
                    'address' : "0x0D",
                    'type'    : "Status" },
                   {'name'    : "RxRemOverflow1Count",
                    'address' : "0x0E",
                    'type'    : "Status" },
                   {'name'    : "RxRemOverflow2Count",
                    'address' : "0x0F",
                    'type'    : "Status" },
                   {'name'    : "RxRemOverflow3Count",
                    'address' : "0x10",
                    'type'    : "Status" },
                   {'name'    : "RxFrameErrorCount",
                    'address' : "0x11",
                    'type'    : "Status" },
                   {'name'    : "RxFrameCount",
                    'address' : "0x12",
                    'type'    : "Status" },
                   {'name'    : "TxLocOverflow0Count",
                    'address' : "0x13",
                    'type'    : "Status" },
                   {'name'    : "TxLocOverflow1Count",
                    'address' : "0x14",
                    'type'    : "Status" },
                   {'name'    : "TxLocOverflow2Count",
                    'address' : "0x15",
                    'type'    : "Status" },
                   {'name'    : "TxLocOverflow3Count",
                    'address' : "0x16",
                    'type'    : "Status" },
                   {'name'    : "TxFrameErrorCount",
                    'address' : "0x17",
                    'type'    : "Status" },
                   {'name'    : "TxFrameCount",
                    'address' : "0x18",
                    'type'    : "Status" },
                   {'name'    : "RxClkFreq",
                    'address' : "0x19",
                    'type'    : "Status" },
                   {'name'    : "TxClkFreq",
                    'address' : "0x1A",
                    'type'    : "Status" },
                   {'name'    : "TxOpCodeStatus",
                    'address' : "0x1C",
                    'type'    : "Status" },
                   {'name'    : "LastTxOpCode",
                    'address' : "0x1C",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "RxOpCodeStatus",
                    'address' : "0x1D",
                    'type'    : "Status" },
                   {'name'    : "LastRxOpCode",
                    'address' : "0x1D",
                    'size'    : "4",
                    'lsBit'   : "0",
                    'type'    : "Status" },
                   {'name'    : "TxOpCodeCount",
                    'address' : "0x1E",
                    'type'    : "Status" },
                   {'name'    : "RxOpCodeCount",
                    'address' : "0x1F",
                    'type'    : "Status" },
 ],
     'commands': [{ 'name'   : "ResetRx"},
                  { 'name'   : "Flush"} ]
   }
