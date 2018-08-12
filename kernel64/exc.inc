;   Exceptions


;	Divide Error
;	#DE
int00:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV]
	call	putc
	mov		al,[EXV+1]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Reserved
;	#DB
int01:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+2]
	call	putc
	mov		al,[EXV+3]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	NMI - Nonmaskable external interrupt

int02:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+4]
	call	putc
	mov		al,[EXV+5]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Breakpoint
;	#BP
int03:
	cli
	push	RSI
	push	RDX
	push	RCX
	push	RBX
	push	RAX
	push	rdx
	push	rcx
	push	rbx
	mov		ebx,BREAKPS
	call	PrintMsg

	mov		ebx,RAX_VAL
	call	PrintMsg
	call	PrintQWH

	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RBX_VAL
	call	PrintMsg
	pop		rbx
	mov		RAX,RBX
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RCX_VAL
	call	PrintMsg
	pop		rcx
	mov		RAX,RCX
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RDX_VAL
	call	PrintMsg
	pop		rdx
	mov		RAX,RDX
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RSI_VAL
	call	PrintMsg
	mov		RAX,RSI
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RDI_VAL
	call	PrintMsg
	mov		RAX,RDI
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,CR0_VAL
	call	PrintMsg
	mov		RAX,CR0
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,CR2_VAL
	call	PrintMsg
	mov		RAX,CR2
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,CR3_VAL
	call	PrintMsg
	mov		RAX,CR3
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,CR4_VAL
	call	PrintMsg
	mov		RAX,CR4
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,RSP_VAL
	call	PrintMsg
	mov		RAX,RSP
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,CS_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,CS
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,DS_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,DS
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,SS_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,SS
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,GS_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,GS
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,FS_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,FS
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,ES_VAL
	call	PrintMsg
	xor		rax,rax
	mov		AX,ES
	call	PrintQWH
	mov		ebx,ENDL
	call	PrintMsg

	mov		ebx,BREAKPE
	call	PrintMsg

	pop		RAX
	pop		RBX
	pop		RCX
	pop		RDX
	pop		RSI
	sti
iretq

;	Overflow
;	#OF
int04:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+6]
	call	putc
	mov		al,[EXV+7]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	BOUND Range Exceeded
;	#UD
int06:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+8]
	call	putc
	mov		al,[EXV+9]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Invalid Opcode
;	#BR
int05:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+10]
	call	putc
	mov		al,[EXV+11]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Device Not Available
;	#NM
int07:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+12]
	call	putc
	mov		al,[EXV+13]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Double Fault
;	#DF
int08:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+14]
	call	putc
	mov		al,[EXV+15]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Coprocessor Segment Overrun

int09:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+16]
	call	putc
	mov		al,[EXV+17]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Invalid TSS
;	#TS
int0a:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+18]
	call	putc
	mov		al,[EXV+19]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Segment Not Present
;	#NP
int0b:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+20]
	call	putc
	mov		al,[EXV+21]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Stack-Segment Fault
;	#SS
int0c:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+22]
	call	putc
	mov		al,[EXV+23]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	General Protection
;	#GP
int0d:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+24]
	call	putc
	mov		al,[EXV+25]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Page Fault
;	#PF
int0e:

iretq

;	x87 FPU Floating-Point Error
;	#MF
int10:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+26]
	call	putc
	mov		al,[EXV+27]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Alignment Check
;	#AC
int11:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+28]
	call	putc
	mov		al,[EXV+29]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Machine Check
;	#MC
int12:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+30]
	call	putc
	mov		al,[EXV+31]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	SIMD Floating-Point Exception
;	#XM
int13:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+32]
	call	putc
	mov		al,[EXV+33]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq

;	Virtualization Exception
;	#VE
int14:
	push	RBX
	push	RAX
	mov		ebx,EIO
	call	PrintMsg
	mov		al,[EXV+34]
	call	putc
	mov		al,[EXV+35]
	call	putc
	mov		rbx,ENDL
	call	PrintMsg
	pop		RAX
	pop		RBX
iretq