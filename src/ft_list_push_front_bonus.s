bits 64

global ft_list_push_front

ft_list_push_front:
	mov	rdx, [rdi] 
	mov	[rsi + 8], rdx
	mov	[rdi], rsi
	mov	rax, rsi
	ret
