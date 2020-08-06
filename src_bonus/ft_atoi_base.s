;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_atoi_base.s                                     :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:32:05 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:32:05 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

section .text
	global ft_atoi_base ; ft_atoi_base(char *s, int s_base);

ft_char_to_int:			; rdi - char
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

ft_isspace:
	or rax, 0x01
	cmp rdi, 0x09		; '\t'
	jl .ret_no
	cmp rdi, 0x0E		; '\r' + 1
	jl .ret_yes
	cmp rdi, 0x20		; ' '
	je .ret_yes
.ret_no:
	xor rax, rax
.ret_yes:
	ret

ft_atoi_base:			; rdi - s, rsi - s_base
	mov r10, rdi		; r10 - s
.skip_space:
	xor rdi, rdi
	mov dil, byte[r10]
	push rsi
	push r10
	call ft_isspace
	pop r10
	pop rsi
	test rax, rax
	jz .end_skip_space 
	inc r10
	jmp .skip_space
.end_skip_space:
	xor r11, r11		; r11 - sign
	xor rdx, rdx		; rdx - result
	mov al, byte[r10]
	cmp al, 0x2D		; '-'
	jne .try_plus
	inc r11
	inc r10
	jmp .get_digit
.try_plus:
	cmp al, 0x2B		; '+'
	jne .get_digit
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
