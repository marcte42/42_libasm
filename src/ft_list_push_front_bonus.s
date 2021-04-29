bits 64

global ft_list_push_front
extern __errno_location
extern malloc

ft_list_push_front:
	push rdi
	push rsi
	mov rdi, 16
	call malloc
	cmp	rax, 0
	je	error
	pop rsi
	pop rdi
	mov [rax], rsi
	mov rsi, [rdi]
	mov [rax + 8], rsi
	mov [rdi], rax
	ret
	
error:
	ret