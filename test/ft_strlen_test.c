/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/25 21:14:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

static int	test_strlen_helper(const char *s);

void	test_strlen(void)
{
	char	*buffer;

	assert(test_strlen_helper(""));
	assert(test_strlen_helper("a"));
	assert(test_strlen_helper("ab"));
	assert(test_strlen_helper("abc"));
	buffer = calloc(sizeof(char), 1024 * 1024);
	if (!buffer)
	{
		perror("malloc");
		exit(1);
	}
	assert(test_strlen_helper(memset(buffer, 'a', 1000)));
	assert(test_strlen_helper(memset(buffer, 'a', 1024 * 1024 - 1)));
	buffer[1024 * 1000] = '\0';
	assert(test_strlen_helper(buffer));
	buffer[1024 * 100] = '\0';
	assert(test_strlen_helper(buffer));
	buffer[1024 * 10] = '\0';
	assert(test_strlen_helper(buffer));
	free(buffer);
	return ;
}

static int	test_strlen_helper(const char *s)
{
	return (ft_strlen(s) == strlen(s));
}
