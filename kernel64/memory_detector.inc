; Memory Detector

get_memory:
	pushad
	mov		di,Memory_Map
	push	ds
	pop		es
	xor		bp,bp
	mov		eax,0xe820
	xor		ebx,ebx
	mov		ecx,24
	mov		edx,0x534D4150
	int		0x15
	jc		.0gm	;	Not Supported
	cmp		eax,0x534D4150
	jnz		.0gm
	test	ebx,ebx
	jz		.0gm
	jmp		.1gm
.2gm:
	mov		eax,0xe820
	mov		ecx,24
	mov		edx,0x534D4150
	int		0x15
.1gm:
	jc		.3gm
	jcxz	.4gm
	mov		eax,[es:di + 8]
	or		eax,[es:di + 12]
	jz		.4gm
	cmp		bp,32
	jz		.3gm
	add		di,24
	inc		bp
.4gm:
	test	ebx,ebx
	jnz		.2gm 	;	Not Ended Yet
.3gm:
	mov	[mmap_cnt],bp
	popad
	stc
	ret
.0gm:
	popad
	clc
	ret


get_memory2:
	mov		ax,0xe801
	xor		cx,cx
	xor		dx,dx
	int		0x15
	jc		.0gm2
	cmp		ah, 0x86
	jz		.0gm2
	cmp		ah,0x80
	jz		.0gm2
	jcxz	.1gm2
	mov		ax, cx
	mov		bx, dx
.1gm2:
	stc
	ret	
.0gm2:
	clc
	ret

getMemorySize:
	call	get_memory
	jnc		.0gms
	xor		eax,eax
	xor		esi,esi
	xor		bp,bp
	mov		esi,Memory_Map
.3gms:
	inc		bp
	mov		ebx,[esi+16]	
	cmp		bp,[mmap_cnt]
	jz		.4gms
	cmp		ebx,1
	jz		.2gms	
	add		esi,24
	jmp		.3gms
.2gms:

	mov		ebx,[esi+12]	;Lenght : Second DWORD
	mov		ecx,[esi+8]	;Lenght : First DWORD

	mov		eax,[Memory_Size]
	mov		edx,[Memory_Size+4]
	add		eax,ecx
	adc		edx,ebx

	mov		[Memory_Size],eax
	mov		[Memory_Size+4],edx

	cmp		bp,[mmap_cnt]
	jz		.4gms
	add		esi,24
	jmp		.3gms

.4gms:
	mov		ecx,[Memory_Size]
	mov		edx,[Memory_Size+4]

	mov		eax,ecx
	mov		ecx,1024*1024
	div		ecx
	mov		[Memory_Size_MB],ax
	stc
	ret
.0gms:
	call	get_memory2
	jnc		.1gms
	mov		ax,0x40
	mul		bx
	shl		edx,16
	add		eax,edx
	mov		bx,1024
	div		bx
	mov		[Memory_Size_MB],ax
	stc
	ret
.1gms:
	mov		ax,0
	clc
ret

Memory_Size_MB	dq	0xFFFF
Memory_Size	dd	0,0
mmap_cnt	db	0
Memory_Map:
	times 24*32 db 0