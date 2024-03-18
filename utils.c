/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:20:34 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	listlen(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	free_list(char **l)
{
	int	i;

	i = 0;
	while(l[i])
		free(l[i++]);
	free(l);
}

stack	initialize_stack_a(char **argv)
{
	stack	a;
	int		i;
	char	**list;
	
	a.name = 'a';
	list = ft_split(argv[1], ' ');
	a.size = listlen(list);
	a.arr = (int*)malloc(sizeof(int) * a.size);
	i = -1;
	while (++i < a.size)
		a.arr[i] = ft_atoi(list[i]);
	a.top = a.arr[0];
	free_list(list);
	return (a);
}

stack	initialize_stack_b()
{
	stack	b;
	
	b.name = 'b';
	b.size = 0;
	b.arr = NULL;
	b.top = 0;
	return (b);
}

void	clean_stack(stack a)
{
	if (a.arr)
		free(a.arr);
}

void	copy_arr_until(int *dst, int *src, int n)
{
	int		i;

	if (!dst && !src)
		return ;
	if (dst <= src)
	{
		i = -1;
		while (++i < n)
			dst[i] = src[i];
	}
	if (dst > src)
	{
		i = n;
		while (i-- > 0)
			dst[i] = src[i];
	}
}

void	print_arr(int *a, int size) //bunu sonradan sil
{
	int i = -1;
	printf("{");
	while (++i < size)
		printf("%d, ", a[i]);
	printf("}\n");
}