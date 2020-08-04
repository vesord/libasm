section .text
	global ft_strlen

ft_strlen:
	xor rcx, rcx
	mov rax, rdi
.loop_start:
	mov cl, byte[rax]
	test cl, cl
	jz .loop_end
	inc rax
	jmp .loop_start
.loop_end:
	sub rax, rdi
	ret
	
