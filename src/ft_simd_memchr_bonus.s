section .text
global ft_simd_memchr

ft_simd_memchr:
	mov rax, rdi ; p
	movd xmm0, esi ; v_target
	punpcklbw xmm0, xmm0
	pshuflw xmm0, xmm0, 0
	pshufd xmm0, xmm0, 0
	xor r8d, r8d ; i = 0
	cmp rdx, 16
	jb .byte_loop
.sse_loop:
	movdqu xmm1, [rax + r8] ; v_chunk
	pcmpeqb xmm1, xmm0 ; v_cmp
	pmovmskb ecx, xmm1 ; mask
	cmp ecx, 0
	jnz .found_simd
	add r8, 16
	mov rcx, r8
	add rcx, 16
	cmp rcx, rdx
	jbe .sse_loop
.byte_loop:
	cmp r8, rdx
	jae .not_found
	cmp byte [rax + r8], sil
	je .found_byte
	inc r8
	jmp .byte_loop
.found_simd:
	bsf ecx, ecx
	add rax, r8
	add rax, rcx
	ret
.found_byte:
	add rax, r8
	ret
.not_found:
	mov eax, 0
	ret

;#include <immintrin.h>
;void	*ft_simd_memchr(const void *s, int c, size_t n) {
;	const unsigned char* p = (const unsigned char*)s;
;	unsigned char target = (unsigned char)c;
;	__m128i	v_target = _mm_set1_epi8(target);
;	size_t	i = 0;
;	for (; i + 16 <= n; i += 16) {
;		__m128i	v_chunk = _mm_loadu_si128((const __m128i *)&p[i]);
;		__m128i	v_cmp = _mm_cmpeq_epi8(v_chunk, v_target);
;		int		mask = _mm_movemask_epi8(v_cmp);
;		if (mask != 0) {
;			int	offset = __builtin_ctz(mask);
;			return ((void *)&p[i + offset]);
;		}
;	}
;	for (; i < n; i++) {
;		if (p[i] == target)
;			return ((void *)&p[i]);
;	}
;	return (NULL);
;}
