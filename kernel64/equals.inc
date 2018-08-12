kernel_location equ 0x1000

tmp_code_seg	equ tmp_code-tmp_dts
tmp_data_seg	equ tmp_data-tmp_dts
tmp_gcb_seg		equ tmp_gcb- tmp_dts

; Memory Addresses And Informatins
os_mem_req			equ	8			; Mega Byte
os_pml4				equ	0x40000		; Page Map Level 4 Address
os_stack			equ	0x30000
os_idt				equ	0x45000
os_apic				equ	0x5000

;  Paging
pg_p				equ	1			; Present
pg_wr				equ	1<<1		; Read And Write
pg_us				equ	1<<2		; User Or Supervisor
pg_pwt				equ	1<<3		; Page Write Through
pg_pcd				equ	1<<4		; Page-level Cache Disable
pg_a				equ	1<<5		; Accessed
pg_d				equ	1<<6		; Dirty
pg_ps				equ	1<<7		; Page Size
pg_g				equ	1<<8		; Page Global


;  CR0
cr0_pe				equ 1			; Protection Mode
cr0_mc				equ 1<<1		; Monitor Coprocessor
cr0_e				equ 1<<2		; Emulation
cr0_ts				equ 1<<3		; Task Switch
cr0_et				equ 1<<4		; Extension Type
cr0_ne				equ 1<<5		; Numberic Error
cr0_wp				equ 1<<16		; Write Protect
cr0_am				equ 1<<18		; Alignment Mask
cr0_nw				equ 1<<29		; No Write
cr0_cd				equ 1<<30		; Cache Disable
cr0_pg				equ 1<<31		; Paging

;  CR3
cr3_pcd				equ	1<<4		; Page Level Cache Disable
cr3_pwt				equ	1<<3		; Page Level Write

;	CR4
cr4_vme				equ	1			; Virtual-8086 Machine Extension
cr4_pvi				equ	1<<1		; Protection Mode Virtual Interrupts
cr4_tsd				equ	1<<2		; Time Stamp Disable
cr4_de				equ	1<<3		; Debugging Extensions
cr4_pse				equ	1<<4		; Page Size Extensions
cr4_pae				equ	1<<5		; Pysical Address Extension
cr4_mce				equ	1<<6		; Machine Check Enable
cr4_pge				equ	1<<7		; Page Global Enable
cr4_pce				equ	1<<8		; Performance Monitoring Counter Enable
cr4_osfxsr			equ	1<<9		; Operating System Support for FXSAVE and FXRSTOR instructions
cr4_osxmmexcpt		equ	1<<10		; Operating System Support for Unmasked SIMD Floating-Point Exceptions
cr4_vmxe			equ	1<<13		; VMX-Enable
cr4_smxe			equ	1<<14		; SMX-Enable
cr4_fsgsbase		equ	1<<16		; FSGSBASE-Enable
cr4_pcid			equ	1<<17		; PCID-Enable
cr4_osxsave			equ	1<<18		; XSAVE and Processor Extended States-Enable
cr4_smep			equ	1<<20		; SMEP-Enable

cpu_64ins			equ	1<<29


;	String Special Charectors
nl				equ	13
fl				equ	10
zs				equ	0

;	PIT
PIT_M_INT		equ		0	; PIT Mode : Interrupt On Terminal Count
PIT_M_OT		equ		2	; PIT Mode : Programmable One-Shot
PIT_M_RG		equ		4	; PIT Mode : Rate Generator
PIT_M_SW		equ		6	; PIT Mode : Square Wave Rate Generator
PIT_M_ST		equ		8	; PIT Mode : Software Triggered Strobe
PIT_M_HT		equ		10	; PIT Mode : Hardware Triggered Strobe
PIT_T0			equ		0
PIT_T1			equ		1<<6
PIT_T2			equ		2<<6
PIT_RB			equ		3<<6	; Read Back Command
PIT_RWF			equ		3<<4	; Write LSB , MSB
PIT_BF			equ		1193180	; Base Frequency

;	APIC
MSRAPICBase		equ	0x1B
MSRAPICEnable	equ	1<<11

LAPIC_ID		equ		os_apic+0x20
LAPIC_VERSION	equ		os_apic+0x30
LAPIC_TPR		equ		os_apic+0x80
LAPIC_APR		equ		os_apic+0x90
LAPIC_PPR		equ		os_apic+0xA0
LAPIC_EOI		equ		os_apic+0xB0
LAPIC_RRD		equ		os_apic+0xC0
LAPIC_LDR		equ		os_apic+os_apic+0xD0	; Logical Destination Register
LAPIC_DFR		equ		os_apic+0xE0	; Destination Format Register
LAPIC_SIVR		equ		os_apic+0xF0	; Spurious Interrupt Vector Register
LAPIC_ISR0		equ		os_apic+0x100	; In-Service Register (ISR)
LAPIC_ISR1		equ		os_apic+0x110
LAPIC_ISR2		equ		os_apic+0x120
LAPIC_ISR3		equ		os_apic+0x130
LAPIC_ISR4		equ		os_apic+0x140
LAPIC_ISR5		equ		os_apic+0x150
LAPIC_ISR6		equ		os_apic+0x160
LAPIC_ISR7		equ		os_apic+0x170
LAPIC_TMR0		equ		os_apic+0x180	; Trigger Mode Register
LAPIC_TMR1		equ		os_apic+0x190
LAPIC_TMR2		equ		os_apic+0x1A0
LAPIC_TMR3		equ		os_apic+0x1B0
LAPIC_TMR4		equ		os_apic+0x1C0
LAPIC_TMR5		equ		os_apic+0x1D0
LAPIC_TMR6		equ		os_apic+0x1E0
LAPIC_TMR7		equ		os_apic+0x1F0
LAPIC_IRR0		equ		os_apic+0x200	; Interrupt Request Register
LAPIC_IRR1		equ		os_apic+0x210
LAPIC_IRR2		equ		os_apic+0x220
LAPIC_IRR3		equ		os_apic+0x230
LAPIC_IRR4		equ		os_apic+0x240
LAPIC_IRR5		equ		os_apic+0x250
LAPIC_IRR6		equ		os_apic+0x260
LAPIC_IRR7		equ		os_apic+0x270
LAPIC_ESR		equ		os_apic+0x280	; Error Status Register
LAPIC_LVT_CMCI	equ		os_apic+0x2F0	; LVT CMCI Register
LAPIC_ICR0		equ		os_apic+0x300	; Interrupt Command Register
LAPIC_ICR1		equ		os_apic+0x310
LAPIC_LVT_TIMER equ		os_apic+0x320
LAPIC_LVT_TS	equ		os_apic+0x330	; LVT Thermal Sensor Register
LAPIC_LVT_PMC	equ		os_apic+0x340	; LVT Performance Monitoring Counters Register
LAPIC_LVT_LINT0 equ		os_apic+0x350	; LVT LINT0 Register
LAPIC_LVT_LINT1 equ		os_apic+0x360	; LVT LINT1 Register
LAPIC_LVT_ER	equ		os_apic+0x370	; LVT Error Register
LAPIC_TMR_ICR	equ		os_apic+0x380	; Timer : Initial Count Register
LAPIC_TMR_CCR	equ		os_apic+0x390	; Timer : Current Count Register
LAPIC_TMR_DCR	equ		os_apic+0x3E0	; Timer : Divide Configuration Register