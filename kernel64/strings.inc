CPU_64BIT_NOT_SUPPORTED		DB		"Sorry! Your hardware does not support 64bit instructions...",0xA,0xD,0
CPU_TOO_OLD					DB		"Sorry! Your system CPU is too old...",0xA,0xD,0
BIOS_TOO_OLD				DB		"Sorry! Your system BIOS is too old...",0xA,0xD,0
MEMORY_TOO_LOW				DB		"Sorry! Your system RAM is less than 8MB...",0xA,0xD,0
PressKey					DB		"Press any key to restart...",0
BREAKPS						DB		"***********Breakpoint  Called***********",fl,nl,zs
BREAKPE						DB		"****************************************",fl,nl,zs
RAX_VAL						DB		"RAX : ",0
RBX_VAL						DB		"RBX : ",0
RCX_VAL						DB		"RCX : ",0
RDX_VAL						DB		"RDX : ",0
RSI_VAL						DB		"RSI : ",0
RDI_VAL						DB		"RDI : ",0
CR0_VAL						DB		"CR0 : ",0
CR2_VAL						DB		"CR2 : ",0
CR3_VAL						DB		"CR3 : ",0
CR4_VAL						DB		"CR4 : ",0
RIP_VAL						DB		"RIP : ",0
SS_VAL						DB		"SS  : ",0
ES_VAL						DB		"ES  : ",0
FS_VAL						DB		"FS  : ",0
GS_VAL						DB		"GS  : ",0
CS_VAL						DB		"CS  : ",0
DS_VAL						DB		"DS  : ",0
RSP_VAL						DB		"RSP : ",0
RIF_VAL						DB		"RIF : ",0
EIO							DB		"Unhandeled Exception Occured ! : #",0
EXV							DB		"DEDBNIOFUDBRNMDFCSTSNPSSGPPFMFACMCXMVE"
ENDL						DB		fl,nl,zs
