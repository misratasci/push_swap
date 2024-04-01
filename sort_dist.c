/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:41:38 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/01 17:43:05 by mitasci          ###   ########.fr       */
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
