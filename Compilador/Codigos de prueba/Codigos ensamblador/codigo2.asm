TITLE	codigo2.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?r@@:DWORD
COMM	?h@@:DWORD:02H
_DATA	ENDS
_CONST	SEGMENT
??@21@@	DB	'%d', 0aH, 00H
??@13@@	DB	'C PROGRAMMING %d', 0aH, '//', 00H
_CONST	ENDS
_TEXT	SEGMENT
_a$ = 8
_b$ = 12
_@1$ = 16
_myfunc	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 64
	push	ebx	
	push	esi	
	push	edi	
	mov		eax, DWORD PTR _b$[ebp]
	mul		DWORD PTR _b$[ebp]
	mov		DWORD PTR _b$[ebp], eax
	mov		eax, DWORD PTR _@1$[ebp]
	fld		eax
	jmp		SHORT $exit@myfunc
$exit@myfunc:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_myfunc	ENDP
_TEXT	ENDS
_TEXT	SEGMENT
_i$ = -4
_x$ = -8
_@5$ = -12
_z$ = -16
_@8$ = -20
_@10$ = -24
_@11$ = -28
_@20$ = -32
_@25$ = -36
_@26$ = -40
_@28$ = -44
_@22$ = -48
_@17$ = -52
_@15$ = -56
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 120
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _x$[ebp], 6
	mov		eax, 6
	add		eax, 5
	mov		DWORD PTR _@4$[ebp], eax
	mov		eax, DWORD PTR _@5$[ebp]
	mov		DWORD PTR _z$[ebp], eax
	mov		DWORD PTR _@7$[ebp], 12
	xor		edx, edx
	mov		eax, DWORD PTR _@9$[ebp]
	div		2
	mov		DWORD PTR _@9$[ebp], eax
	mov		eax, DWORD PTR _@10$[ebp]
	sub		eax, DWORD PTR _@10$[ebp]
	mov		DWORD PTR _@10$[ebp], eax
	mov		eax, DWORD PTR _@11$[ebp]
	mov		DWORD PTR ?r@@, eax
	mov		eax, 0
	cmp		eax, 3
	jg		SHORT $LN14@main
	jmp		SHORT $LN18@main
$LN14@main:
	push	5
	push	OFFSET _??@13@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN20@main
$LN18@main:
	mov		eax, DWORD PTR _@16$[ebp]
	add		eax, 5
	mov		DWORD PTR _@16$[ebp], eax
	mov		eax, DWORD PTR _@17$[ebp]
	mov		DWORD PTR ?r@@, eax
$LN20@main:
	mov		DWORD PTR _i$[ebp], 0
$LN21@main:
	cmp		DWORD PTR _@19$[ebp], 5
	jl		SHORT $LN26@main
	jmp		SHORT $LN30@main
$LN23@main:
	mov		eax, DWORD PTR _i$[ebp]
	mov		DWORD PTR _@20$[ebp], eax
	mov		eax, DWORD PTR _i$[ebp]
	add		eax, 1
	mov		DWORD PTR _i$[ebp], eax
	jmp		SHORT $LN21@main
$LN26@main:
	push	DWORD PTR _i$[ebp]
	push	OFFSET _??@21@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN23@main
$LN30@main:
	mov		DWORD PTR _@24$[ebp], 4
	mov		eax, DWORD PTR _@25$[ebp]
	mov		ebx, DWORD PTR _?h@@$[ebp+eax]
	mov		DWORD PTR _@26$[ebp], ebx
	push	5
	push	DWORD PTR _@26$[ebp]
	call	_myfunc
	add		esp, 8
	fstp	_$[ebp]
	mov		eax, DWORD PTR _@28$[ebp]
	mov		DWORD PTR _z$[ebp], eax
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

