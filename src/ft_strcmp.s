bits 64

global ft_strcmp

ft_strcmp:
	mov	rcx, 0
	mov	rax, 0

loop:
	cmp	byte [rdi + rcx], 0
	je	return
	cmp	byte [rsi + rcx], 0
	je	return
	mov	dl, [rsi + rcx]
	cmp	byte [rdi + rcx], dl
	jne	return 
	inc	rcx
	jmp	loop

return:
	movzx	rax, byte [rdi + rcx]
	movzx	rdx, byte [rsi + rcx]
	sub	rax, rdx
	ret
