/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:37 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 11:32:15 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stacks(stack *a, stack *b)
{
	int	i;
	
	printf("Pivot A: %d, Pivot B: %d\n", a->pivot, b->pivot);
	i = 0;
	while (b->size < a->size)
	{
		if (a->index[i] == a->pivot)
			r(a);
		p(a, b);
		if (find_ind(a->index, a->size, b->pivot) > a->size / 2)
			revr(a);
		i++;
	}

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

int	calc_label(stack *a, stack *b, int val)
{
	int	right_stack;
	//int	right_place;

	right_stack = (val > b->pivot && in_stack(*a, val)) || (val < b->pivot && in_stack(*b, val));
	//right_place = (piv_a - val) == distance(piv_a, val, a->index, a->size)
	return (right_stack);
}
/*
void	calc_lbl_arr(stack *a, stack *b, int *arr)
{
	
}
*/
void sort(stack *a, stack *b)
{
	split_stacks(a, b);
	init_lbl_arr(a, b);
	printf("in stack: %d, in right stack: %d\n", in_stack(*a, 8), calc_label(a, b, 8));
}
