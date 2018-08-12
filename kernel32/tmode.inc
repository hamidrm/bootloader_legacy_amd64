CURSOR_POS		DW		0


HideCursor:

	mov		ax,0xA
	mov		dx,0x3D4
	out		dx,ax
	mov		ax,0x07
	mov		dx,0x3D5
	out		dx,ax

	mov		ax,0xB
	mov		dx,0x3D4
	out		dx,ax
	mov		ax,0x07
	mov		dx,0x3D5
	out		dx,ax
ret

ShowCursor:

	mov		al,0xA
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x0C
	mov		dx,0x3D5
	out		dx,al

	mov		al,0xB
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x0F
	mov		dx,0x3D5
	out		dx,al
ret

RefreshCursorPos:
	mov		bx,[CURSOR_POS]

	mov		al,0xF
	mov		dx,0x3D4
	out		dx,al
	mov		al,bl
	mov		dx,0x3D5
	out		dx,al

	mov		al,0xE
	mov		dx,0x3D4
	out		dx,al
	mov		al,bh
	mov		dx,0x3D5
	out		dx,al
ret

PrintMsg:
	pusha
	xor	ecx,ecx
	mov	cx,[CURSOR_POS]
	xor esi,esi
	add	esi,ecx
	add	esi,ecx
	mov ah,0xC3
.199:
	mov	al, [ebx]
	cmp al,0
	jz .200
	inc ebx
	mov [gs:esi],al
	inc esi
	inc esi
	inc	cx
	jmp .199
.200:
	mov		[CURSOR_POS],cx
	call	RefreshCursorPos
	popa
ret

ClearScreen:
	push	es
	mov		ax,gs
	mov		es,ax
	mov		ax,0x3F00
	mov		ecx,25*80
	mov		edi,0
	rep		stosw
	pop		es
ret
