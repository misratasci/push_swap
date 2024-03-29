/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:37 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/29 12:51:37 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_from_front(stack *a, stack *b)
{
	while (b->size < a->size)
	{
		if (a->index[0] == a->pivot)
				r(a);
		else
			p(a, b);
	}
}

static void	split_from_back(stack *a, stack *b)
{
	while (b->size < a->size)
	{
		revr(a);
		if (a->index[0] == a->pivot)
			revr(a);
		p(a, b);
	}
}

void	split_stacks(stack *a, stack *b)
{
	printf("Pivot A: %d, Pivot B: %d\n", a->pivot, b->pivot);
	if (find_ind(a->index, a->size, b->pivot) <= a->size / 2)
		split_from_front(a, b);
	else
		split_from_back(a, b);
}

int	*init_lbl_arr(stack *a, stack *b)
{
	int	*lbl_arr;
	int	i;

	lbl_arr = (int *)malloc(sizeof(int) * (a->size + b->size));
	i = -1;
	while (++i < a->size + b->size)
		lbl_arr[i] = 0;
	return (lbl_arr);
}

int	in_stack(stack a, int val)
{
	return (find_ind(a.index, a.size, val) != -1);
}

int	right_stack(stack a, stack b, int val)
{
	return ((in_stack(a, val) && val > b.pivot) || (in_stack(b, val) && val < b.pivot));
}

static int	right_place_in_a(stack a, int val)
{
	int	piv_ind;
	int	val_ind;
	int	dist;

	piv_ind = find_ind(a.index, a.size, a.pivot);
	val_ind = find_ind(a.index, a.size, val);
	dist = piv_ind - val_ind;
	if (val_ind > piv_ind)
		dist = piv_ind - val_ind + a.size;
	return (dist == a.pivot - val);
}

static int	right_place_in_b(stack b, int val)
{
	int	piv_ind;
	int	val_ind;
	int	dist;

	piv_ind = find_ind(b.index, b.size, b.pivot);
	val_ind = find_ind(b.index, b.size, val);
	dist = (-1) * (piv_ind - val_ind);
	if (piv_ind > val_ind)
		dist = piv_ind - val_ind + b.size;
	return (dist == b.pivot - val);
}

int	right_place(stack a, stack b, int val)
{
	if (in_stack(a, val) && right_stack(a, b, val))
		return (right_place_in_a(a, val));
	if (in_stack(b, val) && right_stack(a, b, val))
		return (right_place_in_b(b, val));
	return (0);
}

/*
0: wrong stack, wrong place
1: right stack, wrong place
2: right stack, right place
3: wrong stack, right place, can reach with rr (in first half of stack)
4: wrong stack, right place, can reach with rrr (in second half)
-1: is pivot a
-2: is pivot b

(3 ve 4ü sonra yaparım kafam basmadı)
*/
int	calc_label(stack a, stack b, int val)
{
	if (val == a.pivot)
		return (-1);
	if (val == b.pivot)
		return (-2);
	if (right_stack(a, b, val) && right_place(a, b, val))
		return (2);
	else if (right_stack(a, b, val) && !right_place(a, b, val))
		return (1);
	return (0);
}

void	calc_lbl_arr(stack a, stack b, int *arr)
{
	int	i;

	i = -1;
	while (++i < a.size + b.size)
		arr[i] = calc_label(a, b, i);
}

int	lbls_are_better(int *old, int *new, int size)
{
	return (arr_sum(new, size) > arr_sum(old, size));
}

void sort(stack *a, stack *b)
{
	int	*lbl_arr;
	
	split_stacks(a, b);
	lbl_arr = init_lbl_arr(a, b);
	calc_lbl_arr(*a, *b, lbl_arr);
	//printf("right place : %d\n", right_place(*a, *b, 2));
	printf("Label array: ");
	print_arr(lbl_arr, a->size + b->size);
	
}
