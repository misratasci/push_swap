/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:35 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 13:57:15 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrr(stack *a, stack *b)
{
	int	tmp;

	if (!a->arr || a->index || b->arr || b->index)
		return ;
	tmp = a->arr[a->size - 1];
	copy_arr_until(a->arr + 1, a->arr, a->size - 1);
	a->arr[0] = tmp;
	tmp = b->arr[b->size - 1];
	copy_arr_until(b->arr + 1, b->arr, b->size - 1);
	b->arr[0] = tmp;
	tmp = a->index[a->size - 1];
	copy_arr_until(a->index + 1, a->index, a->size - 1);
	a->index[0] = tmp;
	tmp = b->index[b->size - 1];
	copy_arr_until(b->index + 1, b->index, b->size - 1);
	b->index[0] = tmp;
	write(1, "rrr\n", 4);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	distance(int val1, int val2, int *a, int size)
{
	int diff;
	int	ind1;
	int	ind2;
	
	ind1 = find_ind(a, size, val1);
	ind2 = find_ind(a, size, val2);
	diff = abs(ind1 - ind2);	
	if (diff <= size / 2)
	{
		return (diff);
	}
	else
		return (diff - size);
}

int	ind_distance(int ind1, int ind2, int size)
{
	int diff;

	diff = abs(ind1 - ind2);	
	if (diff <= size / 2)
	{
		return (diff);
	}
	else
		return (diff - size);
}