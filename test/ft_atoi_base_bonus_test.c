/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 03:14:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 07:35:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <assert.h>

static void	easy_case(void);
static void	complicated_case(void);
static void	error_case(void);

void	test_atoi_base(void)
{
	easy_case();
	complicated_case();
	error_case();
}

static void	easy_case(void)
{
	assert(ft_atoi_base("0", "0123456789") == 0);
	assert(ft_atoi_base("1", "0123456789") == 1);
	assert(ft_atoi_base("2", "0123456789") == 2);
	assert(ft_atoi_base("9", "0123456789") == 9);
	assert(ft_atoi_base("10", "0123456789") == 10);
	assert(ft_atoi_base("109", "0123456789") == 109);
	assert(ft_atoi_base("0", "0123") == 0);
	assert(ft_atoi_base("1", "0123") == 1);
	assert(ft_atoi_base("2", "0123") == 2);
	assert(ft_atoi_base("3", "0123") == 3);
	assert(ft_atoi_base("10", "0123") == 4);
	assert(ft_atoi_base("103", "0123") == 19);
	assert(ft_atoi_base("0", "01") == 0);
	assert(ft_atoi_base("1", "01") == 1);
	assert(ft_atoi_base("10", "01") == 2);
	assert(ft_atoi_base("101", "01") == 5);
	assert(ft_atoi_base("0", "0123456789ABCDEF") == 0);
	assert(ft_atoi_base("1", "0123456789ABCDEF") == 1);
	assert(ft_atoi_base("F", "0123456789ABCDEF") == 15);
	assert(ft_atoi_base("10", "0123456789ABCDEF") == 16);
	assert(ft_atoi_base("10F", "0123456789ABCDEF") == 271);
	assert(ft_atoi_base("z", "0123456789abcdefghijklmnopqrstuvwxyz") == 35);
	assert(ft_atoi_base("zz", "0123456789abcdefghijklmnopqrstuvwxyz") == 1295);
}

static void	complicated_case(void)
{
	assert(ft_atoi_base("", "0123456789") == 0);
	assert(ft_atoi_base("A", "0123456789") == 0);
	assert(ft_atoi_base("1A", "0123456789") == 1);
	assert(ft_atoi_base("10A9", "0123456789") == 10);
	assert(ft_atoi_base("4", "0123") == 0);
	assert(ft_atoi_base("14", "0123") == 1);
	assert(ft_atoi_base("1043", "0123") == 4);
	assert(ft_atoi_base("2", "01") == 0);
	assert(ft_atoi_base("102", "01") == 2);
	assert(ft_atoi_base("X", "0123456789ABCDEF") == 0);
	assert(ft_atoi_base("10f", "0123456789ABCDEF") == 16);
	assert(ft_atoi_base("0", "9876543210") == 9);
	assert(ft_atoi_base("1", "9876543210") == 8);
	assert(ft_atoi_base("2", "9876543210") == 7);
	assert(ft_atoi_base("9", "9876543210") == 0);
	assert(ft_atoi_base("10", "9876543210") == 89);
	assert(ft_atoi_base("109", "9876543210") == 890);
}

static void	error_case(void)
{
	assert(ft_atoi_base("1", "a") == 0);
	assert(ft_atoi_base("1", "") == 0);
	assert(ft_atoi_base("1", " 01") == 0);
	assert(ft_atoi_base("1", "0-1") == 0);
	assert(ft_atoi_base("1", "01+") == 0);
	assert(ft_atoi_base("1", "11") == 0);
	assert(ft_atoi_base("1", "0120") == 0);
}
