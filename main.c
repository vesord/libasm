/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:05:42 by matrus            #+#    #+#             */
/*   Updated: 2020/08/05 15:08:15 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	ft_strlen_test()
{
	printf("\t\tSTRLEN_TEST\n\n");
	printf("%li\n", ft_strlen(""));
	printf("%li\n", ft_strlen("1"));
	printf("%li\n", ft_strlen("12"));
	printf("%li\n", ft_strlen("123"));
	printf("%li\n", ft_strlen("1234"));
}

void	ft_strcpy_test()
{
	char *str;

	printf("\n\n\t\tSTRCPY_TEST\n\n");
	str = (char*)malloc(sizeof(char) * 5);
	printf("%s\n", ft_strcpy(str, "1"));
	printf("%s\n", ft_strcpy(str, "12"));
	printf("%s\n", ft_strcpy(str, "123"));
	printf("%s\n", ft_strcpy(str, "1234"));
	free(str);
}

void	ft_strcmp_test()
{
	printf("\n\n\t\tSTRCMP_TEST\n\n");
	printf("eq: %i\n", ft_strcmp("123", "123"));
	printf("eq: %i\n", ft_strcmp("", ""));
	printf("eq: %i\n", ft_strcmp("123\200", "123\200"));
	printf("l : %i\n", ft_strcmp("1", "123"));
	printf("l : %i\n", ft_strcmp("", "123"));
	printf("l : %i\n", ft_strcmp("123", "123abc"));
	printf("l : %i\n", ft_strcmp("123", "123\200"));
	printf("g : %i\n", ft_strcmp("123", "1"));
	printf("g : %i\n", ft_strcmp("123", ""));
	printf("g : %i\n", ft_strcmp("123abc", "123"));
	printf("g : %i\n", ft_strcmp("123\200", "123"));
}

void	ft_write_test()
{
	printf("\n\n\t\tWRITE_TEST\n\n");
	printf("ft_write ret: %li\n\n", ft_write(1, "Hello, world!\n", 15));
	printf("errno: %i\n", errno);
	printf("ft_write ret: %li\n\n", ft_write(1, "Hello, world!\n", 5));
	printf("errno: %i\n", errno);
	printf("ft_write ret: %li\n\n", ft_write(1, "Hello, world!\n", 0));
	printf("errno: %i\n", errno);
	printf("ft_write ret: %li\n\n", ft_write(1, "Hello, world!\n", -5));
	printf("errno: %i\n", errno);
	printf("ft_write ret: %li\n\n", ft_write(9, "Hello, world!\n", 15));
	printf("errno: %i\n", errno);
}

void	ft_read_test()
{
	char	*buf;
	int		fd;

	printf("\n\n\t\tREAD_TEST\n\n");
	buf = (char*)calloc(255, sizeof(char));
	printf("ft_read ret: %li\nstring: %s\n", ft_read(0, buf, 10), buf);
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);
	
	printf("ft_read ret: %li\nstring: %s\n", ft_read(0, buf, 10), buf);
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);

	fd = open("./main.c", O_RDWR);
	printf("ft_read ret: %li\nstring: %s\n", ft_read(fd, buf, 255), buf);	
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);
	close(fd);
	
	fd = open("./main.c", O_WRONLY);
	printf("ft_read ret: %li\nstring: %s\n", ft_read(fd, buf, 255), buf);
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);

	printf("ft_read ret: %li\nstring: %s\n", ft_read(0, buf, -10), buf);
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);
	
	printf("ft_read ret: %li\nstring: %s\n", ft_read(74, buf, 10), buf);
	printf("errno: %i\n\n", errno);
	bzero(buf, 255);

	free(buf);
}

void	ft_strdup_test()
{
	char *s;

	printf("\n\n\t\tSTRDUP_TEST\n\n");
	printf("s1: %s\n", (s = ft_strdup("Hello, world!\n")));
	free(s);
	printf("s2: %s\n", (s = ft_strdup("\n")));
	free(s);
	printf("s3: %s\n", (s = ft_strdup("")));
	free(s);
	printf("s4: %s\n", (s = ft_strdup("12345678901234567890\n")));
	free(s);
	printf("s5: %s\n", (s = ft_strdup("Hello92834\n")));
	free(s);
}

void	ft_atoi_base_test()
{
//	char i = 33;
//
//	while (i < 127)
//	{
//		printf("char to int %c: %i\n", i, ft_atoi_base(&i, 16));
//		i++;
//	}
	printf("str: %16s, base: %2i, int: %i\n", "", 10,  ft_atoi_base("", 10));
	printf("str: %16s, base: %2i, int: %i\n", "4", 10,  ft_atoi_base("4", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-4", 10,  ft_atoi_base("-4", 10));
	printf("str: %16s, base: %2i, int: %i\n", "0", 10,  ft_atoi_base("0", 10));
	printf("str: %16s, base: %2i, int: %i\n", "8oo", 10,  ft_atoi_base("8oo", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-73two", 10,  ft_atoi_base("-73two", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-333-", 10,  ft_atoi_base("-333-", 10));
	printf("str: %16s, base: %2i, int: %i\n", "--8", 10,  ft_atoi_base("--8", 10));
	printf("str: %16s, base: %2i, int: %i\n", "ff", 16,  ft_atoi_base("ff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "1f", 16,  ft_atoi_base("1f", 16));
	printf("str: %16s, base: %2i, int: %i\n", "-f", 16,  ft_atoi_base("-f", 16));
	printf("str: %16s, base: %2i, int: %i\n", "-00ff", 16,  ft_atoi_base("-00ff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "fedcba9", 16,  ft_atoi_base("fedcba9", 16));
	printf("str: %16s, base: %2i, int: %i\n", "-fedcba9", 16,  ft_atoi_base("-fedcba9", 16));
	printf("str: %16s, base: %2i, int: %i\n", "1010", 2,  ft_atoi_base("1010", 2));
	printf("str: %16s, base: %2i, int: %i\n", "11111110", 2,  ft_atoi_base("11111110", 2));
	printf("str: %16s, base: %2i, int: %i\n", "-1", 2,  ft_atoi_base("-1", 2));
	printf("str: %16s, base: %2i, int: %i\n", "-11112110", 2,  ft_atoi_base("-11112110", 2));
	printf("str: %16s, base: %2i, int: %i\n", "111", 2,  ft_atoi_base("111", 2));
	printf("str: %16s, base: %2i, int: %i\n", "0", 2,  ft_atoi_base("0", 2));
	printf("str: %16s, base: %2i, int: %i\n", "7fffffff", 16,  ft_atoi_base("7fffffff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "7FFFffff", 16,  ft_atoi_base("7FFFffff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "7ffffffF", 16,  ft_atoi_base("7ffffffF", 16));
	printf("str: %16s, base: %2i, int: %i\n", "7fffFFFf", 16,  ft_atoi_base("7fffFFFf", 16));
	printf("str: %16s, base: %2i, int: %i\n", "4A5561", 12,  ft_atoi_base("4A5561", 12));
	printf("str: %16s, base: %2i, int: %i\n", "3030", 6,  ft_atoi_base("3030", 6));
	printf("str: %16s, base: %2i, int: %i\n", "15B9D2A", 15,  ft_atoi_base("15B9D2A", 15));
	printf("str: %16s, base: %2i, int: %i\n", "-15B9D2A", 15,  ft_atoi_base("-15B9D2A", 15));
	printf("str: %16s, base: %2i, int: %i\n", "   -4", 10,  ft_atoi_base("   -4", 10));
	printf("str: %16s, base: %2i, int: %i\n", " \t0", 10,  ft_atoi_base(" \t0", 10));
	printf("str: %16s, base: %2i, int: %i\n", " 8oo", 10,  ft_atoi_base(" 8oo", 10));
	printf("str: %16s, base: %2i, int: %i\n", "\t-73two", 10,  ft_atoi_base("\t-73two", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-0000000000001", 2,  ft_atoi_base("-0000000000001", 2));
	printf("str: %16s, base: %2i, int: %i\n", "-00000000000a1", 2,  ft_atoi_base("-00000000000a1", 2));
	printf("str: %16s, base: %2i, int: %i\n", "0000000010001", 2,  ft_atoi_base("0000000010001", 2));
}

int main(void)
{
	ft_atoi_base_test();
//	ft_strlen_test();
//	ft_strcmp_test();
//	ft_strcpy_test();
//	ft_write_test();
//	ft_read_test();
//	ft_strdup_test();
	return (0);
}
