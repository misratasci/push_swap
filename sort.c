/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:37 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 10:28:07 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stacks(stack *a, stack *b)
{
	int	piv_a;
	int	piv_b;

	piv_a = find_max(a->index, a->size);
	piv_b = piv_a / 2;
	printf("Pivot A: %d, Pivot B: %d\n", piv_a, piv_b);
	while (find_ind(a->index, a->size, piv_b) > a->size / 2)
	{
		p(a, b);
		revr(a);
	}
	while (b->size < a->size)
		p(a, b);
}

void sort(stack *a, stack *b)
{
	split_stacks(a, b);
}
