/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_old2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:22:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 10:23:08 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(stack a)
{
	int	i;

	i = -1;
	while (++i < a.size - 1)
	{
		if (a.arr[i] > a.arr[i + 1])
			return (0);
	}
	return (1);
}

int	find_place(int val, stack *b)
{
	int	i;
	int	max;
	int	min;

	max = find_max(b->arr, b->size);
	if (max < val)
		return (find_ind(b->arr, b->size, max));
	min = find_min(b->arr, b->size);
	if (min > val)
		return ((find_ind(b->arr, b->size, min) + 1) % b->size);
	if (val > b->arr[0] && val < b->arr[b->size - 1])
		return (0);
	i = -1;
	while (++i < b->size)
	{	
		if (val < b->arr[i] && val > b->arr[(i + 1) % b->size])
			return ((i + 1) % b->size);
	}
	return (-1);
}

int	get_push_ind(stack *a, stack *b)
{
	int	i;
	int	i1;
	int	i2;
	
	i = -1;
	i1 = -1;
	i2 = -1;
	while (++i < min(a->size, b->size))
	{
		if (i == find_place(a->arr[i], b)) {
		//printf("place: %d\n", find_place(a->arr[i], b));
			i1 = i;
			break;
		}
	}
	i = min(a->size, b->size) + 1;
	while (--i > 0)
	{
		if (i == find_place(a->arr[i], b))
			i2 = i;
	}
	if (i1 <= a->size - i2)
		return (i1);
	else
		return (i2);
}

void	rotate_push(stack *a, stack *b, int push_ind)
{
	int	i;
	
	i = 0;
	if (push_ind <= max(a->size, b->size) - push_ind)
	{
		while (i++ < push_ind)
			rr(a, b);
	}
	else
	{
		while (a->size > b->size && i < a->size - b->size)
		{
			revr(a);
			i++;
		}
		while (a->size < b->size && i < b->size - a->size)
		{
			revr(b);
			i++;
		}
		i = 0;
		while (i++ < min(a->size, b->size) - push_ind)
			revrr(a, b);
	}
	p(a, b);
}
/*
void	sort(stack *a, stack *b)
{
	int	push_ind;

	p(a, b);
	p(a, b);
	if (b->arr[0] < b->arr[1])
		s(b);
	while (a->size > 0)
	{
		//if (is_sorted(*a))
		//	break;
		//print_arr(a->arr, a->size);
		//print_arr(b->arr, b->size);
		push_ind = get_push_ind(a, b);
		//printf("push ind: %d\n", push_ind);
		if (push_ind != -1)
			rotate_push(a, b, push_ind);
		else if (a->size > b->size)
			r(a);
		else
			r(b);
	}
	rotate_to_top(b, find_max(b->arr, b->size));
}
*/