/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:50 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 17:17:18 by mitasci          ###   ########.fr       */
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

static int	find_place(int val, stack *b)
{
	int	i;
	int	max;
	int	min;

	max = find_max(b->arr, b->size);
	//printf("max: %d\n", max);
	if (max < val)
		return ((find_ind(b->arr, b->size, max) + 1) % b->size);
	min = find_min(b->arr, b->size);
	//printf("min: %d\n", min);
	if (min > val)
		return ((find_ind(b->arr, b->size, min)));
	i = -1;
	while (++i < b->size - 1)
	{	
		//printf("in while loop - val: %d, b->arr[%d]: %d\n", val, i, b->arr[i]);
		if (b->arr[i] < val && val < b->arr[(i + 1)])
			return ((i + 1));
	}
	return (-1);
}

static void	push_to_place(int place, stack *a, stack *b)
{
	int	i;
	
	i = 0;
	if (place <= a->size / 2)
	{
		while (i++ < place)
			r(a);
	}
	else
	{
		while (i++ < a->size - place)
			revr(a);
	}
	p(b, a);
}

static void	rotate_to_min(stack *a)
{
	int	min;
	int	ind;
	int	i;

	min = find_min(a->arr, a->size);
	ind = find_ind(a->arr, a->size, min);
	i = 0;
	if (ind <= a->size / 2)
	{
		while (i++ < ind)
			r(a);
	}
	else
	{
		while (i++ < a->size - ind)
			revr(a);
	}
}

void	sort_5_inc(stack *a, stack *b)
{
	int	push_place;

	p(a, b);
	p(a, b);
	//print_stacks(*a, *b);
	sort_3_inc(a);
	//print_stacks(*a, *b);
	push_place = find_place(b->arr[0], a);
	//printf("place: %d\n", push_place);
	push_to_place(push_place, a, b);
	//print_stacks(*a, *b);
	push_place = find_place(b->arr[0], a);
	//printf("place: %d\n", push_place);
	push_to_place(push_place, a, b);
	//print_stacks(*a, *b);
	rotate_to_min(a);
}