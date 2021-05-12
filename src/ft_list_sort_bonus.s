bits 64

global ft_list_sort

ft_list_sort:
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
	call	r13
	cmp		rax, 0
	jg		swap
	mov		rdi, [r14 + 8]
	mov		r14, rdi
	jmp		loop
	
swap:
	mov		rdi, [r14]
	mov		rsi, [r15]
	mov		[r14], rsi
	mov		[r15], rdi
	mov		r14, r12
	jmp		loop

return:
	ret
