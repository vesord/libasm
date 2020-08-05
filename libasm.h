/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:04:32 by matrus            #+#    #+#             */
/*   Updated: 2020/08/05 08:34:00 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <errno.h>

	size_t	ft_strlen(char *str);
	char	*ft_strcpy(char *dst, char *src);
	int		ft_strcmp(char *s1, char *s2);
	ssize_t	ft_write(int fd, const void *buf, size_t count);
	ssize_t	ft_read(int fd, const void *buf, size_t count);
	char	*ft_strdup(char *s);

	int		ft_atoi_base(char *str, int str_base);

#endif
