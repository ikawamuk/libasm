/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/30 10:27:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

char		*random_string(u_int32_t min_len, u_int32_t max_len);

static void	test_strdup_helper(const char *src);

void	test_strdup(void)
{
	static const u_int32_t	max_len = 1024 * 1024;
	size_t					i;
	char					*src;

	test_strdup_helper("");
	test_strdup_helper("a");
	test_strdup_helper("bc");
	test_strdup_helper("def");
	i = 0;
	while (i++ < 100)
	{
		src = random_string(0, max_len);
		test_strdup_helper(src);
		free(src);
	}
	return ;
}

static void	test_strdup_helper(const char *src)
{
	char	*dst;

	dst = ft_strdup(src);
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
