;* ************************************************************************** *;
;*                                                                            *;
;*                                                        :::      ::::::::   *;
;*   ft_list_remove_if.s                                :+:      :+:    :+:   *;
;*                                                    +:+ +:+         +:+     *;
;*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *;
;*                                                +#+#+#+#+#+   +#+           *;
;*   Created: 2020/08/06 23:32:45 by matrus            #+#    #+#             *;
;*   Updated: 2020/08/06 23:32:45 by matrus           ###   ########.fr       *;
;*                                                                            *;
;* ************************************************************************** *;

section .text
	global ft_list_remove_if
	extern free

ft_list_remove_if:			; rdi - **beg_list, rsi - *data_ref, rdx - *cmp
	mov r8, rdi				; r8 - **beg_list
	xor r9, r9				; r9 - *prev
	mov rcx, [r8]
.loop_start:
	test rcx, rcx
	jz	.end
	mov rdi, [rcx]
	push rcx
	push rsi
	push rdx
	push r8
	push r9
	call rdx
	pop r9
	pop r8
	pop rdx
	pop rsi
	pop rcx
	test rax, rax
	jz .del_one
	mov r9, rcx
	mov rcx, [rcx + 8]
	jmp .loop_start

.del_one:
	test r9, r9
	jz .dont_need_set_prev
	mov rax, [rcx + 8]		; prev->next = cur->next
	mov [r9 + 8], rax
	jmp .do_free

.dont_need_set_prev:
	mov rax, [rcx + 8]
	mov [r8], rax			; set new head
	jmp .do_free

.do_free:
	mov rdi, rcx
	mov rcx, [rcx + 8]
	push rcx
	push rsi
	push rdx
	push r8
	push r9
	call free
	pop r9
	pop r8
	pop rdx
	pop rsi
	pop rcx
	jmp .loop_start 

.end:
	ret
