global ft_list_sort
section .text

ft_list_sort:
.null_check:
	cmp rdi, 0
	je .return
	cmp qword [rdi], 0
	je .return
	push rbx
	push r12
	push r13
	push r14
	push r15
	mov rbx, rdi ; begin_list
	mov r12, rsi ; cmp
	mov r13, 0   ; end
.outer_loop:
	cmp r13, [rbx]
	je .outer_done
	mov r14, [rbx]     ; prev
	mov r15, [r14 + 8] ; cur
.inner_loop:
	cmp r15, r13
	je .inner_done
	mov rdi, [r14]
	mov rsi, [r15]
	call r12
	cmp eax, 0
	jle .inner_advance
	mov r8, [r14]
	mov r9, [r15]
	mov [r14], r9
	mov [r15], r8
.inner_advance:
	mov r14, r15
	mov r15, [r15 + 8]
	jmp .inner_loop
.inner_done:
	mov r13, r14
	jmp .outer_loop
.outer_done:
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
.return:
	ret

;void	ft_list_sort(t_list **begin_list, int (*cmp)()) {
;	if (!begin_list || !*begin_list) return ;
;	t_list *end = NULL;
;	while (end != *begin_list) {
;		t_list *prev = *begin_list;
;		t_list *cur = prev->next;
;		for (; cur != end; prev = cur, cur = cur->next) {
;			if (cmp(prev->data, cur->data) > 0) {
;				void	*tmp = prev->data;
;				prev->data = cur->data;
;				cur->data = tmp;
;			}
;		}
;		end = prev;
;	}
;}
