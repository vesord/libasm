section .text
	global ft_list_push_front
	extern ft_create_elem
	extern malloc

ft_list_push_front:	; rdi - **begin_list, rsi - *data
	push rdi
	push rsi
	mov rdi, rsi
	call ft_create_elem 
	pop rsi
	pop rdi
	test rax, rax
	jz .err_malloc
	mov rdx, [rdi]			; rdx = *begin_list;
	mov [rdi], rax			; *begin_list = ft_create_elem;
	add rax, 8
	mov [rax], rdx
.err_malloc:
	ret
