section .text
global ft_strlen
ft_strlen:
	mov rcx, rdi
.while:
	cmp byte [rdi], 0
	je .return
	inc rdi
	jmp .while
.return:
	mov rax, rdi
	sub rax, rcx
	ret

;#include <stddef.h>
;
;size_t	ft_strlen(const char *s) {
;	const char *head = s;
;	while (*s)
;		++s;
;	return (s - head);
;}
