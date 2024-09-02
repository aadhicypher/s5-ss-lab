section .data
    string db 'Hello, World!', 0
    length equ $ - string

section .text
    global _start

_start:
    mov rsi, string
    mov rcx, length

toggle_loop:
    mov al, [rsi]
    test al, al
    jz end_loop
    cmp al, 'A'
    jl not_alpha
    cmp al, 'Z'
    jle to_lowercase
    cmp al, 'a'
    jl not_alpha
    cmp al, 'z'
    jle to_uppercase
    jmp next_char

to_lowercase:
    or al, 0x20
    jmp store_char

to_uppercase:
    and al, 0xDF

store_char:
    mov [rsi], al

next_char:
    inc rsi
    loop toggle_loop

end_loop:
    mov rax, 60
    xor rdi, rdi
    syscall
