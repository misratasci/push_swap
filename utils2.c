/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:50 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/03 20:24:07 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_ind(int *a, int size, int value)
{
	int	i;

	if (!a || size < 1)
		return (-1);
	i = -1;
	while (++i < size)
	{
		if (a[i] == value)
			return (i);
	}
	return (-1);
}

int	find_next_min(int *a, int size, int prev_min)
{
	int	i;
	int	res;

	if (!a || size < 2)
		return (-1);
	i = 0;
	while (a[i] <= prev_min)
		i++;
	if (i >= size)
		return (-1);
	res = a[i];
	while (i < size)
	{
		if (a[i] < res && a[i] > prev_min)
			res = a[i];
		i++;
	}
	return (res);
}

void	sort_3_inc(stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
		return ;
	else if (a->arr[0] < a->arr[2] && a->arr[2] < a->arr[1])
	{
		s(a);
		r(a);
	}
	else if (a->arr[1] < a->arr[0] && a->arr[0] < a->arr[2])
		s(a);
	else if (a->arr[2] < a->arr[0] && a->arr[0] < a->arr[1])
		revr(a);
	else if (a->arr[1] < a->arr[2] && a->arr[2] < a->arr[0])
		r(a);
	else
	{
		s(a);
		revr(a);
	}
}

void	sort_4_inc(stack *a, stack *b)
{
	p(a, b);
	sort_3_inc(a);
	if (b->arr[0] < a->arr[0])
		p(b, a);
	else if (a->arr[0] < b->arr[0] && b->arr[0] < a->arr[1])
	{
		r(a);
		p(b, a);
		revr(a);
	}
	else if (a->arr[1] < b->arr[0] && b->arr[0] < a->arr[2])
	{
		revr(a);
		p(b, a);
		r(a);
	}
	else if (*b->arr > a->arr[2])
	{
		p(b, a);
		r(a);
	}
}