

GetCPUValidition:
	mov		eax,[CPU_EXT_FEATURES2]
	test	eax,cpu_64ins
	jz		.0gcv
	stc
	ret
.0gcv:
	clc
ret

OldCPU:
	mov		eax,[CPU_MAX_CPUID_EFUNCTIONS_NUMBER]
	cmp		eax,1
	jbe		.oc
	clc
	ret
.oc:
	stc
ret