bits 64

global ft_strdup
extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	call	ft_strlen
	push	rdi
	inc	rax
	mov	rdi, rax
	call	malloc
	cmp	rax, 0
	je	error
	pop	rsi
	mov	rdi, rax
	call	ft_strcpy
	ret

error:
	neg	rax
	mov	rdi, rax
	call	__errno_location
	mov	[rax], rdi
	mov	rax, -1
	ret
