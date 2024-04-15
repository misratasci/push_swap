/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 23:47:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_digit(int a, int digit)
{
	int	i;
	int	res;

	if (digit < 1)
		return (-1);
	if (digit > count_digits(a))
		return (0);
	i = 0;
	while (i < digit)
	{
		res = a % 10;
		a /= 10;
		i++;
	}
	return (res);
}

void	push_to_b(t_stack *a, t_stack *b, int digit)
{
	int	i;
	int	dig;
	int	size;

	dig = 0;
	i = 0;
	while (dig <= 9)
	{
		size = a->size;
		while (i < size)
		{
			if (a->size == 0)
				return ;
			if (dig == get_digit(a->index[0], digit))
				p(a, b);
			else
				r(a);
			i++;
		}
		i = 0;
		dig++;
	}
}

void	push_to_a(t_stack *a, t_stack *b, int digit)
{
	int	i;
	int	dig;
	int	size;

	dig = get_max_of_dig(b, digit);
	i = 0;
	while (dig >= 0)
	{
		size = b->size;
		while (i < size)
		{
			if (b->size == 0)
				return ;
			if (dig == get_digit(b->index[0], digit))
				p(b, a);
			else
				r(b);
			i++;
		}
		i = 0;
		dig--;
		size = b->size;
	}
}

void	push_all_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		p(b, a);
}

void	sort(t_stack *a, t_stack *b)
{
	int	digits;

	digits = count_digits(find_max(a->index, a->size));
	push_to_b(a, b, 1);
	if (digits > 1)
		push_to_a(a, b, 2);
	if (digits > 2)
		push_to_b(a, b, 3);
	push_all_to_a(a, b);
}
