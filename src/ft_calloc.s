global ft_calloc
extern malloc, __errno_location
section .text
ft_calloc:
	push rbx
.check_size_is_zero:
	mov rbx, rsi
	cmp rbx, 0
	je .allocate
.check_overflow:
	mov rax, rbx
	mul rdi
	jno .allocate
.no_memory_error:
	call __errno_location wrt ..plt
	mov dword [rax], 12
	jmp .error
.allocate:
	imul rbx, rdi
	mov rdi, rbx
	call malloc wrt ..plt
	cmp rax, 0
	je .error
	mov rdi, rax
	mov rsi, 0
	mov rdx, rbx
	call ft_memset
	jmp .return
.error:
	mov rax, 0
.return:
	pop rbx
	ret

;void	*ft_calloc(size_t nmemb, size_t size) {
;	if (size && nmemb > (size_t)-1 / size) {
;		errno = ENOMEM;
;		return (NULL);
;	}
;	size *= nmemb;
;	void	*p = malloc(size);
;	if (!p)
;		return (NULL);
;	return (ft_memset(p, 0, size));
;}

ft_memset:
	mov r8, rdi
	cmp rdx, 0
	je .return
	mov [r8], sil
	mov [r8 + rdx - 1], sil
	cmp rdx, 3
	jb .return
	mov [r8 + 1], sil
	mov [r8 + 2], sil
	mov [r8 + rdx - 2], sil
	mov [r8 + rdx - 3], sil
	cmp rdx, 7
	jb .return
	mov [r8 + 3], sil
	mov [r8 + rdx - 4], sil
	cmp rdx, 9
	jb .return
	mov r9d, r8d
	neg r9d
	and r9d, 3
	add r8, r9
	sub rdx, r9
	and rdx, -4
	movzx r10d, sil
	imul r10d, r10d, 0x01010101
	mov dword [r8], r10d
	mov dword [r8 + rdx - 4], r10d
	cmp	rdx, 9
	jb .return
	mov dword [r8 + 4], r10d
	mov dword [r8 + 8], r10d
	mov dword [r8 + rdx - 8], r10d
	mov dword [r8 + rdx - 12], r10d
	cmp	rdx, 25
	jb .return
	movd xmm0, r10d
	pshufd xmm0, xmm0, 0
	movdqu [r8 + 12], xmm0
	movdqu [r8 + rdx - 28], xmm0
	mov r9d, r8d
	and r9d, 4
	or r9, 24
	add r8, r9
	sub rdx, r9
	mov r11d, r10d
	shl r11, 32
	or r11, r10
.while:
	cmp rdx, 32
	jb .return
	mov [r8], r11
	mov [r8 + 8], r11
	mov [r8 + 16], r11
	mov [r8 + 24], r11
	add r8, 32
	sub rdx, 32
	jmp .while
.return:
	mov rax, rdi
	ret

;void	*ft_memset(void *s, int c, size_t n) {
;	unsigned char	*p = s;
;	size_t			k;
;
;	if (n == 0) return (s);
;	p[0] = c;
;	p[n - 1] = c;
;	if (n <= 2) return (s);
;	p[1] = c;
;	p[2] = c;
;	p[n - 2] = c;
;	p[n - 3] = c;
;	if (n <= 6) return (s);
;	p[3] = c;
;	p[n - 4] = c;
;	if (n <= 8) return (s);
;
;	k = -(uintptr_t)p & 3;
;	p += k;
;	n -= k;
;	n &= -4;
;
;	uint32_t	c32 = ((uint32_t)-1) / 255 * (unsigned char)c;
;	size_t		n32 = n / 4;
;	((uint32_t *)p)[0] = c32;
;	((uint32_t *)p)[n32 - 1] = c32;
;	if (n <= 8) return (s);
;	((uint32_t *)p)[1] = c32;
;	((uint32_t *)p)[2] = c32;
;	((uint32_t *)p)[n32 - 2] = c32;
;	((uint32_t *)p)[n32 - 3] = c32;
;	if (n <= 24) return (s);
;	((uint32_t *)p)[3] = c32;
;	((uint32_t *)p)[4] = c32;
;	((uint32_t *)p)[5] = c32;
;	((uint32_t *)p)[6] = c32;
;	((uint32_t *)p)[n32 - 4] = c32;
;	((uint32_t *)p)[n32 - 5] = c32;
;	((uint32_t *)p)[n32 - 6] = c32;
;	((uint32_t *)p)[n32 - 7] = c32;
;	k  = 24 + ((uintptr_t)p & 4);
;	p += k;
;	n -= k;
;	uint64_t	c64 = c32 | ((uint64_t)c32 << 32);
;	for (; n >= 32; n -= 32, p += 32) {
;		((uint64_t *)p)[0] = c64;
;		((uint64_t *)p)[1] = c64;
;		((uint64_t *)p)[2] = c64;
;		((uint64_t *)p)[3] = c64;
;	}
;	return (s);
;}
