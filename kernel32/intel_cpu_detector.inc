

; Remeber that 8086/8088/80286/80386/80486 does not support cpuid instruction.
; Here is CPU information table

; CPU Names Table
CPU_8086						DB	"8086/8088",0
CPU_80286						DB	"80286",0
CPU_80386						DB	"80386",0
CPU_80486						DB	"80486",0
CPU_BRAND						DB	"                                                ",0
CPU_NAME						DD	0	

CPU_TYPE						DB	0
CPU_VENDOR_ID					DB	"            ",0
CPU_MAX_CPUID_FUNCTIONS_NUMBER	DD	0
CPU_MAX_CPUID_EFUNCTIONS_NUMBER	DD	0
CPU_SIGNATURE					DD	0
CPU_STEPPING_VALUE				DB	0
CPU_MODEL						DB	0
CPU_FAMILY						DB	0
CPU_PROCESSOR_TYPE				DB	0
CPU_PROCESSOR_TYPE1				DB	"Original OEM Processor",0
CPU_PROCESSOR_TYPE2				DB	"OverDrive® Processor  ",0
CPU_PROCESSOR_TYPE3				DB	"Dual Processor        ",0
CPU_PROCESSOR_TYPE4				DB	"Intel Reserved        ",0
CPU_EXTENDED_MODEL				DB	0
CPU_EXTENDED_FAMILY				DB	0
CPU_BRAND_INDEX					DB	0
CPU_CLFLUSH_LINE_SIZE			DB	0
CPU_LOGICAL_PROCESSOR_NUMBER	DB	0
CPU_APIC_ID						DB	0
CPU_PROCESSOR_TYPE_STRING		DD	0	
CPU_FEATURES1					DD	0
CPU_FEATURES2					DD	0
CPU_MODEL_VALUE					DB	0
CPU_FAMILY_VALUE				DB	0
CPU_CACHE_EAX					DD	0
CPU_CACHE_EBX					DD	0
CPU_CACHE_ECX					DD	0
CPU_CACHE_EDX					DD	0

CPU_CACHES_NUMBER				DB	0

CPU_CACHE1_FLAGS				DB	0
CPU_CACHE1_LSIZE				DW	0 ;1
CPU_CACHE1_LPARTITIONS			DW	0 ;3
CPU_CACHE1_WAYS					DW	0 ;5
CPU_CACHE1_TYPE					DB	0 ;7
CPU_CACHE1_LEVELE				DB	0 ;8
CPU_CACHE1_SI_FA_FLAGS			DB	0 ;9  ; Self Initializing Cache Level AND Fully Associative Cache Flags
CPU_CACHE1_MAX_THREADS_SHARED	DW	0 ;10
CPU_CACHE1_MAX_CORES			DB	0 ;12
CPU_CACHE1_SIZE					DD	0 ;13

CPU_CACHE2_FLAGS				DB	0
CPU_CACHE2_LSIZE				DW	0
CPU_CACHE2_LPARTITIONS			DW	0
CPU_CACHE2_WAYS					DW	0
CPU_CACHE2_TYPE					DB	0
CPU_CACHE2_LEVELE				DB	0
CPU_CACHE2_SI_FA_FLAGS			DB	0    ; Self Initializing Cache Level AND Fully Associative Cache Flags
CPU_CACHE2_MAX_THREADS_SHARED	DW	0
CPU_CACHE2_MAX_CORES			DB	0
CPU_CACHE2_SIZE					DD	0

CPU_CACHE3_FLAGS				DB	0
CPU_CACHE3_LSIZE				DW	0
CPU_CACHE3_LPARTITIONS			DW	0
CPU_CACHE3_WAYS					DW	0
CPU_CACHE3_TYPE					DB	0
CPU_CACHE3_LEVELE				DB	0
CPU_CACHE3_SI_FA_FLAGS			DB	0    ; Self Initializing Cache Level AND Fully Associative Cache Flags
CPU_CACHE3_MAX_THREADS_SHARED	DW	0
CPU_CACHE3_MAX_CORES			DB	0
CPU_CACHE3_SIZE					DD	0

