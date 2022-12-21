TITLE	codigo3.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?r@@:DWORD
COMM	?h@@:DWORD:02H
_DATA	ENDS
_CONST	SEGMENT
__real@9999999a	DD	09999999ar
__real@00000000	DD	000000000r
__real@00000000	DD	000000000r
??@23@@	DB	'Z is equal 0', 0aH, 00H
??@26@@	DB	'z is equal 1', 0aH, 00H
??@28@@	DB	'Z is not 0 or 1', 0aH, 00H
??@18@@	DB	'C PROGRAMMING %d', 0aH, '//', 00H
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
_x$ = -8
_@5$ = -12
_y$ = -16
_@8$ = -20
_z$ = -24
_@11$ = -28
_@13$ = -32
_@14$ = -36
_@16$ = -44
_@36$ = -48
_@37$ = -52
_@39$ = -56
_@24$ = -60
_@27$ = -64
_@29$ = -68
_q$ = -72
_x$ = -76
_@20$ = -80
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 144
	push	ebx	
	push	esi	
	push	edi	
	movss	xmm0, DWORD PTR __real@9999999a
	movss	DWORD PTR _x$[ebp], xmm0
	mov		DWORD PTR _@4$[ebp], 0
	movss	xmm0, DWORD PTR _@5$[ebp]
	movss	DWORD PTR _y$[ebp], xmm0
	mov		eax, 6
	add		eax, 5
	mov		DWORD PTR _@7$[ebp], eax
	mov		eax, DWORD PTR _@8$[ebp]
	mov		DWORD PTR _z$[ebp], eax
	mov		DWORD PTR _@10$[ebp], 12
	xor		edx, edx
	mov		eax, DWORD PTR _@12$[ebp]
	div		2
	mov		DWORD PTR _@12$[ebp], eax
	mov		eax, DWORD PTR _@13$[ebp]
	sub		eax, DWORD PTR _@13$[ebp]
	mov		DWORD PTR _@13$[ebp], eax
	mov		eax, DWORD PTR _@14$[ebp]
	mov		DWORD PTR ?r@@, eax
	movss	xmm0, DWORD PTR _@15$[ebp]
	mulss	xmm0, DWORD PTR __real@00000000
	movss	DWORD PTR _@15$[ebp], xmm0
	movss	xmm0, DWORD PTR _@16$[ebp]
	movss	DWORD PTR _y$[ebp], xmm0
	mov		eax, 0
	cmp		eax, 3
	jg		SHORT $LN18@main
	jmp		SHORT $LN21@main
$LN18@main:
	push	5
	push	OFFSET _??@18@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
$LN21@main:
	jmp		SHORT $LN32@main
$LN22@main:
	push	OFFSET _??@23@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN35@main
$LN25@main:
	push	OFFSET _??@26@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN35@main
$LN28@main:
	push	OFFSET _??@28@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN35@main
	jmp		SHORT $LN35@main
$LN32@main:
	mov		eax, 0
	cmp		eax, 2
	je		SHORT $LN22@main
	mov		eax, 1
	cmp		eax, 2
	je		SHORT $LN25@main
	jmp		SHORT $LN28@main
$LN35@main:
	mov		DWORD PTR _@35$[ebp], 4
	mov		eax, DWORD PTR _@36$[ebp]
	mov		ebx, DWORD PTR _?h@@$[ebp+eax]
	mov		DWORD PTR _@37$[ebp], ebx
	push	5
	push	DWORD PTR _@37$[ebp]
	call	_myfunc
	add		esp, 8
	fstp	_$[ebp]
	mov		eax, DWORD PTR _@39$[ebp]
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

