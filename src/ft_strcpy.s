section .text
	global ft_strcpy

ft_strcpy:					;rdi - dest, rsi - src
	xor rcx, rcx
	mov rax, rdi
.loop_start:
	mov cl, byte[rsi]
	mov byte[rdi], cl
	test cl, cl
	jz .loop_end
	inc rsi
	inc rdi
	jmp .loop_start
.loop_end:
	ret

