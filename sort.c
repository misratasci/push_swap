/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:22:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/19 17:23:54 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//printf("place: %d\n", find_place(a->arr[i], b));
		if (i == find_place(a->arr[i], b))
			i1 = i;
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
	
	i = -1;
	while (++i < push_ind)
		rr(a, b);
	p(a, b);
}

int	r_cost(stack *a, stack *b)
{
	int	push_ind;
	int	n;
	int	i;
	
	push_ind = 0;
	n = 0;
	while (push_ind != -1)
	{
		r_sim(a);
		push_ind = get_push_ind(a, b);
		n++;
	}
	printf("sim-push-ind: %d\n", push_ind);
	i = -1;
	while (++i < n)
		revr_sim(a);
	return (push_ind + n + 1);
}

int	revr_cost(stack *a, stack *b)
{
	int	push_ind;
	int	n;
	int	i;
	
	push_ind = 0;
	n = 0;
	while (push_ind != -1)
	{
		revr_sim(a);
		push_ind = get_push_ind(a, b);
		n++;
	}
	printf("sim-push-ind: %d\n", push_ind);
	i = -1;
	while (++i < n)
		r_sim(a);
	return (push_ind + n + 1);
}

void	sort(stack *a, stack *b)
{
	int	push_ind;
	int	r_c;
	int	revr_c;
	
	p(a, b);
	p(a, b);
	if (b->top < b->arr[1])
		s(b);
	while (a->size > 0)
	{
		print_arr(a->arr, a->size);
		print_arr(b->arr, b->size);
		push_ind = get_push_ind(a, b);
		printf("push ind: %d\n", push_ind);
		if (push_ind != -1)
			rotate_push(a, b, push_ind);
		else if (a->size > b->size)
		{
			r_c = r_cost(a, b);
			revr_c = revr_cost(a, b);
			if (r_c <= revr_c)
				r(a);
			else
				revr(a);
		}
		else
			r(b);
	}
	rotate_to_top(b, find_max(b->arr, b->size));
}
