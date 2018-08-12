GetMPT:

	;Test Area 1 (EBDA)
	;Test Area 2 (639KB-640KB)
	mov		si,0xFC00
	mov		ax,0x9000
	mov		es,ax
	mov		ecx,0x400
cnext_byte:
	mov		al,'_'
	cmp		[es:si],al
	jnz		not_found_here
	mov		al,'M'
	cmp		[es:si+1],al
	jnz		not_found_here
	mov		al,'P'
	cmp		[es:si+2],al
	jnz		not_found_here
	mov		al,'_'
	cmp		[es:si+3],al
	jnz		not_found_here
	mov		 ebx,msg1
	mov		si,CPU_TOO_OLD
	call	prt_msg
jmp	$
	ret
not_found_here:
	inc		ebx
	loop	cnext_byte
	;Test Area 3 (BIOS ROM)

ret