section .text
	global ft_strdup
	extern malloc
	extern ft_strlen

ft_strdup:			;	rdi - s
	push rdi		;	save s
	call ft_strlen
	push rax		;	save ft_strlen(s);
	inc rax
	mov rdi, rax
	call malloc		;	rax = new_s
	pop rcx			;	rcx = ft_strlen(s);
	pop rdi			;	rdi = s
	test rax, rax
	jz .ret
	mov byte[rax + rcx], 0x00
.loop_start:
	test rcx, rcx
	jz .ret
	dec rcx
	mov dl, byte[rdi + rcx]
	mov byte[rax + rcx], dl
	jmp .loop_start
.ret:
	ret	
