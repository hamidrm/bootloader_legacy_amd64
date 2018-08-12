[BITS 32]
;   Output : AL=>CPU TYPE
DoesSupportCPUID:
	pushad
	pushf
	pop eax
	or eax,0x200000
	push eax
	popf
	pushf
	pop eax
	test eax,0x200000
	jz .0
	popad
	stc
	ret
.0:
	popad
	clc
ret

get_cpu_brand:
	pushad
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
	popa
	mov ebx,CPU_NAMEA
	call PrintMsg
	ret
.2:              ; Brand String Future Does Not Supported!
	mov eax,1
	cpuid
	cmp	bl,0
	jnz .2
	popad
	ret
.1:
	popad
	ret
ret




CPU_NAMEA db "                                                ",0