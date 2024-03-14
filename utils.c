/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 16:18:38 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	initialize_stack_a(int argc, char **argv)
{
	stack	a;
	int		i;
	
	a.name = 'a';
	a.size = argc - 1;
	a.arr = (int*)malloc(sizeof(int) * a.size);
	i = -1;
	while (++i < a.size)
		a.arr[i] = ft_atoi(argv[i + 1]);
	a.top = a.arr[a.size - 1];
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

int	find_max(int *a, int size)
{
	int	i;
	int	max;

	if (!a || size < 1)
		return (-1);
	max = a[0];
	i = -1;
	while (++i < size)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max);
}

int	find_min(int *a, int size)
{
	int	i;
	int	min;

	if (!a || size < 1)
		return (-1);
	min = a[0];
	i = -1;
	while (++i < size)
	{
		if (a[i] < min)
			min = a[i];
	}
	return (min);
}

int	find_min_ind(int *a, int size)
{
	int	i;
	int	min;
	int	ind;

	if (!a || size < 1)
		return (-1);
	min = a[0];
	ind = 0;
	i = -1;
	while (++i < size)
	{
		if (a[i] < min)
		{
			min = a[i];
			ind = i;
		}
	}
	return (ind);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	distance(int ind1, int ind2, int size)
{
	int diff;

	diff = abs(ind1 - ind2);	
	if (diff < size / 2)
	{
		return (diff);
	}
	else
		return (diff - size);
}

int	find_middle(int *a, int size) //bunsuz da deneyebilirsin
{
	int	maxmin[2];
	int	middle;
	int	diff;
	int	i;
	int	res;

	maxmin[0] = find_max(a, size);
	maxmin[1] = find_min(a, size);
	middle = (maxmin[0] + maxmin[1]) / 2;
	i = -1;
	diff = abs(a[0] - middle);
	while (++i < size)
	{
		if (a[i] == middle)
			return (middle);
		else if (diff < abs(a[i] - middle))
		{
			diff = abs(a[i] - middle);
			res = a[i];
		}
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