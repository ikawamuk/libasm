/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 16:57:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdlib.h>
#include <assert.h>

void		generate_random_list(t_list **list_head_p, size_t size);
void		ft_list_clear(t_list *list_head, void (*del)(void *));

static int	test_list_sort_helper(size_t list_size);

void	test_list_sort(void)
{
	assert(test_list_sort_helper(0));
	assert(test_list_sort_helper(1));
	assert(test_list_sort_helper(2));
	assert(test_list_sort_helper(100));
}

static int	test_list_sort_helper(size_t list_size)
{
	int		result;
	t_list	*list_head;
	t_list	*cur;
	t_list	*prev;

	list_head = NULL;
	generate_random_list(&list_head, list_size);
	ft_list_sort(&list_head, ft_strcmp);
	result = 1;
	if (!list_head || !list_head->next)
	{
		ft_list_clear(list_head, free);
		return (1);
	}
	prev = list_head;
	cur = prev->next;
	while (cur)
	{
		if (ft_strcmp(prev->data, cur->data) > 0)
			result = 0;
		prev = cur;
		cur = cur->next;
	}
	ft_list_clear(list_head, free);
	return (result);
}
