
; Assembler code for the function floatasmsaxpy

; Callee Adjustment
; a (scalar)	-> xmm0
; x (address)	-> xmm1
; y (address)	-> xmm2


section .text
bits 64
default rel

global saxpyASM

saxpyASM:
	;xorps xmm0, xmm0

	;movss xmm1, [rcx]
	;movss xmm2, [rdx]
	;movss xmm3, [r8]

	vmulss xmm0, xmm1, xmm0
	vaddss xmm0, xmm0, xmm2
	ret