bits 64

default rel

segment .data
    msg db "hello cac ban !/n xin chao moi nguoi ", 0xd, 0xa, 0

segment .text
global main
extern ExitProcess

extern printf

main:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 50

    lea     rcx, [msg]
    call    printf

    xor     rax, rax
    call    ExitProcess
