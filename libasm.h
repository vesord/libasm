/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:04:32 by matrus            #+#    #+#             */
/*   Updated: 2020/08/06 09:51:49 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <errno.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

	size_t	ft_strlen(char *str);
	char	*ft_strcpy(char *dst, char *src);
	int		ft_strcmp(char *s1, char *s2);
	ssize_t	ft_write(int fd, const void *buf, size_t count);
	ssize_t	ft_read(int fd, const void *buf, size_t count);
	char	*ft_strdup(char *s);

	int		ft_atoi_base(char *str, int str_base);
	t_list	*ft_create_elem(void *data);
	void	ft_list_push_front(t_list **begin_list, void *data);
	int		ft_list_size(t_list *begin_list);
	void	ft_list_sort(t_list **begin_list, int (*cmp)(void*, void*));

#endif
