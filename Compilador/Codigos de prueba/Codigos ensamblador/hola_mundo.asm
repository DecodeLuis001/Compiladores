TITLE	hola_mundo.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@0@@	DB	'Hola Mundo', 00H
_CONST	ENDS
_TEXT	SEGMENT
_argc$ = 8
_@1$ = 0
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 64
	push	ebx	
	push	esi	
	push	edi	
	push	OFFSET _??@0@@
	call	_printf
	add		esp, 4
$exit@main:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_main	ENDP
_TEXT	ENDS
END

