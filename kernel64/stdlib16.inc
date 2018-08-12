

EnableA20:
	call WaitForEmptyInputBuffer
    mov al,0xAD
    out 0x64,al
	call WaitForEmptyInputBuffer
	mov	al,0xD0
	out	0x64,al
	call WaitForFullOutputBuffer
	in al,0x60
	mov bl,al
	call WaitForEmptyInputBuffer
	or	bl,2
	mov	al,0xD1
	out	0x64,al
	call WaitForEmptyInputBuffer
	mov al,bl
	out	0x60,al
    call WaitForEmptyInputBuffer
    mov al,0xAE
    out 0x64,al
    call WaitForEmptyInputBuffer
ret

Restart:
	call WaitForEmptyInputBuffer
	mov	al,0xD1
	out	0x64,al
	call WaitForEmptyInputBuffer
	mov al,0x00
	out	0x60,al	
ret

WaitForEmptyInputBuffer:
	in	al,0x64
	test al,2
	jnz WaitForEmptyInputBuffer
ret

WaitForFullOutputBuffer:
	in	al,0x64
	test al,1
	jz WaitForFullOutputBuffer
ret

prt_numberw:
	pusha
	mov cx,10
	mov dx,0
	mov si,0

ND:
	div cx
	cmp dx,0
	jnz prt_cnumberw_nzr
	cmp ax,0
	jz prt_cnumberw
prt_cnumberw_nzr:
	push dx
	inc si
	mov dx,0
	jmp ND

prt_cnumberw:
	pop ax
	mov ah,0eh
	mov bh,0
	mov bl,0
	add al,'0'
	int 10h
	dec si
	jnz prt_cnumberw
	popa
ret




prt_numberwh:
	pusha
	push ax
	mov ah,0eh
	mov al,'0'
	mov bh,0
	mov bl,0
	int 10h
	mov al,'x'
	int 10h
	pop ax
	mov cx,16
	mov dx,0
	mov si,0
	jmp	NDH

NDH:
	div cx
	cmp dx,0
	jnz prt_cnumberwh_nzr
	cmp ax,0
	jz prt_cnumberwh
prt_cnumberwh_nzr:
	push dx
	inc si
	mov dx,0
	jmp NDH

prt_cnumberwh:
	pop ax
	mov ah,0eh
	mov bl,al
	mov bh,0
	mov al,[hexval+0x1000+bx]
	mov bh,0
	mov bl,0
	int 10h
	dec si
	jnz prt_cnumberwh
	popa
ret

prt_msg:
	pusha
	mov ah,0eh
	mov bh,0
	mov bl,0xFF
prt_nc:
	mov al,[si]
	cmp al,0
	jz end_prt
	int 10h
	inc si
	jmp prt_nc
end_prt:
	popa
	ret

clr_screen:
	
ret


WaitForKey:
	call	WaitForEmptyInputBuffer
    mov		al,0xAE
    out		0x64,al
	mov		ah,0x10
	int		0x16
ret


HCursor:

	mov		al,0xA
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x0f
	mov		dx,0x3D5
	out		dx,al

	mov		al,0xB
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x0f
	mov		dx,0x3D5
	out		dx,al
ret