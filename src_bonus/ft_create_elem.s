;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_create_elem.s                                   :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:32:19 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:32:19 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

section .text
	global ft_create_elem
	extern malloc

ft_create_elem:		; rdi - *data
	push rdi
	mov rdi, 16
	call malloc
	pop rdi
	test rax, rax
	jz .err_malloc
	mov rdx, rax
	mov [rdx], rdi
	add rdx, 8
	mov qword[rdx], 0x0
.err_malloc:
	ret	
