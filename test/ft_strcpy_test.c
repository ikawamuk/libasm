/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/25 22:05:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

char		*random_string(u_int32_t min_len, u_int32_t max_len);
static void	test_strcpy_helper(const char *src);

void	test_strcpy(void)
{
	static const u_int32_t	max_len = 1024 * 1024;
	size_t					i;
	char					*src;

	test_strcpy_helper("");
	test_strcpy_helper("a");
	test_strcpy_helper("bc");
	test_strcpy_helper("def");
	i = 0;
	while (i++ < 100)
	{
		src = random_string(0, max_len);
		test_strcpy_helper(src);
		free(src);
	}
	return ;
}

static void	test_strcpy_helper(const char *src)
{
	char	*dst;
	char	*return_value;

	dst = calloc(sizeof(char), strlen(src) + 1);
	if (!dst)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return_value = ft_strcpy(dst, src);
	assert(return_value == dst);
	if (!strcmp(dst, src))
	{
		free(dst);
		return ;
	}
	fprintf(stderr, "FAIL: strings are not equal. \
		src:'%s' dst:'%s'\n", src, dst);
	free(dst);
	exit(EXIT_FAILURE);
}
