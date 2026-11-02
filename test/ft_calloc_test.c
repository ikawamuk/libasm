/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 02:24:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>

// errno
static int	test_calloc_helper(size_t nmemb, size_t size);

void	test_calloc(void)
{
	assert(test_calloc_helper(10, 4));
	assert(test_calloc_helper(1, 1));
	assert(test_calloc_helper(1000, 1000));
	assert(test_calloc_helper(0, 0));
	assert(test_calloc_helper(0, 100));
	assert(test_calloc_helper(100, 0));
	assert(ft_calloc(SIZE_MAX, 2) == NULL && errno == ENOMEM);
	assert(ft_calloc(SIZE_MAX / 2 + 1, 2) == NULL && errno == ENOMEM);
	assert(ft_calloc(SIZE_MAX / 3 + 1, 3) == NULL && errno == ENOMEM);
}

static int	test_calloc_helper(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			n;
	size_t			i;

	p = ft_calloc(nmemb, size);
	if (nmemb == 0 || size || 0)
	{
		free(p);
		return (1);
	}
	assert(p != NULL);
	n = nmemb * size;
	i = 0;
	while (i < n)
		if (p[i++] != 0)
			return (0);
	free(p);
	return (1);
}
