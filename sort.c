/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:43:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/03 13:31:01 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_digits(int a)
{
	int res;
	
	res = 0;
	while (a != 0)
	{
		a /= 10;
		res++;
	}
	return (res);
}

int get_digit(int a, int digit)
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

void	push_to_b(stack *a, stack *b, int digit)
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
			//printf("a: %d - i: %d\n", get_digit(a->index[0], digit), i);
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

void	push_to_a(stack *a, stack *b, int digit)
{
	int	i;
	int	dig;
	int	size;
	
	dig = 9;
	i = 0;
	while (dig >= 0)
	{
		size = b->size;
		while (i < size)
		{
			//print_stacks(*a, *b);
			//printf("a: %d, i: %d, dig: %d\n", get_digit(b->index[0], digit), i, dig);
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

void	sort(stack *a, stack *b)
{
	push_to_b(a, b, 1);
	print_stacks(*a, *b);
	push_to_a(a, b, 2);
	print_stacks(*a, *b);
	push_to_b(a, b, 3);
	print_stacks(*a, *b);
}