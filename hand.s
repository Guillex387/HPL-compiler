; header
section .data
  fmt: db "%u\n", 0x0 ; or %c by default

section .bss
  mem: resb 30

section .text

extern printf
global _start

_start:
  xor rcx, rcx
  ; next
  inc rcx
  ; prev
  dec rcx
  ; inc
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  inc rdx
  mov byte [mem+rcx], dl
  ; dec
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  dec rdx
  mov byte [mem+rcx], dl
  ; loop
loop_1:
  xor rax, rax
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  cmp rdx, rax
  je loop_1_end
  ; end
loop_1_end:
  ; show
  push rcx
  lea rdi, fmt
  xor rsi, rsi
  mov byte sil, [mem+rcx]
  call printf
  pop rcx
  ; footer
  mov rax, 60
  mov rdi, 0
  syscall
