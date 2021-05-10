bits 64

global ft_list_sort

ft_list_sort:
	
	mov		r14, [rdi]
	mov		rdx, r14
	mov		r13, rsi

loop:
	mov		r15, [r14 + 8]
	cmp		r15, 0
	je		return
	mov		rdi, [r14]
	mov		r12, [r14 + 8]
	mov		rsi, [r12]
	call	r13
	cmp		rax, 0
	jg		swap
	mov		r14, r15
	jmp		loop

swap:
	mov		r11, [r14]
	mov		r12, [r15]
	mov		[r14], r12
	mov		[r15], r11
	mov		r14, rdx
	jmp		loop

return:
	ret