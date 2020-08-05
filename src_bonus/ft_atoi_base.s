section .text
	global ft_atoi_base ; ft_atoi_base(char *s, int s_base);

ft_char_to_int:
	cmp rdi, 0x30		; '0'
	jl .wrong_ret
	cmp rdi, 0x3A		; '9' + 1
	jl .ret_less_a
	cmp rdi, 0x41		; 'A'
	jl .wrong_ret
	cmp rdi, 0x47		; 'F' + 1
	jl .ret_upper
	cmp rdi, 0x61		; 'a'
	jl .wrong_ret
	cmp rdi, 0x67		; 'f' + 1
	jl .ret_lower
.wrong_ret:
	neg rdi
	mov rax, rdi
	ret
.ret_lower:
	sub rdi, 0x20		; 'a' - 0x20 = 'A'
.ret_upper:
	sub rdi, 0x07		; 'A' - 0x07 = 0x3a
.ret_less_a:
	sub rdi, 0x30
	mov rax, rdi
	ret

ft_atoi_base:			; rdi - s, rsi - s_base
	xor r11, r11		; r11 - sign
	mov r10, rdi		; r10 - s
	xor rax, rax
	xor rdx, rdx		; rdx - result
	mov al, byte[r10]
	cmp al, 0x2D
	jne .get_digit
	inc r11
	inc r10
.get_digit:
	xor rdi, rdi
	mov dil, byte[r10]
	test rdi, rdi
	jz .stop
	push r11
	push r10
	push rsi
	push rdx
	call ft_char_to_int
	pop rdx
	pop rsi
	pop r10
	pop r11
	test rax, rax
	js .stop
	cmp rax, rsi
	jae .stop
	mov r9, rax
	mov rax, rdx
	mul rsi
	mov rdx, rax
	add rdx, r9
	inc r10
	jmp .get_digit
.stop:
	test r11, r11
	jz .ret
	neg rdx
.ret:
	mov rax, rdx
	ret
