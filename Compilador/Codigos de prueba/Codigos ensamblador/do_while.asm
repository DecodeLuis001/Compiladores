TITLE	do_while.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@8@@	DB	0aH, 'La suma es: %d', 0aH, 00H
??@1@@	DB	'Ingrese un numero(si desea salir ingrese 0):', 0aH, 00H
??@3@@	DB	'%d', 00H
_CONST	ENDS
_TEXT	SEGMENT
_x$ = -4
_suma$ = -8
_@9$ = -8
_@2$ = -8
_@4$ = -12
_@5$ = -12
_@6$ = -16
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 80
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _suma$[ebp], 0
$LN2@main:
	push	OFFSET _??@1@@
	call	_printf
	add		esp, 4
	push	DWORD PTR _@4$[ebp]
	push	OFFSET _??@3@@
	call	_scanf
	add		esp, 8
	mov		eax, DWORD PTR _x$[ebp]
	add		eax, DWORD PTR _x$[ebp]
	mov		DWORD PTR _x$[ebp], eax
	mov		eax, DWORD PTR _@6$[ebp]
	mov		DWORD PTR _suma$[ebp], eax
	cmp		DWORD PTR _@7$[ebp], 0
	jne		SHORT $LN2@main
	jmp		SHORT $LN12@main
$LN12@main:
	push	DWORD PTR _suma$[ebp]
	push	OFFSET _??@8@@
	call	_printf
	add		esp, 8
	mov		eax, 0
	jmp		SHORT $exit@main
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

