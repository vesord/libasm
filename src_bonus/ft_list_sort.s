section .text
	global ft_list_sort
	extern ft_list_size

;	swaps cur and next elems of list
_ft_list_sort_swap:		; rdi - *prev, rsi - *cur, rdx - *nxt
						; 		*r8			 *r9	 	 *r10
	mov r10, [rdx + 8]
	mov [rsi + 8], r10
	mov r9, rsi
	mov [rdx + 8], r9
	test rdi, rdi
	jz .empty_prev
	mov r8, rdx
	mov [rdi + 8], r8
.empty_prev:
	ret

ft_list_sort:			; rdi - **begin_list, rsi - int (*cmp)
	push r12
	push r13
	push r14
	push r15
	push rdi
	push rsi
	mov rdi, [rdi]
	call ft_list_size
	mov rcx, rax
	pop rsi
	pop rdi
	test rcx, rcx
	jz .bubble_exit
.bubble_i_start:
	dec rcx
	test rcx, rcx			; rcx - bubble counter i
	jz .bubble_exit
	mov r12, 0x00			; prev = NULL
	mov r13, [rdi]			; cur = *head
	mov r14, [r13 + 8]		; nex = *head.next
	mov r8, rcx				; r8 - bubble counter j
.bubble_j_start:

;	___CHECK_CMP___
	push rcx
	mov rcx, rsi
	push rsi
	push r8
	push rdi
	mov rdi, [r13]			; cmp( (cur->data),      ???     )
	mov rsi, [r14]			; cmp( (cur->data), (nex->data) )
	call rcx				; exec (cmp)
	cmp eax, 0				; (cmp*)returns int
	jng .bubble_j_end 

;	___DO_SWAP___
	mov rdi, r12
	mov rsi, r13
	mov rdx, r14
	call _ft_list_sort_swap
	mov rdx, r14
	mov r14, r13
	mov r13, rdx
	test r12, r12
	jnz .bubble_j_end
	pop rdi
	mov [rdi], r13
	push rdi

.bubble_j_end:
	pop rdi
	pop r8
	pop rsi
	pop rcx
	mov r12, r13
	mov r13, r14
	mov r14, [r14 + 8]
	dec r8
	test r8, r8
	jnz .bubble_j_start
	jmp .bubble_i_start

.bubble_exit:
	pop r15
	pop r14
	pop r13
	pop r12
	ret
