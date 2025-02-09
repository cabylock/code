


section .data
    msg db "Hello, world!", 13, 10, 0
    

section .text
    extern printf
    global main



main:
    push ebp
    mov ebp, esp

    push msg
    call printf
    add esp, 4

    leave
    ret