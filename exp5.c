section .data
    prompt1 db 'Enter a string: ', 0
    prompt2 db 'Enter a character to count: ', 0
    buffer db 256
    char db 0
    count dd 0

section .bss
    num resb 4

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    lea ecx, [prompt1]
    mov edx, 14
    int 0x80

    mov eax, 3
    mov ebx, 0
    lea ecx, [buffer]
    mov edx, 256
    int 0x80

    mov byte [ecx+eax-1], 0

    mov eax, 4
    mov ebx, 1
    lea ecx, [prompt2]
    mov edx, 27
    int 0x80

    mov eax, 3
    mov ebx, 0
    lea ecx, [char]
    mov edx, 1
    int 0x80

    lea edx, [buffer]
    mov ebx, char
    xor ecx, ecx

count_occurrences:
    mov al, byte [edx]
    test al, al
    jz print_result
    cmp al, [ebx]
    jne next_char
    inc ecx

next_char:
    inc edx
    jmp count_occurrences

print_result:
    mov dword [count], ecx
    mov eax, [count]
    call print_num

    mov eax, 1
    int 0x80

print_num:
    mov edi, num + 3
    mov byte [edi+1], 0
    mov ebx, 10
convert_loop:
    xor edx, edx
    div ebx
    add dl, '0'
    dec edi
    mov [edi], dl
    test eax, eax
    jnz convert_loop
    lea edx, [edi]
    mov ecx, num + 3 - edi
    mov ebx, 1
    mov eax, 4
    int 0x80
    ret
