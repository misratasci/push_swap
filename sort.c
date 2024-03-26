/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:22:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 22:22:24 by mitasci          ###   ########.fr       */
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
	int	ind;
	
	i = -1;
	ind = INT32_MAX;
	while (++i < min(a->size, b->size))
	{
		if (i == find_place(a->arr[i], b)) {
		//printf("place: %d\n", find_place(a->arr[i], b));
			ind = i;
			break;
		}
	}
	i = a->size;
	while (--i > abs(a->size - b->size))
	{
		if (a->size - i == b->size - find_place(a->arr[i], b))
		{
			if (ind == -1 || ind > a->size - i)
				ind = i - a->size;
		}
	}
	return (ind);
}

void	rotate_push(stack *a, stack *b, int push_ind)
{
	int	i;
	
	i = 0;
	//printf("hello\n");
	while (push_ind >= 0 && i++ < push_ind)
		rr(a, b);
	while (push_ind < 0 && i++ < -push_ind)
		revrr(a, b);
	p(a, b);
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

void	sort_3_dec(stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
	{
		s(a);
		revr(a);
	}
	else if (a->arr[0] < a->arr[2] && a->arr[2] < a->arr[1])
		r(a);
	else if (a->arr[1] < a->arr[0] && a->arr[0] < a->arr[2])
		revr(a);
	else if (a->arr[2] < a->arr[0] && a->arr[0] < a->arr[1])
		s(a);
	else if (a->arr[1] < a->arr[2] && a->arr[2] < a->arr[0])
	{
		revr(a);
		s(a);
	}
}

int	check_sa(stack *a, stack *b)
{
	int	old;
	int new;
	
	old = get_push_ind(a, b);
	s_sim(a);
	new = get_push_ind(a, b);
	//printf("sa sim old push ind: %d, new: %d\n", old, new);
	s_sim(a);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new));
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - abs(new));
}

int	check_ra(stack *a, stack *b)
{
	int	old;
	int new;
	
	old = get_push_ind(a, b);
	r_sim(a);
	new = get_push_ind(a, b);
	//printf("ra sim old push ind: %d, new: %d\n", old, new);
	revr_sim(a);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new));
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - abs(new));
}

int	check_rb(stack *a, stack *b)
{
	int	old;
	int new;
	
	old = get_push_ind(a, b);
	r_sim(b);
	new = get_push_ind(a, b);
	//printf("rb sim old push ind: %d, new: %d\n", old, new);
	revr_sim(b);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new));
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - abs(new));
}

int	check_rra(stack *a, stack *b)
{
	int	old;
	int new;
	
	old = get_push_ind(a, b);
	revr_sim(a);
	new = get_push_ind(a, b);
	//printf("ra sim old push ind: %d, new: %d\n", old, new);
	r_sim(a);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new));
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - abs(new));
}

int	check_rrb(stack *a, stack *b)
{
	int	old;
	int new;
	
	old = get_push_ind(a, b);
	revr_sim(b);
	new = get_push_ind(a, b);
	//printf("rb sim old push ind: %d, new: %d\n", old, new);
	r_sim(b);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new));
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - abs(new));
}

int	choose_move(stack *a, stack *b)
{
	int	profits[5];
	int	move;
	
	profits[0] = check_sa(a, b);
	profits[1] = check_ra(a, b);
	profits[2] = check_rb(a, b);
	profits[3] = check_rra(a, b);
	profits[4] = check_rrb(a, b);
	if (all_els_eq(profits, 5) || all_els_neg(profits, 5))
		return (-1);
	move = find_ind(profits, 5, find_max(profits, 5));
	//print_arr(profits, 5);
	if (move == 0)
		s(a);
	if (move == 1)
		r(a);
	if (move == 2)
		r(b);
	if (move == 3)
		revr(a);
	if (move == 4)
		revr(b);
	return (profits[move]);
}

void	sort(stack *a, stack *b)
{
	int	push_ind;

	p(a, b);
	p(a, b);
	p(a, b);
	sort_3_dec(b);
	while (a->size > 3)
	{
		int i = 0;
		while (i++ < 15)
			choose_move(a, b);
		//print_stacks(*a, *b);
		push_ind = get_push_ind(a, b);
		//printf("push ind: %d\n", push_ind);
		if (push_ind != INT32_MAX)
			rotate_push(a, b, push_ind);
		else if (a->size > b->size)
			r(a);
		else
			r(b);
	}
	rotate_to_top(b, find_max(b->arr, b->size));
}
