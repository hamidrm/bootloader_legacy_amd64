





old_idt	dq	0x00




tmp_pmr:
    dw		tmp_pme-tmp_pmr-1
    dd		tmp_pms


tmp_pms:
	dq		0

tmp_pmcode:
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0x9A
	db		0xcf
	db		0x00

tmp_pmdata:
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0x92
	db		0xcf
	db		0x00

tmp_gcb:					;Graphic Charectors Buffer
	dw		3999
	dw		0x8000
	db		0x0b
	db		0x92
	db		0x40
	db		0x00

tmp_pme: