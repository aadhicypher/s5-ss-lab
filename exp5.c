section .data
    string db 'Hello, world!', 0
    target_char db 'o'
    count db 0
    msg db 'Occurrences of character: ', 0
    result_msg db ' times', 10, 0

section .bss
    digit resb 3

section .text
    global _start

_start:
    mov rsi, string
    mov al, [target_char]
    mov rcx, 0

count_loop:
    mov bl, [rsi]
    cmp bl, 0
    je end_loop
    cmp bl, al
    jne next_char
    inc rcx

next_char:
    inc rsi
    jmp count_loop

end_loop:
    mov rbx, rcx
    mov rdi, digit
    add_digit:
        xor rdx, rdx
        mov rax, rbx
        mov rbx, 10
        div rbx
        add
