bits 64

global ft_list_sort

ft_list_sort:
	push	r12
	push	r13
	push	r14
	push	r15
	cmp		byte [rdi], 0
	je		return
	mov		r14, [rdi]
	mov		r13, rsi
	mov		r12, r14

loop:
	cmp		byte [r14 + 8], 0
	je		return
	mov		r15, [r14 + 8]
	mov		rdi, [r14]
	mov		rsi, [r15]
	push	r14
	push	r15
	push	r12
	push	r13
	call	r13
	cmp		rax, 0
	jg		swap
	jmp		no_swap
	
swap:
	pop		r13
	pop		r12
	pop		r15
	pop		r14
	mov		rdi, [r14]
	mov		rsi, [r15]
	mov		[r14], rsi
	mov		[r15], rdi
	mov		r14, r12
	jmp		loop

no_swap:
	pop		r13
	pop		r12
	pop		r15
	pop		r14
	mov		rdi, [r14 + 8]
	mov		r14, rdi
	jmp		loop

return:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret
