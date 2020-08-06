/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:23:16 by matrus            #+#    #+#             */
/*   Updated: 2020/08/06 23:02:48 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include "libasm_tests.h"

static int	my_cmp(void *data1, void *data2)
{
	return (*((int*)(data1)) - *((int*)(data2)));
}

static void	print_list_int(t_list *list)
{
	while (list)
	{
		printf("%i ", *((int*)(list->data)));
		list = list->next;
	}
}

static void	list_free(t_list *list)
{
	t_list* next;

	if (!list)
		return ;
	while (1)
	{
		next = list->next;
		free(list);
		list = next;
		if (!list)
			return ;
	}
}

int			main(void)
{	
	ft_list_remove_if_test();
	ft_list_sort_test();
	ft_list_size_test();
	ft_list_push_front_test();
	ft_create_elem_test();
	ft_atoi_base_test();
}

void		ft_atoi_base_test()
{
	printf("\n\n\t\tATOI BASE TEST\n\n");
	printf("str: %16s, base: %2i, int: %i\n", "", 10,  ft_atoi_base("", 10));
	printf("str: %16s, base: %2i, int: %i\n", "4", 10,  ft_atoi_base("4", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-4", 10,  ft_atoi_base("-4", 10));
	printf("str: %16s, base: %2i, int: %i\n", "+4", 10,  ft_atoi_base("+4", 10));
	printf("str: %16s, base: %2i, int: %i\n", "0", 10,  ft_atoi_base("0", 10));
	printf("str: %16s, base: %2i, int: %i\n", "8oo", 10,  ft_atoi_base("8oo", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-73two", 10,  ft_atoi_base("-73two", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-333-", 10,  ft_atoi_base("-333-", 10));
	printf("str: %16s, base: %2i, int: %i\n", "+333-", 10,  ft_atoi_base("+333-", 10));
	printf("str: %16s, base: %2i, int: %i\n", "--8", 10,  ft_atoi_base("--8", 10));
	printf("str: %16s, base: %2i, int: %i\n", "++8", 10,  ft_atoi_base("++8", 10));
	printf("str: %16s, base: %2i, int: %i\n", "-2147483648", 10,  ft_atoi_base("-2147483648", 10));
	printf("str: %16s, base: %2i, int: %i\n", "2147483647", 10,  ft_atoi_base("2147483647", 10));
	printf("str: %16s, base: %2i, int: %i\n", "ff", 16,  ft_atoi_base("ff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "1f", 16,  ft_atoi_base("1f", 16));
	printf("str: %16s, base: %2i, int: %i\n", "-f", 16,  ft_atoi_base("-f", 16));
	printf("str: %16s, base: %2i, int: %i\n", "-00ff", 16,  ft_atoi_base("-00ff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "+00ff", 16,  ft_atoi_base("+00ff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "  +00ff", 16,  ft_atoi_base("  +00ff", 16));
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
	printf("str: %16s, base: %2i, int: %i\n", "80000000", 16,  ft_atoi_base("80000000", 16));
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

	printf("\nEXTRA\n");
	printf("str: %16s, base: %2i, int: %i\n", "ffffffff", 16,  ft_atoi_base("ffffffff", 16));
	printf("str: %16s, base: %2i, int: %i\n", "2147483648", 10,  ft_atoi_base("2147483648", 10));

}

void		ft_create_elem_test()
{
	t_list *elem;
	int i = 100500;

	printf("\n\n\t\tCREATE ELEM TEST\n\n");
	elem = NULL;
	elem = ft_create_elem(&i);
	printf("elem data: %i\n", *((int*)(elem->data)));
	free(elem);

	elem = NULL;
	const char c[20] = "Hello, world!\0";
	elem = ft_create_elem((void*)c);
	printf("elem data: %s\n", ((char*)(elem->data)));
	free(elem);
}


void		ft_list_push_front_test()
{
	t_list *list;
	const char c1[20] = "Hello, world1!\0";
	const char c2[20] = "Hello, world2!\0";
	const char c3[20] = "Hello, world3!\0";
	int i = 777;
	
	printf("\n\n\t\tLIST_PUSH_FRONT TEST\n\n");
	list = NULL;
	ft_list_push_front(&list, (void*)c2);
	ft_list_push_front(&list, (void*)c3);
	ft_list_push_front(&list, (void*)c1);
	printf("1 elem: %s\n", ((char*)(list->data)));
	printf("2 elem: %s\n", ((char*)(list->next->data)));
	printf("3 elem: %s\n", ((char*)(list->next->next->data)));
	list_free(list);

	list = NULL;
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	ft_list_push_front(&list, &i);
	print_list_int(list);
	list_free(list);
}

void		ft_list_size_test()
{
	t_list *list;
	const char c1[20] = "Hello, world1!\0";
	const char c2[20] = "Hello, world2!\0";
	const char c3[20] = "Hello, world3!\0";

	printf("\n\n\t\tLIST SIZE TEST\n\n");
	list = NULL;
	printf("size: %i\n", ft_list_size(list));

	ft_list_push_front(&list, (void*)c3);
	printf("size: %i\n", ft_list_size(list));
	
	ft_list_push_front(&list, (void*)c2);
	printf("size: %i\n", ft_list_size(list));

	ft_list_push_front(&list, (void*)c1);
	printf("size: %i\n", ft_list_size(list));
	free(list->next->next);

	list->next->next = NULL;
	printf("size: %i\n", ft_list_size(list));
	free(list->next);

	list->next = NULL;
	printf("size: %i\n", ft_list_size(list));
	free(list);

	list = NULL;
	printf("size: %i\n", ft_list_size(list));
}

void		ft_list_sort_test()
{
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	t_list *list;

	printf("\n\n\t\tLIST SORT TEST\n\n");
	list = NULL;
	ft_list_push_front(&list, &i1);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i3);
	ft_list_push_front(&list, &i4);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore sort:\n");
	print_list_int(list);
	ft_list_sort(&list, my_cmp);
	printf("\nAfter sort:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i4);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i1);
	ft_list_push_front(&list, &i4);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore sort:\n");
	print_list_int(list);
	ft_list_sort(&list, my_cmp);
	printf("\nAfter sort:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i1);
	printf("\n\nBefore sort:\n");
	print_list_int(list);
	ft_list_sort(&list, my_cmp);
	printf("\nAfter sort:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	printf("\n\nBefore sort:\n");
	print_list_int(list);
	ft_list_sort(&list, my_cmp);
	printf("\nAfter sort:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i4);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore sort:\n");
	print_list_int(list);
	ft_list_sort(&list, my_cmp);
	printf("\nAfter sort:\n");
	print_list_int(list);
	list_free(list);
}

void		ft_list_remove_if_test()
{
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	int i6 = 6;
	t_list *list;

	printf("\n\n\t\tLIST REMOVE IF TEST\n\n");
	list = NULL;
	ft_list_push_front(&list, &i1);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i3);
	ft_list_push_front(&list, &i4);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore remove %i:\n", i3);
	print_list_int(list);
	ft_list_remove_if(&list, &i3, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);

	list = NULL;
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore remove %i:\n", i5);
	print_list_int(list);
	ft_list_remove_if(&list, &i5, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);

	list = NULL;
	printf("\n\nBefore remove %i:\n", i2);
	print_list_int(list);
	ft_list_remove_if(&list, &i2, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i5);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore remove %i:\n", i2);
	print_list_int(list);
	ft_list_remove_if(&list, &i2, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i5);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore remove %i:\n", i5);
	print_list_int(list);
	ft_list_remove_if(&list, &i5, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);
	
	list = NULL;
	ft_list_push_front(&list, &i5);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i5);
	printf("\n\nBefore remove %i:\n", i6);
	print_list_int(list);
	ft_list_remove_if(&list, &i6, my_cmp);
	printf("\nAfter remove:\n");
	print_list_int(list);
	list_free(list);
}
