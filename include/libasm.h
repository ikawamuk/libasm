/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 01:16:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/10/25 21:32:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>
# include <sys/types.h>

/* mandatory */

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);

/* bonus */

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

int				ft_atoi_base(char *str, char *base);
void			ft_list_push_front(t_list **begin_list, void *data);
unsigned int	ft_list_size(t_list *begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_remove_if(t_list **begin_list, void *data_ref, \
						int (*cmp)(), void (*free_fct)(void *));
void			*ft_simd_memchr(const void *s, int c, size_t n);

#endif
