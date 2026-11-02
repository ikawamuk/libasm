/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 16:57:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

const void	*list_at(const t_list *list, size_t index);

static void	generate_char_list(t_list **list_head_p, char *str);

void	test_list_remove_if(void)
{
	t_list	*list_head;

	list_head = NULL;
	generate_char_list(&list_head, "ABCABA");
	assert(ft_list_size(list_head) == 6);
	assert(!ft_strcmp(list_at(list_head, 0), "A"));
	assert(!ft_strcmp(list_at(list_head, 1), "B"));
	assert(!ft_strcmp(list_at(list_head, 2), "C"));
	assert(!ft_strcmp(list_at(list_head, 3), "A"));
	assert(!ft_strcmp(list_at(list_head, 4), "B"));
	assert(!ft_strcmp(list_at(list_head, 5), "A"));
	ft_list_remove_if(&list_head, "A", ft_strcmp, free);
	assert(ft_list_size(list_head) == 3);
	assert(!ft_strcmp(list_at(list_head, 0), "B"));
	assert(!ft_strcmp(list_at(list_head, 1), "C"));
	assert(!ft_strcmp(list_at(list_head, 2), "B"));
	ft_list_remove_if(&list_head, "B", ft_strcmp, free);
	assert(ft_list_size(list_head) == 1);
	assert(!ft_strcmp(list_at(list_head, 0), "C"));
	ft_list_remove_if(&list_head, "X", ft_strcmp, free);
	assert(ft_list_size(list_head) == 1);
	assert(!ft_strcmp(list_at(list_head, 0), "C"));
	ft_list_remove_if(&list_head, "C", ft_strcmp, free);
	assert(ft_list_size(list_head) == 0);
	assert(list_at(list_head, 0) == NULL);
}

static void	generate_char_list(t_list **list_head_p, char *str)
{
	size_t	list_size;
	char	*cp;

	*list_head_p = NULL;
	list_size = ft_strlen(str);
	while (list_size != 0)
	{
		cp = malloc(sizeof(char) * 2);
		if (!cp)
		{
			perror("malloc");
			exit(1);
		}
		cp[0] = str[list_size - 1];
		cp[1] = '\0';
		ft_list_push_front(list_head_p, cp);
		--list_size;
	}
}
