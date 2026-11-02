global ft_list_remove_if
extern free
section .text
ft_list_remove_if:
	push rbx
	push r12
	push r13
	push r14
	push r15
	cmp rdi, 0
	je .return
	mov rbx, rdi ; link
	mov r12, rsi ; data_ref
	mov r13, rdx ; cmp
	mov r14, rcx ; free_fct
.loop:
	cmp qword [rbx], 0
	je .return
	mov r15, [rbx] ; cur
	mov rdi, [r15]
	mov rsi, r12
	call r13
	cmp eax, 0
	jne .advance_loop
	mov r8,  [r15 + 8]
	mov [rbx], r8
	mov rdi, [r15]
	call r14
	mov rdi, r15
	call free wrt ..plt
	jmp .loop
.advance_loop:
	lea rbx, [r15 + 8]
	jmp .loop
.return:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	ret

;void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)) {
;	if (!begin_list) return;
;	t_list **link = begin_list;
;	while (*link) {
;		t_list *cur = *link;
;		if (cmp(cur->data, data_ref) == 0) {
;			*link = cur->next;
;			free_fct(cur->data);
;			free(cur);
;			continue ;
;		}
;		link = &cur->next;
;	}
;}
