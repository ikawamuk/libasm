/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/26 18:20:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

char		*random_string(u_int32_t min_len, u_int32_t max_len);
static void	test_strcmp_helper(const char *s1, const char *s2);

void	test_strcmp(void)
{
	static const u_int32_t	max_len = 1024 * 1024;
	char					*s1;
	char					*s2;
	size_t					i;

	test_strcmp_helper("", "");
	test_strcmp_helper("", "a");
	test_strcmp_helper("b", "");
	test_strcmp_helper("c", "c");
	test_strcmp_helper("de", "def");
	test_strcmp_helper("ghixyz", "ghi");
	test_strcmp_helper("jkl", "l");
	test_strcmp_helper("l", "jkl");
	i = 0;
	while (i++ < 100)
	{
		s1 = random_string(0, max_len);
		s2 = random_string(0, max_len);
		test_strcmp_helper(s1, s2);
		free(s1);
		free(s2);
	}
}

/* 
	Under non-POSIX-compliant environments, 
	use the following condition in place of (actual != expected)
	(((actual > 0) - (actual < 0)) != ((expected > 0) - (expected < 0)))
*/
static void	test_strcmp_helper(const char *s1, const char *s2)
{
	int	actual;
	int	expected;

	actual = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	if (((actual > 0) - (actual < 0)) != ((expected > 0) - (expected < 0)))
	{
		fprintf(stderr, "FAIL: s1:'%s' s2:'%s', \
			expected:%d actual:%d\n", s1, s2, expected, actual);
		exit(EXIT_FAILURE);
	}
	return ;
}
