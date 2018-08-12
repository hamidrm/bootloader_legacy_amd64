gdtr:
    dw		gdt_end-gdt_start-1   ;GDT Legth
    dd		gdt_start             ;GDT Offset   

gdt_start:                            ;Null Descriptor
	dd		0
	dd		0

osl_cs:                               ;Kernel Code Descriptor
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0x9A
	db		0xcf
	db		0x00

osl_ds:                               ;Kernel Data Descriptor
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0x92
	db		0xcf
	db		0x00

appl_cs:                               ;Application Code Descriptor
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0xfa
	db		0xcf
	db		0xC0   ; Start Point Of the user layer

appl_ds:                               ;Application Data Descriptor
	dw		0xffff
	dw		0x0000
	db		0x00
	db		0xf2
	db		0xcf
	db		0xC0   ; Start Point Of the user layer

graphic_chars_buffer:
	dw		3999	       ; Limit 80*25*2-1
	dw		0x8000	       ; Base 0xb8000
	db		0x0b
	db		0x92	       ; present,ring 0,data,expand-up,writable
	db		0x40	       ; byte granularity 16 bit
	db		0x00

gdt_end:


code_seg equ osl_cs-gdt_start
data_seg equ osl_ds-gdt_start
chars_seg equ graphic_chars_buffer-gdt_start
