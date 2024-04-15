/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 21:18:01 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_with_zeroes(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		a[i] = 0;
}

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
	if (!l)
		return ;
	while (l[i])
		free(l[i++]);
	free(l);
}

void	copy_arr_until(int *dst, int *src, int n)
{
	int		i;

	if (!dst || !src)
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

int	count_digits(int a)
{
	int res;
	
	res = 0;
	while (a != 0)
	{
		a /= 10;
		res++;
	}
	return (res);
}

void	print_arr(int *a, int size) //bunu sonradan sil
{
	int i = -1;
	printf("{");
	while (++i < size)
		printf("%d, ", a[i]);
	printf("}\n");
}

void	print_stacks(t_stack a, t_stack b) //bunu da sil
{
	printf("Stack A:\n");
	print_arr(a.arr, a.size);
	//print_arr(a.index, a.size);
	printf("Stack B:\n");
	print_arr(b.arr, b.size);
	//print_arr(b.index, b.size);
}