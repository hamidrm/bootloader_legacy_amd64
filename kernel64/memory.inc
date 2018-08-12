Page4LInit:

	mov		ebx,os_pml4
	and		ebx,0xFFFF
	mov		edi,ebx
	mov		eax,os_pml4
	and		eax,0xF0000
	shr		eax,4
	mov		es,ax

	push	di
	mov		ecx,0x1000		; Provide 16 KB Blank Space For Primiry Tables  PML4 => PDPT => PD => PT => Mem
	xor		eax,eax
	rep		stosd
	pop		di

	; Page Map Table
	mov		eax,(0x1000+os_pml4)
	or		eax,pg_p|pg_wr
	mov		[es:di],eax

	; Page Directory Pointer Table
	mov		eax,(0x2000+os_pml4)
	or		eax,pg_p|pg_wr
	mov		[es:di+0x1000],eax

	; Page Directory Table
	mov		eax,(0x3000+os_pml4)
	or		eax,pg_p|pg_wr
	mov		[es:di+0x2000],eax
	mov		di,0x3000

	; Page Table
	mov		eax,pg_p|pg_wr
	mov		ecx,0x200		;	Length of a Page Table (512)
.0ipm:
	mov		[es:di],eax
	add		di,8
	add		eax,0x1000
	loop	.0ipm
;jmp		$
ret


idt_init:
	mov		ebx,os_idt
	;and		ebx,0xFFFFFFFF
	mov		edi,ebx
	mov		eax,os_idt
	and		eax,0xF0000
	shr		eax,4
	mov		es,ax

	mov		esi,ivts


	mov		ecx,0x100
	mov		dx ,0x8f00
.0ii:
	mov		ax,si
	mov		[es:di],ax
	mov		WORD [es:di+2],tmp_code_seg
	mov		[es:di+4],dx
	xor		eax,eax
	mov		[es:di+6 ],ax
	mov		[es:di+8 ],eax
	mov		[es:di+12],eax
	add		di,0x10
	add		esi,5
	loop	.0ii
ret