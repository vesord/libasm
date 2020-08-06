;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_write.s                                         :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:31:40 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:31:40 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

section .text
	extern __errno_location
	global ft_write

ft_write:		; rdi - fd, rsi - &buff, rdx - count
	xor rax, rax
	or	rax, 1
	syscall
	cmp rax, 0
	jl .set_errno
	ret
.set_errno:
	neg rax
	push rax
	call __errno_location
	pop rdi
	mov [rax], edi
	mov rax, -1
	ret
	
