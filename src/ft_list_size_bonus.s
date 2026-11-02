global ft_list_size
extern malloc
section .text

ft_list_size:
	mov rax,0
.loop:
	cmp rdi, 0
	je .return
	inc rax
	mov rdi, [rdi + 8]
	jmp .loop
.return:
	ret


;unsigned int	ft_list_size(t_list *begin_list)
;{
;	unsigned int	size = 0;
;	while (begin_list)
;	{
;		++size;
;		begin_list = begin_list->next;
;	}
;	return (size);
;}
