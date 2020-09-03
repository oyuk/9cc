.intel_syntax noprefix
.global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 208
  push 0
  pop rax
  mov rsp, rbp
  pop rax
  ret
