section .text
global ft_strcpy
ft_strcpy:
	mov rax, rdi
.while:
	cmp byte [rsi], 0
	je .return
	mov cl, byte [rsi]
	mov byte [rdi], cl
	inc rdi
	inc rsi
	jmp .while
.return:
	mov byte [rdi], 0
	ret

;char	*ft_strcpy(char *dest, const char *src) {
;	char	*dest_head = dest;
;	while (*src) {
;		*dest = *src;
;		++dest;
;		++src;
;	}
;	*dest = '\0';
;	return (dest);
;}
