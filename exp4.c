section .data
    str db 'Hello World!', 0

section .text
    global _start

_start:
    mov edx, str

toggle:
    mov al, byte [edx]
    test al, al
    jz done
    mov ebx, edx
    mov bl, [ebx]
    cmp bl, 'a'
    jl check_upper
    cmp bl, 'z'
    jg check_upper
    sub byte [edx], 32
    jmp next_char

check_upper:
    cmp bl, 'A'
    jl next_char
    cmp bl, 'Z'
    jg next_char
    add byte [edx], 32

next_char:
    inc edx
    jmp toggle

done:
    mov eax, 1
    int 0x80
