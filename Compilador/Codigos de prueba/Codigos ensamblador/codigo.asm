TITLE	codigo.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?r@@:DWORD
COMM	?g@@:DWORD
COMM	?h@@:DWORD:02H
_DATA	ENDS
_CONST	SEGMENT
__real@9999999a	DD	09999999ar
__real@00000000	DD	000000000r
__real@00000000	DD	000000000r
??@22@@	DB	'C PROGRAMMING %d', 0aH, '//', 00H
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
_@10$ = -28
_@11$ = -32
_@15$ = -36
_@17$ = -40
_@18$ = -44
_@20$ = -52
_@29$ = -56
_@30$ = -60
_@32$ = -64
_@26$ = -68
_@24$ = -72
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 136
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
	mov		eax, DWORD PTR _@9$[ebp]
	add		eax, 3
	mov		DWORD PTR _@9$[ebp], eax
	mov		eax, DWORD PTR _@10$[ebp]
	mov		DWORD PTR ?g@@, eax
	mov		eax, DWORD PTR _z$[ebp]
	mov		DWORD PTR _@11$[ebp], eax
	mov		eax, DWORD PTR _z$[ebp]
	add		eax, 1
	mov		DWORD PTR _z$[ebp], eax
	mov		eax, DWORD PTR _@11$[ebp]
	mov		DWORD PTR ?g@@, eax
	mov		eax, DWORD PTR _z$[ebp]
	sub		eax, 1
	mov		DWORD PTR _z$[ebp], eax
	mov		eax, DWORD PTR _z$[ebp]
	mov		DWORD PTR ?g@@, eax
	mov		DWORD PTR ?g@@, 4
	mov		DWORD PTR _@14$[ebp], 12
	xor		edx, edx
	mov		eax, DWORD PTR _@16$[ebp]
	div		2
	mov		DWORD PTR _@16$[ebp], eax
	mov		eax, DWORD PTR _@17$[ebp]
	sub		eax, DWORD PTR _@17$[ebp]
	mov		DWORD PTR _@17$[ebp], eax
	mov		eax, DWORD PTR _@18$[ebp]
	mov		DWORD PTR ?r@@, eax
	movss	xmm0, DWORD PTR _@19$[ebp]
	mulss	xmm0, DWORD PTR __real@00000000
	movss	DWORD PTR _@19$[ebp], xmm0
	movss	xmm0, DWORD PTR _@20$[ebp]
	movss	DWORD PTR _y$[ebp], xmm0
	mov		eax, 0
	cmp		eax, 3
	jg		SHORT $LN26@main
	jmp		SHORT $LN30@main
$LN26@main:
	push	5
	push	OFFSET _??@22@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN32@main
$LN30@main:
	mov		eax, DWORD PTR _@25$[ebp]
	add		eax, 5
	mov		DWORD PTR _@25$[ebp], eax
	mov		eax, DWORD PTR _@26$[ebp]
	mov		DWORD PTR ?r@@, eax
$LN32@main:
	mov		DWORD PTR _@28$[ebp], 4
	mov		eax, DWORD PTR _@29$[ebp]
	mov		ebx, DWORD PTR _?h@@$[ebp+eax]
	mov		DWORD PTR _@30$[ebp], ebx
	push	5
	push	DWORD PTR _@30$[ebp]
	call	_myfunc
	add		esp, 8
	fstp	_$[ebp]
	mov		eax, DWORD PTR _@32$[ebp]
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

