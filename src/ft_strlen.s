bits 64

global ft_strlen

ft_strlen:
	mov	rcx, 0

loop:
	cmp	byte [rdi + rcx], 0
	je	return
	inc	rcx
	jmp	loop

return:
	mov 	rax, rcx
	ret
