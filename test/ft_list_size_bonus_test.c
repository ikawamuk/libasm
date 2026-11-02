/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 13:24:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <assert.h>
#include <stdlib.h>

void	generate_random_list(t_list **list_head_p, size_t size);
void	ft_list_clear(t_list *list_head, void (*del)(void *));

void	test_list_size(void)
{
	t_list	*list_head;

	list_head = NULL;
	generate_random_list(&list_head, 0);
	assert(ft_list_size(list_head) == 0);
	ft_list_clear(list_head, free);
	list_head = NULL;
	generate_random_list(&list_head, 1);
	assert(ft_list_size(list_head) == 1);
	ft_list_clear(list_head, free);
	list_head = NULL;
	generate_random_list(&list_head, 2);
	assert(ft_list_size(list_head) == 2);
	ft_list_clear(list_head, free);
	list_head = NULL;
	generate_random_list(&list_head, 100);
	assert(ft_list_size(list_head) == 100);
	ft_list_clear(list_head, free);
}
