global ft_read
extern __errno_location
section .text
ft_read:
	mov eax, 0
	syscall
	cmp rax, -4095
	jae .error
	ret
.error:
	push rax
	call __errno_location wrt ..plt
	pop rdx
	neg rdx
	mov [rax], edx
	mov rax, -1
	ret

;ssize_t read(int fd, void *buf, size_t count) {
;	long int	return_value;
;	__asm__ __volatile__ (
;		"syscall" 
;		: "=a"(return_value)
;		: "a"(2), "D"(fd), "S"(buf), "d"(count)
;		: "rcx", "r11", "memory"
;	);
;	if ((unsigned long int)return_value >= -4095UL) {
;		errno = -return_value;
;		return (-1);
;	}
;	return (return_value);
;}
