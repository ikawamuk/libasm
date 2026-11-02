global ft_list_push_front
extern malloc
section .text
ft_list_push_front:
	push r12
	push r13
	push rax
	mov r12, rdi ; begin_list
	mov r13, rsi ; data
	mov rdi, 16
	call malloc wrt ..plt
	cmp rax, 0
	je .return
	mov qword [rax], r13
	mov r8, [r12]
	mov qword [rax + 8], r8
	mov qword [r12], rax
.return:
	add rsp, 8
	pop r13
	pop r12
	ret

;void	ft_list_push_front(t_list **begin_list, void *data) {
;	t_list	*new_node = malloc(sizeof(t_list));
;	if (!new_node) return;
;	new_node->data = data;
;	new_node->next = *begin_list;
;	*begin_list = new_node;
;	return ;
;}
