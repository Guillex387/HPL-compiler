; Header
section .data
  fmt: db "%u", 0xa, 0x0
section .bss
  mem: resb 30

section .text
extern printf
global _start

print_num:
  push rcx
  lea rdi, fmt
  xor rsi, rsi
  mov byte sil, [mem+rcx]
  call printf
  pop rcx
  ret

print_ascii:
  push rcx
  mov rax, 1
  mov rdi, 1
  lea rsi, [mem+rcx]
  mov rdx, 1
  syscall
  pop rcx
  ret

_start:
  xor rcx, rcx
; Next cell
  inc rcx
; Prev cell
  dec rcx
; Increment cell
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  inc rdx
  mov byte [mem+rcx], dl
; Decrement cell
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  dec rdx
  mov byte [mem+rcx], dl
; Loop begin
loop_1:
  xor rax, rax
  xor rdx, rdx
  mov byte dl, [mem+rcx]
  cmp rdx, rax
  je loop_1_end
; Loop end
loop_1_end:
; Show cell
  push rcx
  lea rdi, fmt
  xor rsi, rsi
  mov byte sil, [mem+rcx]
  call printf
  pop rcx
; Kernel exit
  mov rax, 60
  mov rdi, 0
  syscall
