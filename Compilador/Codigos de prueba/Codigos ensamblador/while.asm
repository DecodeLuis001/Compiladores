TITLE	while.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@2@@	DB	'hola', 0aH, 00H
_CONST	ENDS
_TEXT	SEGMENT
_i$ = -4
_@3$ = -4
_@5$ = -8
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 72
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _i$[ebp], 0
$LN2@main:
	cmp		DWORD PTR _@1$[ebp], 3
	jl		SHORT $LN4@main
	jmp		SHORT $LN9@main
$LN4@main:
	push	OFFSET _??@2@@
	call	_puts
	add		esp, 4
	mov		eax, DWORD PTR _@4$[ebp]
	add		eax, 1
	mov		DWORD PTR _@4$[ebp], eax
	mov		eax, DWORD PTR _@5$[ebp]
	mov		DWORD PTR _i$[ebp], eax
	jmp		SHORT $LN2@main
$LN9@main:
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

