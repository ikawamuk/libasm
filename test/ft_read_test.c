/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:18:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/30 10:27:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	test_read(void)
{
	const char	msg[] = "hello write\n";
	char		read_buf[100];
	int			pipefd[2];

	errno = 0;
	assert(ft_read(-1, read_buf, sizeof(read_buf)) == -1);
	assert(errno == EBADF);
	if (pipe(pipefd))
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	write(pipefd[1], msg, sizeof(msg));
	close(pipefd[1]);
	bzero(read_buf, sizeof(read_buf));
	assert(ft_read(pipefd[0], read_buf, sizeof(read_buf)) == sizeof(msg));
	assert(!memcmp(msg, read_buf, sizeof(msg)));
	close(pipefd[0]);
}