CPU_CACHE4_FLAGS				DB	0
CPU_CACHE4_LSIZE				DW	0
CPU_CACHE4_LPARTITIONS			DW	0
CPU_CACHE4_WAYS					DW	0
CPU_CACHE4_TYPE					DB	0
CPU_CACHE4_LEVELE				DB	0
CPU_CACHE4_SI_FA_FLAGS			DB	0    ; Self Initializing Cache Level AND Fully Associative Cache Flags
CPU_CACHE4_MAX_THREADS_SHARED	DW	0
CPU_CACHE4_MAX_CORES			DB	0
CPU_CACHE4_SIZE					DD	0



; CPU	Monitoring

CPU_SMALLEST_MONITOR_LSIZE		DW	0
CPU_LARGEST_MONITOR_LSIZE		DW	0
CPU_MONITORING_FLAGS			DB	0
CPU_C0_MSUBSTATES_NUMBER		DB	0
CPU_C1_MSUBSTATES_NUMBER		DB	0
CPU_C2_MSUBSTATES_NUMBER		DB	0
CPU_C3_MSUBSTATES_NUMBER		DB	0
CPU_C4_MSUBSTATES_NUMBER		DB	0

CPU_INTERRUPT_THRESHOLDS_NUMBERS		DB	0
CPU_DTS_F1						DB	0
CPU_DTS_F2						DB	0

CPU_MAX_SUPPORTED_LEAF			DD	0
CPU_PLATFORM_DCA_CAP			DD	0

CPU_M_COUNTERS_NUMBER			DB	0
CPU_M_COUNTERS_BITS_NUMBER		DB	0
CPU_M_FEATURES					DB	0
CPU_M_VERSION_ID				DB	0
CPU_M_COUNTERS_PER_LP_NUMBER	DB	0
CPU_M_COUNTERS_PER_LP_BITWIDTH	DB	0
CPU_M_LENGTH_EBX_BIT_VECTOR		DB	0

CPU_EXT_FEATURES1				DD	0
CPU_EXT_FEATURES2				DD	0

CPU_L2_CACHE_LSIZE				DB	0
CPU_L2_CACHE_SIZE				DW	0
CPU_L2_CACHE_ASSOCIATIVITY		DB	0

CPU_APM_DETAILS					DB	0

CPU_PHYSICAL_ADDR_SIZE			DB	0
CPU_VIRTUAL_ADDR_SIZE			DB	0

CPU_SERIAL						DD	0,0,0

fps								DW	0
; Some constant
CPU_SSE3			equ		1
CPU_PCLMULDQ		equ		1<<1
CPU_DTES64			equ		1<<2
CPU_MONITOR			equ		1<<3
CPU_DS_CPL			equ		1<<4
CPU_VMX				equ		1<<5
CPU_SMX				equ		1<<6
CPU_EIST			equ		1<<7
CPU_TL2				equ		1<<8
CPU_SSSE3			equ		1<<9
CPU_CNXT_ID			equ		1<<10
CPU_FMA				equ		1<<12
CPU_CX16			equ		1<<13
CPU_xTPR			equ		1<<14
CPU_PDCM			equ		1<<15
CPU_PCID			equ		1<<17
CPU_DCA				equ		1<<18
CPU_SSE4.1			equ		1<<19
CPU_SSE4.2			equ		1<<20
CPU_x2APIC			equ		1<<21
CPU_MOVBE			equ		1<<22
CPU_POPCNT			equ		1<<23
CPU_TSC_DEADLINE	equ		1<<24
CPU_AES				equ		1<<25
CPU_XSAVE			equ		1<<26
CPU_OSXSAVE			equ		1<<27
CPU_AVX				equ		1<<28
CPU_F16C			equ		1<<29
CPU_RDRAND			equ		1<<30

