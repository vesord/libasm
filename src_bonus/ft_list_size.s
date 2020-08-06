;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_list_size.s                                     :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:32:54 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:32:54 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

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
