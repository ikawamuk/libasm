section .text
global ft_strcmp
ft_strcmp:
.while:
	movzx rax, byte [rdi]
	movzx rcx, byte [rsi]
	cmp rax, 0
	je .return
	cmp rax, rcx
	jne .return
	inc rdi
	inc rsi
	jmp .while
.return:
	sub rax, rcx
	ret

;int ft_strcmp(const char *s1, const char *s2) {
;	while (*s1) {
;		if (*s1 != *s2)
;			break ;
;		++s1;
;		++s2;
;	}
;	return ((unsigned char)*s1 - (unsigned char)*s2);
;}