CPU_FPU				equ		1<<32
CPU_VME				equ		1<<33
CPU_DE				equ		1<<34
CPU_PSE				equ		1<<35
CPU_TSC				equ		1<<36
CPU_MSR				equ		1<<37
CPU_PAE				equ		1<<38
CPU_MCE				equ		1<<39
CPU_CX8				equ		1<<40
CPU_APIC			equ		1<<41
CPU_SEP				equ		1<<43
CPU_MTRR			equ		1<<44
CPU_PGE				equ		1<<45
CPU_MCA				equ		1<<46
CPU_CMOV			equ		1<<47
CPU_PAT				equ		1<<48
CPU_PSE36			equ		1<<49
CPU_PSN				equ		1<<50
CPU_CLFSH			equ		1<<51
CPU_DS				equ		1<<53
CPU_ACPI			equ		1<<54
CPU_MMX				equ		1<<55
CPU_FXSR			equ		1<<56
CPU_SSE				equ		1<<57
CPU_SSE2			equ		1<<58
CPU_SS				equ		1<<59
CPU_HTT				equ		1<<60
CPU_TM				equ		1<<61
CPU_PBE				equ		1<<63


; here is a macro for checking this that : CPU does support input feature?
; Output : CF
%macro CPUDS 1             ; CPU Does Support %1 ? 
	pushad
%if	%1>0x80000000
	mov	eax,%1>>32
	mov	ebx,[CPU_FEATURES2]
%else
	mov	eax,%1
	mov	ebx,[CPU_FEATURES1]
%endif
	test	eax,ebx
	jz		.0ds
	popad
	stc
	jmp	.1sd
.0ds:
	popad
	clc
.1sd:
%endmacro






get_cpu:
	pusha
	; First we must check that : is it a 8086/8088?
	pushf
	pop ax
	and ax,0xfff
	push ax
	popf
	pushf
	pop ax
	and	ax,0xF000
	cmp ax,0xF000
	jnz .1gc              ; it is not a 8086/8088 , perhaps it is a 80286 , then let's test it!
	push  sp              ; Another test for have certain 8086/8088
	pop   dx
	cmp dx,sp
	jnz .2gc              ; it is actualy a 8086/8088
	popa
	mov	byte [CPU_TYPE],0     ; it is an unknow proccessor
	ret
.2gc:
	popa
	mov	dword	[CPU_NAME],CPU_8086
	mov byte [CPU_TYPE],1
	ret
.1gc:
	pushf
	pop ax
	or ax,0xf000
	push ax
	popf
	pushf
	pop ax
	test ax,0xf000
	jnz .3gc
	popa
	mov byte [CPU_TYPE],2               ; it is a 80286
	mov	dword	[CPU_NAME],CPU_80286
	ret
.3gc:
	popa
	pushad
	pushfd
	pop eax
	mov ebx,eax
	xor eax,0x40000
	push eax
	popfd
	pushfd
	pop eax
	xor eax,ebx
	cmp	eax,0
	jnz .4gc
	mov byte [CPU_TYPE],3   ; it is a 80386
	mov	dword	[CPU_NAME],CPU_80386
	popad
	ret
.4gc:
	pushfd
	pop eax
	or eax,0x200000
	push eax
	popfd
	pushfd
	pop eax
	test eax,0x200000
	jnz .5gc
	popad
	mov byte [CPU_TYPE],4   ; it is a 80486
	mov	dword	[CPU_NAME],CPU_80486
	ret
