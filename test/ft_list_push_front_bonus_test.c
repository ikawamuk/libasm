/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_bonus_test.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 13:24:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <assert.h>
#include <stdlib.h>

void	test_list_push_front(void)
{
	t_list		*list;
	t_list		*next;
	int			i;
	const char	array[] = "012345";

	list = NULL;
	ft_list_push_front(&list, (void *)&array[0]);
	ft_list_push_front(&list, (void *)&array[1]);
	ft_list_push_front(&list, (void *)&array[2]);
	ft_list_push_front(&list, (void *)&array[3]);
	ft_list_push_front(&list, (void *)&array[4]);
	ft_list_push_front(&list, (void *)&array[5]);
	ft_list_push_front(&list, (void *)&array[6]);
	i = sizeof(array) - 1;
	while (i >= 0)
	{
		assert(list != NULL);
		next = list->next;
		assert((char *)list->data == &array[i--]);
		free(list);
		list = next;
	}
	assert(list == NULL);
}
