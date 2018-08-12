;	Some things are wrong here. I will complete this at future
;	AX : Frequency
;	BX : Lentgh
Beep:
 push   rbx
   push   rax
   mov      al,PIT_M_SW|PIT_RWF|PIT_T2
   out      0x43,al
   pop      rax
   mov      bx,ax
   mov      eax,PIT_BF/2
   mov      edx,eax
   and      edx,0xFFFF0000
   shr      edx,16
   ;div      bx
   mov		dx,100
   mov		ax,100
   push   ax
   out      0x42,al
   mov      al,ah
   out      0x42,al
   xor      rax,rax
   in      al,0x61
   or      al,3
   out      0x61,al
   pop      ax
   pop      rbx
   mul      bx
   xor      ebx,ebx
   and      eax,0xFFFF
   mov      ebx,eax
   and      edx,0xFFFF
   shl      edx,16
   or      ebx,edx
_b0:
   in      al,0x61
   and      al,1<<5
   jz      _b0
   dec      ebx
   jnz      _b0
   in      al,0x61
   and      al,0xFE
   out      0x61,al
ret

Delay:
	xor		edx,edx
	and		eax,0xFFFF
	mov		ax,bx
	mov		bx,PIT_BF/2000
	mul		bx
	shl		edx,16
	or		eax,edx
	mov		ebx,eax
	mov		al,1
	out		0x42,al
	in		al,0x60
	mov		al,0
	out		0x42,al
	in		al,0x61
	and		al,0xFD
	out		0x61,al
_d0:
	in		al,0x61
	and		al,1<<5
	jz		_d0
	dec		ebx
	jnz		_d0
ret