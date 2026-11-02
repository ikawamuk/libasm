global ft_strdup
extern malloc, ft_strlen, ft_strcpy
section .text
ft_strdup:
	push rbx
	mov rbx, rdi
	call ft_strlen
	lea	rdi, [rax + 1]
	call malloc wrt ..plt
	cmp rax, 0
	je .return
	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy
.return:
	pop rbx
	ret

;char *ft_strdup(const char *s)
;{
;	char	*dst = malloc(strlen(s) + 1);
;	if (!dst)
;		return (NULL);
;	return (strcpy(dst, s));
;}
