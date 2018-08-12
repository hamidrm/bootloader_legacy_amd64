





old_idt32	dw	0x00		;Length
			dd	0x00		;Base

init_idt64	dw	0x00		;Length
			dq	0x00		;Base

tmp_itr:
    dw		256*34
    dq		os_idt



tmp_dtr:
    dw		tmp_dte-tmp_dtr-1
    dq		tmp_dts


tmp_dts:
	dq		0

tmp_code:
	dd		0x00		; Limit And Base ignored in Long Mode
	db		0x00		; Limit And Base ignored in Long Mode
	db		0x98
	db		0x20
	db		0x00

tmp_data:
	dd		0x00		; Limit And Base ignored in Long Mode
	db		0x00		; Limit And Base ignored in Long Mode
	db		0x90
	db		0x00
	db		0x00

tmp_gcb:					;Graphic Charectors Buffer
	dw		3999
	dw		0x8000
	db		0x0b
	db		0x90
	db		0x00
	db		0x00

tmp_dte: