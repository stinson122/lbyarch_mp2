section .text
bits 64
default rel
global daxpy

; void daxpy(int n, double A, double *X, double *Y, double *Z)
daxpy:
    ;test only first (i=1)
    movsd xmm1, [rsi] ;X[i] to xmm1
    mulsd xmm1, xmm0 ; A * X[i]
    addsd xmm1, [rdx] ; A * X[i] + Y[i]
    movsd [rcx], xmm1 ;Z[i]

    xor rax, rax
    ret