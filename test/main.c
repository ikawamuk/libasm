/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:10:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/11/01 16:55:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_strlen(void);
void	test_strcpy(void);
void	test_strcmp(void);
void	test_write(void);
void	test_read(void);
void	test_strdup(void);
void	test_calloc(void);
void	test_atoi_base(void);
void	test_list_push_front(void);
void	test_list_size(void);
void	test_list_sort(void);
void	test_list_remove_if(void);
void	test_simd_memchr(void);

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	test_calloc();
	test_atoi_base();
	test_list_push_front();
	test_list_size();
	test_list_sort();
	test_list_remove_if();
	test_simd_memchr();
	return (0);
}
