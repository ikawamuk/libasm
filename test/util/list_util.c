/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:08:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 16:27:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdlib.h>

char	*random_string(u_int32_t min_len, u_int32_t max_len);

void	ft_list_clear(t_list *list_head, void (*del)(void *))
{
	t_list	*next;

	while (list_head)
	{
		next = list_head->next;
		if (del)
			del(list_head->data);
		free(list_head);
		list_head = next;
	}
}

void	generate_random_list(t_list **list_head_p, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		ft_list_push_front(list_head_p, random_string(0, 10));
}

const void	*list_at(const t_list *list, size_t index)
{
	size_t	i;

	i = 0;
	while (list && i++ < index)
		list = list->next;
	if (!list)
		return (NULL);
	return (list->data);
}
