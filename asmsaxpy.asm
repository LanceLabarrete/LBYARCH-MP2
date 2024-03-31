; Assembler code for the function floatasmsaxpy


;section .text
;bits 64
;default rel


;global floatasmsaxpy
;extern printf

;floatasmsaxpy:

    ;mulss xmm0, xmm0, xmm1
    ;addss xmm0, xmm0, xmm2
    
    ;ret