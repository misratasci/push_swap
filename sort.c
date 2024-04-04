/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 04:37:43 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_bit_calculation(t_stack *a)
{
	int	max_value;
	int	i;

	i = 0;
	max_value = 0;
	while (i < a->size)
	{
		if (abs(a->arr[i]) > max_value)
			max_value = abs(a->arr[i]);
		i++;
	}
	a->max_bit = 0;
	while (max_value >> a->max_bit)
		a->max_bit++;
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	num;

	max_bit_calculation(a);
	i = 0;
	while (i < a->max_bit)
	{
		j = a->size;
		while (j--)
		{
			num = a->arr[0];
			if (((num >> i) & 1) == 1)
				r(a);
			else
				p(a, b);
		}
		while (b->size)
			p(b, a);
		i++;
	}
}

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
	exit (0);
}
