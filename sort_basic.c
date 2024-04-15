/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:24:09 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 17:43:30 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_inc(t_stack *a)
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

static int	find_place(int val, t_stack *b)
{
	int	i;
	int	max;
	int	min;

	max = find_max(b->arr, b->size);
	if (max < val)
		return ((find_ind(b->arr, b->size, max) + 1) % b->size);
	min = find_min(b->arr, b->size);
	if (min > val)
		return ((find_ind(b->arr, b->size, min)));
	i = -1;
	while (++i < b->size - 1)
	{
		if (b->arr[i] < val && val < b->arr[(i + 1)])
			return ((i + 1));
	}
	return (-1);
}

static void	push_to_place(int place, t_stack *a, t_stack *b)
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

static void	rotate_to_min(t_stack *a)
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

void	sort_5_inc(t_stack *a, t_stack *b)
{
	int	push_place;

	p(a, b);
	p(a, b);
	sort_3_inc(a);
	push_place = find_place(b->arr[0], a);
	push_to_place(push_place, a, b);
	push_place = find_place(b->arr[0], a);
	push_to_place(push_place, a, b);
	rotate_to_min(a);
}
