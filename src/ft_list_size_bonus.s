bits 64

global ft_list_size

ft_list_size:
	mov	rcx, 0

loop:
	cmp	rdi, 0
	je	return
	mov	rdi, [rdi + 8]
	inc	rcx
	jmp	loop

return:
	mov rax, rcx
	ret
