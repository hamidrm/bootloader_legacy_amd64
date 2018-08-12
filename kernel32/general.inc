
hexval			db "0123456789ABCDEF"

machine_state:
	DB					0
	MS_EAX		dd		0
	MS_EBX		dd		0
	MS_ECX		dd		0
	MS_EDX		dd		0
	MS_CS		dw		0
	MS_DS		dw		0
	MS_ES		dw		0
	MS_GS		dw		0
	MS_FS		dw		0
	MS_SS		dw		0
	MS_EF		dd		0



save_machine_state:
	pushad
	mov		[MS_EAX],EAX
	mov		[MS_EBX],EBX
	mov		[MS_ECX],ECX
	mov		[MS_EDX],EDX
	mov		[MS_CS],CS
	mov		[MS_DS],DS
	mov		[MS_SS],SS
	mov		[MS_ES],ES
	mov		[MS_FS],FS
	mov		[MS_GS],GS
	pushfd
	pop		eax
	mov		[MS_EF],EAX
	sidt	[cs:old_idt]
	popad
ret