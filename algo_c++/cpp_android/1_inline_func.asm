; Listing generated by Microsoft (R) Optimizing Compiler Version 16.00.30319.01 

	TITLE	D:\cpp_prj\day_1\1_inline_func.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	?Add1@@YAHHH@Z					; Add1
; Function compile flags: /Odtp
; File d:\cpp_prj\day_1\1_inline_func.cpp
_TEXT	SEGMENT
_a$ = 8							; size = 4
_b$ = 12						; size = 4
?Add1@@YAHHH@Z PROC					; Add1

; 9    : int Add1(int a, int b) {

	push	ebp
	mov	ebp, esp

; 10   : 	return a+b;

	mov	eax, DWORD PTR _a$[ebp]
	add	eax, DWORD PTR _b$[ebp]

; 11   : }

	pop	ebp
	ret	0
?Add1@@YAHHH@Z ENDP					; Add1
_TEXT	ENDS
PUBLIC	_main
; Function compile flags: /Odtp
_TEXT	SEGMENT
_n2$ = -8						; size = 4
_n1$ = -4						; size = 4
_main	PROC

; 17   : int main() {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 18   : 	int n1 = Add1(1,2);

	push	2
	push	1
	call	?Add1@@YAHHH@Z				; Add1
	add	esp, 8
	mov	DWORD PTR _n1$[ebp], eax

; 19   : 	int n2 = Add2(1,2);

	mov	eax, 1
	add	eax, 2
	mov	DWORD PTR _n2$[ebp], eax

; 20   : }

	xor	eax, eax
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
END