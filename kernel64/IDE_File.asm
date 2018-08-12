
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;       This is ZOS Kernel Part0            ;;
;;        By Hamid Reza Mehrabian            ;;
;;        hr_mehrabian@yahoo. com            ;;
;;             Version 0.1.0                 ;;
;;                 2/2013                    ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


[BITS 16]
[ORG 0x1000]




jmp start
[BITS	64]
;	Interrupts	Vector	Table
ivts:
	jmp		int00
	jmp		int01
	jmp		int02
	jmp		int03
	jmp		int04
	jmp		int05
	jmp		int06
	jmp		int07
	jmp		int08
	jmp		int09
	jmp		int0a
	jmp		int0b
	jmp		int0c
	jmp		int0d
	jmp		int0e
	times	5 DB 0
	jmp		int10
	jmp		int11
	jmp		int12
	jmp		int13
	jmp		int14
	times	5*14 DB 0
	jmp		intVB
	jmp		intVB
	;.....
	times	1280-($-ivts) DB 0
ivte:

%include "exc.inc"

[BITS	16]

%include "stdlib16.inc"
%include "init16.inc"
%include "memory_detector.inc"
%include "intel_cpu_detector.inc"
%include "data.inc"
%include "equals.inc"
%include "general.inc"
%include "strings.inc"
%include "memory.inc"




start:
cli
call	get_cpu

call	OldCPU
jnc		.01k
mov		si,CPU_TOO_OLD
jmp		.1k

.01k:
call	getMemorySize
jc		.02k
mov		si,BIOS_TOO_OLD
jmp		.1k

.02k:
mov		ax,[Memory_Size_MB]
cmp		ax,os_mem_req
ja		.03k
mov		si,MEMORY_TOO_LOW
jmp		.1k

.03k:
mov		eax,[CPU_FEATURES2]
test	eax,1<<4
jnz		.04k
mov		si,CPU_TOO_OLD
jmp		.1k


.04k:
call	GetCPUValidition
jc		.0k
mov		si,CPU_64BIT_NOT_SUPPORTED

.1k:
call	prt_msg
mov		si,PressKey
call	prt_msg
call	WaitForKey
call	Restart

.0k:
call	EnableA20
call	Page4LInit
call	idt_init

lgdt	[tmp_dtr]
lidt	[tmp_itr]

mov		eax,cr4
or		eax,cr4_pae | cr4_pge
mov		cr4,eax

mov ecx, 0xc0000080
rdmsr
or	eax, 0x00000100
wrmsr

mov	edx,os_pml4
mov	cr3,edx

mov	eax,cr0
or eax,cr0_pe | cr0_pg
and	eax,~cr0_cd
and	eax,~cr0_nw
mov cr0,eax

jmp tmp_code_seg:tpm_start

[BITS 64]

tpm_start:

mov		rax,os_stack
mov		rsp,rax
mov		ax,tmp_data_seg
mov		ds,ax
mov		ax,tmp_gcb_seg
mov		gs,ax
call	ShowCursor
call	ClearScreen
mov		ebx,msg1
call	PrintMsg
mov		rax,0x123456789abcdef0
mov		rbx,0x123456789abcdebc
mov		rcx,0x123456789abcdebc
mov		rdx,0x123456789abcdebc

   mov      al,0xff
   out      0x21,al      ; Disable IRQ0
sti


int		3

call	APICEnable
mov		ax,8200
mov		ebx,1000
call	Beep
mov		ebx,5000
call	Delay
mov		ax,8200
mov		ebx,10000
call	Beep

;cli
;hlt
jmp $


intVB:
mov		ebx,msg5
call	PrintMsg
IRETQ



%include "stdlib64.inc"
%include "tmode.inc"
%include "apic.inc"
%include "pit.inc"
;[bits 16]

msg1 db "Hello World !",nl,fl,"From Long Mode (64Bit) Land !",nl,fl,zs
msg5 db "iRetq Worked !",nl,fl,zs