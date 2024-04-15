/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:35 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 23:03:50 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revr(t_stack *a)
{
	int	tmp;

	if (!a->arr || !a->index)
		return ;
	tmp = a->arr[a->size - 1];
	copy_arr_until(a->arr + 1, a->arr, a->size - 1);
	a->arr[0] = tmp;
	tmp = a->index[a->size - 1];
	copy_arr_until(a->index + 1, a->index, a->size - 1);
	a->index[0] = tmp;
	write(1, "rr", 2);
	write(1, &a->name, 1);
	write(1, "\n", 1);
}

void	revrr(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!a->arr || !a->index || !b->arr || !b->index)
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

void	r_n(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		r(a);
		i++;
	}
}

void	revr_n(t_stack *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		revr(a);
		i++;
	}
}