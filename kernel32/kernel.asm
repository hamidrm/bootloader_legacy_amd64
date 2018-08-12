
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


%include "stdlib16.inc"
%include "memory_detector.inc"
%include "intel_cpu_detector.inc"
%include "data_map16.inc"
%include "equals.inc"
%include "general.inc"
%include "vesa.inc"







start:
call	save_machine_state
;call	get_vbe_information
cli
call EnableA20
lgdt [tmp_pmr]
mov	eax,cr0
or eax,cr0_pm
mov cr0,eax
jmp tmp_code_seg:tpm_start
[BITS 32]
tpm_start:
mov	ax,tmp_data_seg
mov	ds,ax
mov	ax,tmp_gcb_seg
mov gs,ax
call	ClearScreen
call	ShowCursor
mov		ebx,msg1
call	PrintMsg
;call	RefreshCursorPos
jmp $

%include "stdlib32.inc"
%include "tmode.inc"
;[bits 16]

msg1 db "hello from protected mode!",0