.5gc:                     ; Ahhhhh! We can use from cpuid now!

	xor eax,eax
	cpuid
	mov DWORD [CPU_MAX_CPUID_FUNCTIONS_NUMBER],eax
	mov DWORD [CPU_VENDOR_ID+0],ebx
	mov DWORD [CPU_VENDOR_ID+4],edx
	mov DWORD [CPU_VENDOR_ID+8],ecx
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	
	


	cmp	al,1
	jb	.6gc
	
		
	mov eax,1
	cpuid
	push ebx
	mov ebx,eax
	and ebx,0xF
	mov	byte [CPU_STEPPING_VALUE],bl
	mov	ebx,eax
	and	ebx,0xF0
	shr	ebx,4
	mov	byte [CPU_MODEL],bl
	mov	ebx,eax
	and	ebx,0xF00
	shr	ebx,8
	mov	byte [CPU_FAMILY],bl
	mov	ebx,eax
	and	ebx,11000000000000b
	shr	ebx,12
	mov	byte [CPU_PROCESSOR_TYPE],bl
	mov	ebx,eax
	and	ebx,0xF0000
	shr	ebx,16
	mov	byte [CPU_EXTENDED_MODEL],bl
	mov	ebx,eax
	and	ebx,0xFF00000
	shr	ebx,20
	mov	byte [CPU_EXTENDED_FAMILY],bl
	pop	ebx
	mov	eax,ebx
	and	eax,0xFF
	mov	byte [CPU_BRAND_INDEX],al
	mov	eax,ebx
	and	eax,0xFF00
	shr	eax,8
	mov	byte [CPU_CLFLUSH_LINE_SIZE],al
	mov	eax,ebx
	and	eax,0xFF0000
	shr	eax,16
	mov	byte [CPU_LOGICAL_PROCESSOR_NUMBER],al
	mov	eax,ebx
	and	eax,0xFF000000
	shr	eax,24
	mov	byte [CPU_APIC_ID],al
	xor	eax,eax
	mov	bl,23
	mov	al,[CPU_PROCESSOR_TYPE]
	mul	bl
	add eax,CPU_PROCESSOR_TYPE
	inc	eax
	mov	DWORD [CPU_PROCESSOR_TYPE_STRING],eax
	mov	DWORD [CPU_FEATURES1],ecx
	mov	DWORD [CPU_FEATURES2],edx
	mov	al,[CPU_EXTENDED_FAMILY]
	add	al,[CPU_FAMILY]
	mov byte [CPU_FAMILY_VALUE],al
	mov	al,[CPU_EXTENDED_MODEL]
	shl	al,4
	add	al,[CPU_MODEL]
	mov byte [CPU_MODEL_VALUE],al





	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,2
	jb	.6gc
	mov	eax,2
	cpuid
	mov	[CPU_CACHE_EAX],eax   ; yesssss...! I know that the value of AL may be more than 1 , but not available cpu that have this feature yet. then we think that max chaches memory is 16.
	mov	[CPU_CACHE_EBX],ebx
	mov	[CPU_CACHE_ECX],ecx
	mov	[CPU_CACHE_EDX],edx


	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,4
	jb	.6gc
	mov	eax,4
	;fill the chaches memory features
	xor	ecx,ecx
	xor	esi,esi
	mov	di,CPU_CACHE1_FLAGS
.8gc:
	cpuid
	test	al,0xF
	jz		.7gc
	cmp		si,4			; We will have only 4 chache information at our table
	jae		.9gc
	push eax
	and	edx,0xF
	mov	byte [di],dl
	mov	eax,ebx
	and	eax,0xFFF
	inc	ax
	mov	word [di+1],ax
	mov eax,ebx
	and	eax,1111111111000000000000b
	shr	eax,12
	inc	ax
	mov	word [di+3],ax
	mov eax,ebx
	and	eax,11111111110000000000000000000000b
	shr	eax,22
	inc ax
	mov word [di+5],ax
	pop	eax
	mov ebx,eax
	and	ebx,11111b
	mov byte [di+7],bl
	mov ebx,eax
	and	ebx,11100000b
	shr	ebx,5
	mov byte [di+8],bl
	mov ebx,eax
	and	ebx,1100000000b
	shr	ebx,8
	mov byte [di+9],bl
	mov ebx,eax
	and	ebx,11111111111100000000000000b
	shr	ebx,14
	mov word [di+10],bx
	mov ebx,eax
	and	ebx,11111100000000000000000000000000b
	shr	ebx,26
	inc	bx
	mov [di+12],bl
	inc	ecx
	; Calculate Cache size in Bytes
	xor	eax,eax
	xor	edx,edx
	xor	ebx,ebx
	mov	bx,[di+1]
	mov	ax,[di+3]
	mul	ebx
	mov	bx,[di+5]
	mul	ebx
	mul	ecx
	mov [di+13],eax
