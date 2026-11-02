/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:37:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/25 22:04:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	*set_random_string(char *buf, size_t len);

char	*random_string(u_int32_t min_len, u_int32_t max_len)
{
	u_int32_t	len;
	char		*str;

	if (min_len > max_len)
		return (NULL);
	len = min_len + (u_int32_t)rand() % (max_len - min_len + 1);
	str = calloc(sizeof(char), len + 1);
	if (!str)
	{
		perror("malloc");
		exit(1);
	}
	return (set_random_string(str, len));
}

static char	*set_random_string(char *buf, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		buf[i++] = (char)(32 + rand() % 95);
	buf[i] = '\0';
	return (buf);
}
