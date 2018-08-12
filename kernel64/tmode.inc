CURSOR_POS		DW		0


HideCursor:

	mov		al,0xA
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x07
	mov		dx,0x3D5
	out		dx,al

	mov		al,0xB
	mov		dx,0x3D4
	out		dx,al
	mov		al,0x07
	mov		dx,0x3D5
	out		dx,al
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
	push	rax
.2pm:
	mov		al, [ebx]
	cmp		al,0
	jz		.3pm
	inc		ebx
	cmp		al,10
	jnz		.0pm
	add		word[CURSOR_POS],80
	jmp		.2pm

.1pm:
	push	rbx
	xor		rdx,rdx
	mov		ax,[CURSOR_POS]
	mov		bx,80
	div		bx
	sub		[CURSOR_POS],dx
	pop		rbx
	jmp		.2pm

.0pm:
	cmp		al,13
	jz		.1pm
	call	putc
	jmp		.2pm
.3pm:
	call	RefreshCursorPos
	pop		rax
ret

hexval		db	"0123456789ABCDEF"

PrintQWH:
	push	rax
	push	rbx
	push	rcx
	push	rdx
	push	rsi
	xor		rdx,rdx
	mov		rbx,rax
	mov		al,'0'
	call	putc
	mov		al,'x'
	call	putc
.0pqwh:
	mov		rax,rbx
	shr		rax,60
	and		rax,0xF
	add		rax,hexval
	mov		rsi,rax
	mov		al,[rsi]
	call	putc
	shl		rbx,4
	inc		dl
	cmp		dl,16
	jnz		.0pqwh
	call	RefreshCursorPos
	pop		rsi
	pop		rdx
	pop		rcx
	pop		rbx
	pop		rax
ret

putc:
	xor		ecx,ecx
	mov		cx,[CURSOR_POS]
	cmp		cx,2000
	jl		.0pc
	call	ScrollDown
.0pc:
	mov		esi,ecx
	add		esi,ecx
	mov		[gs:esi],al
	inc		cx
	mov		[CURSOR_POS],cx
ret

ScrollDown:
	push	rbx
	push	rcx
	push	rdx
	mov		rbx,0xb80A0
	mov		rcx,384
	mov		rsi,0xb8000
.0sd:
	mov		rdx,[rbx]
	mov		[rsi],rdx
	add		rbx,8
	add		rsi,8
	loop	.0sd
	sub		word[CURSOR_POS],80
	pop		rdx
	pop		rcx
	pop		rbx
ret

ClearScreen:
	mov		rax,0x3F00
	mov		ecx,25*80	
	xor		esi,esi	
.0cs:
	mov		[gs:esi],ax
	add		esi,2
	loop	.0cs
ret
