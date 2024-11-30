section .text
bits 64
default rel
global daxpy

daxpy:
    xor r10, r10

L1:
    ;call in C is extern void daxpy(int n, double A, double *X, double *Y, double *Z)
    ; n@rcx A@xmm1 X@r9 Y@r10 Z@rdx
    mov rax, r8
    movsd xmm4, [rax + r10*8] ;X
    mov rax, r9
    movsd xmm5, [rax + r10*8] ;Y

    mulsd xmm4, xmm1 ;A*X
    addsd xmm4, xmm5 ;A*X + Y
    mov rax, rdx
    movsd [rax + r10*8], xmm4 ;Z
    
    inc r10
    cmp r10, rcx
    jl L1
    xor rax, rax
    ret