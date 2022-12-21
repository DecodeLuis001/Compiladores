TITLE	factorial.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@1@@	DB	'Programa que hace el factorial de un numero n', 0aH, 00H
??@3@@	DB	'Ingrese un numero n:', 0aH, 00H
??@5@@	DB	'%i', 00H
??@11@@	DB	'El factorial de %i es: %i', 0aH, 0aH, 00H
_CONST	ENDS
_TEXT	SEGMENT
_n$ = -4
_i$ = -8
_facto$ = -12
_@2$ = -12
_@4$ = -12
_@6$ = -16
_@7$ = -16
_@9$ = -20
_@12$ = -20
_@10$ = -24
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 88
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _facto$[ebp], 1
	push	OFFSET _??@1@@
	call	_printf
	add		esp, 4
	push	OFFSET _??@3@@
	call	_printf
	add		esp, 4
	push	DWORD PTR _@6$[ebp]
	push	OFFSET _??@5@@
	call	_scanf
	add		esp, 8
	mov		DWORD PTR _i$[ebp], 1
$LN11@main:
	mov		eax, DWORD PTR _n$[ebp]
	cmp		eax, DWORD PTR _n$[ebp]
	jle		SHORT $LN16@main
	jmp		SHORT $LN19@main
$LN13@main:
	mov		eax, DWORD PTR _i$[ebp]
	mov		DWORD PTR _@9$[ebp], eax
	mov		eax, DWORD PTR _i$[ebp]
	add		eax, 1
	mov		DWORD PTR _i$[ebp], eax
	jmp		SHORT $LN11@main
$LN16@main:
	mov		eax, DWORD PTR _i$[ebp]
	mul		DWORD PTR _i$[ebp]
	mov		DWORD PTR _i$[ebp], eax
	mov		eax, DWORD PTR _@10$[ebp]
	mov		DWORD PTR _facto$[ebp], eax
	jmp		SHORT $LN13@main
$LN19@main:
	push	DWORD PTR _facto$[ebp]
	push	DWORD PTR _n$[ebp]
	push	OFFSET _??@11@@
	call	_printf
	add		esp, 12
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