.9gc:
	mov	eax,4
	inc	esi
	mov	ecx,esi
	add	di,17
	jmp	.8gc
.7gc:
	mov	ax,si
	mov	[CPU_CACHES_NUMBER],al
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,5
	jb	.6gc
	mov	eax,5
	cpuid
	mov	[CPU_SMALLEST_MONITOR_LSIZE],AX
	mov	[CPU_LARGEST_MONITOR_LSIZE],BX
	and	ECX,0xF
	mov	[CPU_MONITORING_FLAGS],CL
	mov	EAX,EDX
	and	eax,0xf
	mov	[CPU_C0_MSUBSTATES_NUMBER],al
	mov	EAX,EDX
	and	eax,0xf0
	shr	eax,4
	mov	[CPU_C1_MSUBSTATES_NUMBER],al
	mov	EAX,EDX
	and	eax,0xf00
	shr	eax,8
	mov	[CPU_C2_MSUBSTATES_NUMBER],al
	mov	EAX,EDX
	and	eax,0xf000
	shr	eax,12
	mov	[CPU_C3_MSUBSTATES_NUMBER],al
	mov	EAX,EDX
	and	eax,0xf0000
	shr	eax,16
	mov	[CPU_C4_MSUBSTATES_NUMBER],al
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,6
	jb	.6gc
	mov		eax,6
	cpuid
	and	ebx,0xf
	mov	[CPU_INTERRUPT_THRESHOLDS_NUMBERS],bl
	and	al,1111111b
	mov	[CPU_DTS_F1],al
	and	cl,0xf
	mov	[CPU_DTS_F2],cl
	jmp	$
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,7
	jb	.6gc
	mov	eax,7
	cpuid
	mov	[CPU_MAX_SUPPORTED_LEAF],eax
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,9
	jb	.6gc
	mov	eax,9
	cpuid
	mov	[CPU_PLATFORM_DCA_CAP],eax
	mov	al,[CPU_MAX_CPUID_FUNCTIONS_NUMBER]
	cmp	al,0xA
	jb	.6gc
	mov	eax,0xA
	cpuid
	mov	ecx,edx
	and	ECX,11111b
	mov	[CPU_M_COUNTERS_NUMBER],cl
	mov	ecx,edx
	and	ECX,1111111100000b
	shr	eax,5
	mov	[CPU_M_COUNTERS_BITS_NUMBER],cl
	and	bx,1111111b
	mov	[CPU_M_FEATURES],bl
	mov	ebx,eax
	and	ebx,0xff
	mov	[CPU_M_VERSION_ID],bl
	mov	ebx,eax
	and	ebx,0xff00
	shr	ebx,8
	mov	[CPU_M_COUNTERS_PER_LP_NUMBER],bl
	and	ebx,0xff0000
	shr	ebx,16
	mov	[CPU_M_COUNTERS_PER_LP_BITWIDTH],bl
	and	ebx,0xff000000
	shr	ebx,24
	mov	[CPU_M_LENGTH_EBX_BIT_VECTOR],bl
	;CPUID(B) => this function not neccessery currently , this use to detect APIC and processors topology
	;CPUID(D) => this function not neccessery currently , this use to detect XSAVE features
	;Extended functions
