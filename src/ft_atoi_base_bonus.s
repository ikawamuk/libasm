global ft_atoi_base
extern ft_strlen
section .text

ft_atoi_base:
	push rbx
	push r12
	push r13
	push r14
	push r15
	mov r12, rdi
	mov r13, rsi
.init_base:
		mov rdi, r13
		call ft_strlen
		cmp rax, 2
		jb .base_error
		cmp rax, 2147483647
		ja .base_error
		mov r14, rax
	.base_validation:
		mov rbx, 0
		.base_loop:
			cmp rbx, r14
			jae .base_done
			movzx esi, byte [r13 + rbx]
		.check_space:
			cmp sil, ' '
			je .base_error
			cmp sil, 9
			jb .check_sign
			cmp sil, 13
			jbe .base_error
		.check_sign:
			cmp sil, '-'
			je .base_error
			cmp sil, '+'
			je .base_error
		.check_dupulication:
			lea rdi, [r13 + rbx + 1]
			call ft_strchr
			cmp rax, 0
			jne .base_error
			inc rbx
			jmp .base_loop
		.base_done:
.skip_space:
	mov al, [r12]
	cmp al, ' '
	je .advance_space
	cmp al, 9
	jb .space_done
	cmp al, 13
	ja .space_done
.advance_space:
	inc r12
	jmp .skip_space
.space_done:
.check_isnegative:
	mov rbx, 0
	cmp byte [r12], '-'
	jne .check_ispositive
	mov rbx, 1
	inc r12
	jmp .build_value
.check_ispositive:
	cmp byte [r12], '+'
	jne .build_value
	inc r12
.build_value:
	mov r15, 0
.build_loop:
	cmp byte [r12], 0
	je .build_done
	mov rdi, r13
	mov esi, dword [r12]
	call ft_strchr
	cmp rax, 0
	je .build_done
	sub rax, r13
	imul r15d, r14d
	sub r15d, eax
	inc r12
	jmp .build_loop
.build_done:
	mov eax, r15d
	cmp ebx, 0
	jne .return
	neg eax
	jmp .return
.base_error:
	mov rax, 0
.return:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	ret

;int	ft_atoi_base(char *str, char *base) {
;	int	radix, value = 0, neg = 0;
;	if (init_base(&radix, base) < 0) return (0);
;	while (ft_isspace(*str)) ++str;
;	if (*str == '-') neg = 1;
;	if (*str == '-' || *str == '+') ++str;
;	while (*str) {
;		char *p = ft_strchr(base, *str);
;		if (!p) break ;
;		value = radix * value - (p - base);
;		++str;
;	}
;	return (neg ? value : -value);
;}

;static int	init_base(int *n, const char *base) {
;	size_t	len = ft_strlen(base);
;	if (len < 2 || (size_t)INT_MAX < len) return (-1);
;	*n = len;
;	for (size_t i = 0; i < len; ++i)
;		if (ft_isspace(base[i])
;			|| base[i] == '+' || base[i] == '-'
;			|| ft_strchr(base + i + 1, base[i]))
;				return (-1);
;	return (0);
;}

ft_strchr:
.loop:
	cmp byte [rdi], 0
	je .done
	mov al, [rdi] 
	cmp al, sil
	je .return
	inc rdi
	jmp .loop
.done:
	cmp rsi, 0
	jne .not_found
.return:
	mov rax, rdi
	ret
.not_found:
	mov rax, 0
	ret

;static char	*ft_strchr(const char *s, int c) {
;	while (*s) {
;		if (*s == c)
;			return ((char *)s);
;		++s;
;	}
;	if (c == '\0')
;		return ((char *)s);
;	return (NULL);
;}

;static int	ft_isspace(int c) {
;	return (c == ' ' || (9 <= c && c <= 13));
;}
