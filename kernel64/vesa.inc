
vbe_information:
vbe_signature		db		'    '		;VBE Signature
vbe_version			dw		0			;VBE Version
vbe_oem_ptr			dd		0			;VBE Oem Ptr
vbe_capabilities	db		0,0,0,0
vbe_videmodeptr		dd		0
vbe_totalmemory		dw		0
vbe_oemrev			dw		0
vbe_oem_vn_ptr		dd		0
vbe_oem_pn_ptr		dd		0
vbe_oem_pv_ptr		dd		0
times 222			db		0xFF
times 256			db		0



get_vbe_information:
	mov		ax,cs
	mov		es,ax
	mov		ax,0x4F00
	mov		di,vbe_information
	int		0x10
	cmp		al,0x4F
	jnz		.01gvi
	stc
	ret
.01gvi:
	clc
ret