.6gc:

	mov	eax,0x80000000
	cpuid
	mov	[CPU_MAX_CPUID_EFUNCTIONS_NUMBER],eax
	mov	eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp	eax,0x80000001
	jb	.10gc
	mov	eax,0x80000001
	cpuid
	mov	eax,ecx
	mov	[CPU_EXT_FEATURES1],eax
	mov	eax,edx
	mov	[CPU_EXT_FEATURES2],eax
	mov	eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp	eax,0x80000004
	jb	.10gc	
	mov eax,0x80000002
	cpuid
	mov DWORD [CPU_BRAND],EAX
	mov	eax,ebx
	mov DWORD [CPU_BRAND+4],EAX
	mov	eax,ecx
	mov DWORD [CPU_BRAND+8],EAX
	mov	eax,edx
	mov DWORD [CPU_BRAND+12],EAX
	mov eax,0x80000003
	cpuid
	mov DWORD [CPU_BRAND+16],EAX
	mov	eax,ebx
	mov DWORD [CPU_BRAND+20],EAX
	mov	eax,ecx
	mov DWORD [CPU_BRAND+24],EAX
	mov	eax,edx
	mov DWORD [CPU_BRAND+28],EAX
	mov eax,0x80000004
	cpuid
	mov DWORD [CPU_BRAND+32],EAX
	mov	eax,ebx
	mov DWORD [CPU_BRAND+36],EAX
	mov	eax,ecx
	mov DWORD [CPU_BRAND+40],EAX
	mov	eax,edx
	mov DWORD [CPU_BRAND+44],EAX
	mov	DWORD [CPU_NAME],CPU_BRAND
	mov	eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp	eax,0x80000006
	jb	.10gc
	mov	eax,0x80000006
	cpuid
	mov	eax,ecx
	and	eax,0xff
	mov	[CPU_L2_CACHE_LSIZE],al
	mov	eax,ecx
	and	eax,0xf000
	shr	eax,12
	mov	[CPU_L2_CACHE_ASSOCIATIVITY],al
	mov	eax,ecx
	and	eax,0xffff0000
	shr	eax,16
	mov	[CPU_L2_CACHE_SIZE],ax
	mov	eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp	eax,0x80000007
	jb	.10gc
	mov	eax,0x80000007
	cpuid
	shr	edx,8
	mov	[CPU_APM_DETAILS],dl
	mov	eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp	eax,0x80000008
	jb	.10gc
	mov	eax,0x80000008
	cpuid
	mov	ebx,eax
	and	eax,0xff
	shr	ebx,8
	and	ebx,0xff
	mov	[CPU_PHYSICAL_ADDR_SIZE],al
	mov	[CPU_VIRTUAL_ADDR_SIZE],bl
	mov	eax,1
	cpuid
	mov	DWORD [CPU_SERIAL],eax
	mov	eax,3
	cpuid
	mov	DWORD [CPU_SERIAL+1],edx
	mov	DWORD [CPU_SERIAL+2],ecx
	popad
	ret
.10gc:
	popad
	ret



get_fpu:
	pushad
	xor		bx,bx
	fninit
	mov		word [fps],0x5a5a
	fnstsw	[fps]
	mov		ax,[fps]
	test	al,al
	jnz		.0gf
	fnstcw	[fps]
	mov		ax,[fps]
	and		ax,0x103f
	cmp		ax,0x3f
	jnz		.0gf
	stc
	popad
	ret
.0gf:
	clc
	popad
	ret


;get_ferequency:
;	CPUDS	CPU_TSC
;	jnc		.0gfy
;	mov		ecx,0x10
;	rdmsr
;	push	eax
;	push	edx
;	mov		ecx,0xffffffff
;.1gfy:
;	nop
;	nop
;	nop
;	nop
;	nop
;	loop	.1gfy
;	rdmsr
;	sub
;.0gfy:
;ret