
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;        This is ZOS Boot Loader            ;;
;;        By Hamid Reza Mehrabian            ;;
;;             Version 0.1.0                 ;;
;;               10/2/2013                   ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[BITS 16]
	jmp	start   ; Howw! Let's go to start the program! 
%include 'floppy.inc' ; this is floppy information , fat12
	boot_program equ 7c00h
	kernel_location equ 1000h
	temp_location equ 500h
start:
	xor	ax,ax
	mov	ss,ax
	mov	sp,boot_program
	push	ss
	pop	ds

	mov si,Loading_msg+boot_program
	call prt_msg
	
;;  Reading Kernel From Floppy
	
	mov ah,2
	mov al,50
	mov ch,0
	mov cl,2
	mov dh,1
	mov dl,0
	mov bx,0
	mov es,bx
	mov bx,temp_location
	int 13h
	mov di,Kernel_Name+boot_program
	mov si,temp_location
next_file:
	call compar_string
	cmp	bx,1
	jz found
	add si,20h
	jmp next_file
found:
	add si,1ah
	mov ah,[si+1]
	mov al,[si]
	mov bl,[si+2]
	mov bh,[si+3]
	add ax,32
	dec ax
	mov cl,18
	div cl
	inc ah
	mov cl,ah
	mov ch,al
	mov ax,bx
	mov bx,0x200
	dec ax
	mov dx,0
	div bx
	inc al
	push ax
	mov al,ch
	mov ah,0
	mov ch,2
	div ch
	mov dh,ah
	mov ch,al
	pop ax
	mov ah,2
	mov dl,0
	mov bx,0
	mov es,bx
	mov bx,kernel_location
	int 13h
	jc err
	mov ax,0
	jmp 0x0000:kernel_location

err:
	mov si,Error_msg+boot_program
	call prt_msg
	jmp $
prt_msg:
	pusha
	mov ah,0eh
	mov bh,0
	mov bl,0xFF
prt_nc:
	mov al,[si]
	cmp al,0
	jz end_prt
	int 10h
	inc si
	jmp prt_nc
end_prt:
	popa
	ret

compar_string:
	pusha
compare_nc:
	mov	ah,[di]
	mov al,[si]
	cmp	ah,0
	jz	end_compar
	cmp	al,0
	jz	end_compar
	inc di
	inc si
	cmp ah,al
	jz	compare_nc
	popa
	mov bx,0
	ret
end_compar:
	popa
	mov bx,1
	ret

	Loading_msg DB 'Loading...',0xD,0xA,0
	Kernel_Name DB 'KERNEL  BIN',0
	Error_msg DB 'Error! An error occure along booting...',0
	times 510-($-$$) DB 0
	DW 0xAA55