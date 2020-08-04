section .text
	global ft_strcmp

ft_strcmp:				; rdi - s1, rsi - s2
	xor rax, rax
	xor rcx, rcx
.loop_start:
	mov al, byte[rdi]
	mov cl, byte[rsi]
	sub rax, rcx
	jnz .loop_end
	test cl, cl
	jz .loop_end
	inc rdi
	inc rsi
	jmp .loop_start
.loop_end:
	ret

