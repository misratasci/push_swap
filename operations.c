/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:45:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/03 13:20:29 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(stack *a)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	tmp = a->index[0];
	a->index[0] = a->index[1];
	a->index[1] = tmp;
	write(1, "s", 1);
	write(1, &a->name, 1);
	write(1, "\n", 1);
}

void	ss(stack *a, stack *b)
{
	int	tmp;
	
	if (a->size >= 2 && b->size >= 2)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
		tmp = a->index[0];
		a->index[0] = a->index[1];
		a->index[1] = tmp;
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
		tmp = b->index[0];
		b->index[0] = b->index[1];
		b->index[1] = tmp;
		write(1, "ss\n", 3);
	}
}

void	p(stack *a, stack *b)
{
	if (b->size + 1 > b->capacity)
		return ;
	if (b->arr && b->index && b->size > 0)
	{
		copy_arr_until(b->arr + 1, b->arr, b->size);
		copy_arr_until(b->index + 1, b->index, b->size);
	}
	b->arr[0] = a->arr[0];
	b->index[0] = a->index[0];
	b->size++;
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	copy_arr_until(a->index, a->index + 1, a->size - 1);
	a->size--;
	write(1, "p", 1);
	write(1, &b->name, 1);
	write(1, "\n", 1);
}

void	rr(stack *a, stack *b)
{
	int	tmp;

	if (!a->arr || !a->index || !b->arr || !b->index)
		return ;
	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	tmp = b->arr[0];
	copy_arr_until(b->arr, b->arr + 1, b->size - 1);
	b->arr[b->size - 1] = tmp;
	tmp = a->index[0];
	copy_arr_until(a->index, a->index + 1, a->size - 1);
	a->index[a->size - 1] = tmp;
	tmp = b->index[0];
	copy_arr_until(b->index, b->index + 1, b->size - 1);
	b->index[b->size - 1] = tmp;
	write(1, "rr\n", 3);
}

void	r(stack *a)
{
	int	tmp;

	if (!a->arr || !a->index)
		return ;
	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	tmp = a->index[0];
	copy_arr_until(a->index, a->index + 1, a->size - 1);
	a->index[a->size - 1] = tmp;
	write(1, "r", 1);
	write(1, &a->name, 1);
	write(1, "\n", 1);
}

void	revr(stack *a)
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

void	revrr(stack *a, stack *b)
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