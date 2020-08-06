;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_strcmp.s                                        :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:30:04 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:30:04 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

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

