section .text
	global ft_list_size

ft_list_size:		; rdi - *begin_list
	xor rax, rax
.count:
	test rdi, rdi
	jz	.end
	add rdi, 8
	mov rdi, [rdi]
	inc rax
	jmp .count
.end:
	ret
