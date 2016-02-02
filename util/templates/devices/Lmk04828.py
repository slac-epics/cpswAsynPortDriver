d = { 'name': "Lmk04828",
     'registers': [{ 'name'   : "ID_DEVICE_TYPE",
                    'address' : "0x003",
                    'type'    : "Status" },
                   {'name'    : "ID_PROD_UPPER",
                    'address' : "0x004",
                    'type'    : "Status" },
                   {'name'    : "ID_PROD_LOWER",
                    'address' : "0x005",
                    'type'    : "Status" },
                   {'name'    : "ID_MASKREV",
                    'address' : "0x006",
                    'type'    : "Status" },
                   {'name'    : "ID_VNDR_UPPER",
                    'address' : "0x00C",
                    'type'    : "Status" },
                   {'name'    : "ID_VNDR_LOWER",
                    'address' : "0x00D",
                    'type'    : "Status" },
                   {'name'    : "SYS_REF_MUX",
                    'address' : "0x139",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "SYNC_MODE",
                    'address' : "0x143",
                    'size'    : "2",
                    'lsBit'   : "0",
                    'type'    : "Configuration" },
                   {'name'    : "SYNC_EN",
                    'address' : "0x143",
                    'size'    : "1",
                    'lsBit'   : "4",
                    'type'    : "Configuration" },
                   {'name'    : "SYNC_DIS",
                    'address' : "0x144",
                    'size'    : "8",
                    'lsBit'   : "0",
                    'type'    : "Configuration" } ],
     'commands': [{ 'name'   : "SyncClks"}, 
               { 'name'   : "writeConfig"} ]
}


for i in range(0x100, 0x17D):
	if (i == 0x102):
		pass
	elif (i == 0x10A):
		pass
	elif (i == 0x112):
		pass
	elif (i == 0x122):
		pass
	elif (i == 0x12A):
		pass
	elif (i == 0x132):
		pass
	elif (i >= 0x16F and i<=0x172):
		pass
	elif(i >= 0x175 and i<=0x17B):
		pass
	else:
		nme = "LmkReg"
		addr = "{0:#0{1}x}".format(i,6)
		nme += str(addr)
		d['registers'].append(
                   {'name'    : nme,
                    'address' : addr,
                    'type'    : "Configuration" } )
