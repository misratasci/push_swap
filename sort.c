/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:37 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 11:47:40 by mitasci          ###   ########.fr       */
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

/*
0: right stack, wrong place
1: right stack, right place
2: wrong stack, wrong place
3: wrong stack, right place 
*/
int	calc_label(stack *a, stack *b, int val)
{
	int	right_stack;
	int	right_place;

	right_stack = (val > b->pivot && in_stack(*a, val)) || (val < b->pivot && in_stack(*b, val));
	if (right_stack && in_stack(*a, val))
		right_place = (a->pivot - val) == distance(a->pivot, val, a->index, a->size);
	else if (right_stack && in_stack(*b, val))
		right_place = (b->pivot - val) == distance(b->pivot, val, b->index, b->size);
	
	return (right_place);
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
	calc_label(a, 18);
}
