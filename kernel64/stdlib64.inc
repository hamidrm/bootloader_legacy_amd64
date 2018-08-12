[BITS 64]
;   Output : AL=>CPU TYPE
DoesSupportCPUID:
	pushfq
	pop rax
	or eax,0x200000
	push rax
	popfq
	pushfq
	pop rax
	test rax,0x200000
	jz .0
	stc
	ret
.0:
	clc
ret

get_cpu_brand:
	call DoesSupportCPUID
	jnc .1
	mov eax,0x80000000
	cpuid
	cmp eax,0x80000004
	jb	.2
	mov eax,0x80000002
	cpuid
	mov DWORD [CPU_NAMEA],EAX
	mov DWORD [CPU_NAMEA+4],EBX
	mov DWORD [CPU_NAMEA+8],ECX
	mov DWORD [CPU_NAMEA+12],EDX
	mov eax,0x80000003
	cpuid
	mov DWORD [CPU_NAMEA+16],EAX
	mov DWORD [CPU_NAMEA+20],EBX
	mov DWORD [CPU_NAMEA+24],ECX
	mov DWORD [CPU_NAMEA+28],EDX
	mov eax,0x80000004
	cpuid
	mov DWORD [CPU_NAMEA+32],EAX
	mov DWORD [CPU_NAMEA+36],EBX
	mov DWORD [CPU_NAMEA+40],ECX
	mov DWORD [CPU_NAMEA+44],EDX
	mov ebx,CPU_NAMEA
	call Print_Msg
	ret
.2:              ; Brand String Future Does Not Supported!
	mov eax,1
	cpuid
	cmp	bl,0
	jnz .2
	ret
.1:
	ret
ret

Print_Msg:
	xor esi,esi
	mov ah,0xC3
.199:
	mov	al, [ebx]
	cmp al,0
	jz .200
	inc ebx
	mov [gs:esi],al
	inc esi
	inc esi
	jmp .199
.200:
ret

Clear_Screen:
	mov		rax,0x3F00
	mov		ecx,25*80	
	xor		esi,esi	
.0cs:
	mov		[gs:esi],ax
	add		esi,2
	loop	.0cs
ret

Hide_Cursor:
	mov	dx,0x3D4
	mov	al,0xA
	out	dx,al
	mov	al,0x0
	mov	dx,0x3D5
	out	dx,al

	mov	dx,0x3D4
	mov	al,0xB
	out	dx,al
	mov	al,0x0
	mov	dx,0x3D5
	out	dx,al
ret


CPU_NAMEA db "                                                ",0