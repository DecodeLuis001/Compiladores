TITLE	mayor.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@0@@	DB	'Ingrese tres numeros diferentes: ', 00H
??@2@@	DB	'%.2f es el numero mas grande.', 00H
??@4@@	DB	'%.2f es el numero mas grande.', 00H
??@6@@	DB	'%.2f es el numero mas grande.', 00H
_CONST	ENDS
_TEXT	SEGMENT
_argc$ = 8
_n1$ = -8
_n2$ = -16
_n3$ = -24
_@1$ = -24
_@3$ = -24
_@5$ = -24
_@7$ = -24
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 88
	push	ebx	
	push	esi	
	push	edi	
	push	OFFSET _??@0@@
	call	_printf
	add		esp, 4
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n2$[ebp]
	jge		SHORT $LN5@main
	jmp		SHORT $LN10@main
$LN5@main:
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n3$[ebp]
	jge		SHORT $LN7@main
	jmp		SHORT $LN10@main
$LN7@main:
	push	DWORD PTR _n1$[ebp]
	sub		esp, 4
	fld		DWORD PTR _n1$[ebp]
	fstp	DWORD PTR [esp]
	push	OFFSET _??@2@@
	call	_printf
	add		esp, 8
$LN10@main:
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n1$[ebp]
	jge		SHORT $LN12@main
	jmp		SHORT $LN17@main
$LN12@main:
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n3$[ebp]
	jge		SHORT $LN14@main
	jmp		SHORT $LN17@main
$LN14@main:
	push	DWORD PTR _n2$[ebp]
	sub		esp, 4
	fld		DWORD PTR _n2$[ebp]
	fstp	DWORD PTR [esp]
	push	OFFSET _??@4@@
	call	_printf
	add		esp, 8
$LN17@main:
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n1$[ebp]
	jge		SHORT $LN19@main
	jmp		SHORT $LN24@main
$LN19@main:
	movss	xmm0, DWORD PTR __real@00000000
	comiss	xmm0, DWORD PTR _n2$[ebp]
	jge		SHORT $LN21@main
	jmp		SHORT $LN24@main
$LN21@main:
	push	DWORD PTR _n3$[ebp]
	sub		esp, 4
	fld		DWORD PTR _n3$[ebp]
	fstp	DWORD PTR [esp]
	push	OFFSET _??@6@@
	call	_printf
	add		esp, 8
$LN24@main:
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

