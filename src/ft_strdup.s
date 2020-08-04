section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:			;	rdi - s
	push rdi		;	save s
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc		;	rax = new_s
	pop rsi			;	rsi = s
	test rax, rax
	jz .ret
	mov rdi, rax
	call ft_strcpy
.ret:
	ret
