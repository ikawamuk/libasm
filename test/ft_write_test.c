/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/28 14:24:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	test_write(void)
{
	const char	msg[] = "hello write\n";
	char		read_buf[100];
	int			pipefd[2];
	char		extra;

	errno = 0;
	assert(ft_write(-1, msg, sizeof(msg)) == -1);
	assert(errno == EBADF);
	if (pipe(pipefd))
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	errno = 0;
	assert(ft_write(pipefd[1], msg, sizeof(msg)) == sizeof(msg));
	assert(errno == 0);
	close(pipefd[1]);
	bzero(read_buf, sizeof(read_buf));
	assert(read(pipefd[0], read_buf, sizeof(msg)) == sizeof(msg));
	assert(!memcmp(msg, read_buf, sizeof(msg)));
	assert(read(pipefd[0], &extra, 1) == 0);
	close(pipefd[0]);
}
