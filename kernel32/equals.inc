kernel_location equ 0x1000

tmp_code_seg	equ tmp_pmcode-tmp_pms
tmp_data_seg	equ tmp_pmdata-tmp_pms
tmp_gcb_seg		equ tmp_gcb-   tmp_pms

cr0_pm			equ 1