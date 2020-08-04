section .text
	global ft_read
	extern __errno_location

ft_read:			; rdi - fd, rsi - &buf, rdx - count
	xor rax, rax
	syscall
	cmp rax, 0
	jl .set_errno
	ret
.set_errno:
	neg rax
	push rax
	call __errno_location
	pop rdi
	mov [rax], edi
	mov rax, -1
	ret
	
