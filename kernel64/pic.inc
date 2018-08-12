



MaskAllInterrupt:
	mov		al,0xFF
	out		0xA1,al
	out		0x21,al
ret