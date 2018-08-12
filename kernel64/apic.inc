;; Programmable Interrupt Controller



IOAPICEnable:
		;mov				ebx,0xFEC00000
		;mov			dword [0xFEC00000], 1
		;mov			edx,dword [0xFEC00000]
		;call		PrintQWH
ret


APICEnable:


	mov		ecx,MSRAPICBase
	rdmsr
	;mov		edx,eax
	;call	PrintQWH
	or		eax,MSRAPICEnable
	and		eax,0xFFF
	;mov		eax,[LAPIC_TMR_CCR]
	;call	PrintQWH
	or		eax,os_apic
	mov		ecx,MSRAPICBase
	wrmsr

	call	IOAPICEnable
	;invlpg	[MSRAPICBase]
	mov		eax,0xFFFFFFFF
	mov		[LAPIC_DFR],eax
	mov		[LAPIC_TMR_CCR],eax
		mov			eax, dword [LAPIC_LDR]
		and			eax, 00FFFFFFh
		or			al, 1
		mov			dword [LAPIC_LDR], eax


		mov			dword [LAPIC_LVT_PMC], (4<<8)
		mov			dword [LAPIC_LVT_LINT0], 0x10000
		mov			dword [LAPIC_LVT_LINT1], 0x10000
		mov			dword [LAPIC_TPR], 0

	mov		eax,0xFFFFFFFF
	mov		[LAPIC_TMR_ICR],eax

	mov		eax,0x0000A
	;mov		[LAPIC_TMR_DCR],eax
	
	;mov		eax,0x000EE
	;mov		[LAPIC_LVT_TIMER],eax


		mov			dword [LAPIC_SIVR], 33+LAPIC_ISR0
		;map APIC timer to an interrupt, and by that enable it in one-shot mode
		mov			dword [LAPIC_LVT_TIMER], 32

reget:
	mov		eax,[LAPIC_TMR_CCR]
	mov		edx,eax
	mov		edx,eax
	;call	PrintQWH
	test	eax,eax
	;jnz		reget
	
ret


