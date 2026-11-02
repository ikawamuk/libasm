/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simd_memchr_bonus_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 16:56:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <assert.h>
#include <string.h>

static int	test_simd_memchr_helper(const void *s, int c, size_t n);

void	test_simd_memchr(void)
{
	assert(test_simd_memchr_helper("A", 'A', 2));
	assert(test_simd_memchr_helper("AB", 'A', 3));
	assert(test_simd_memchr_helper("AB", 'B', 3));
	assert(test_simd_memchr_helper("ABC", 'A', 4));
	assert(test_simd_memchr_helper("ABC", 'B', 4));
	assert(test_simd_memchr_helper("ABC", 'C', 4));
}

static int	test_simd_memchr_helper(const void *s, int c, size_t n)
{
	return (ft_simd_memchr(s, c, n) == memchr(s, c, n));
}
