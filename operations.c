/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:45:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/19 17:00:38 by mitasci          ###   ########.fr       */
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
	a->top = a->arr[0];
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
		a->top = a->arr[0];
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
		b->top = b->arr[0];
		write(1, "ss\n", 3);
	}
}

void	p(stack *a, stack *b)
{
	int *tmp;
	
	if (a->size == 0)
		return ;
	tmp = (int *)malloc(sizeof(int) * (b->size + 1));
	tmp[0] = a->arr[0];
	if (b->size > 0)
	{
		copy_arr_until(tmp + 1, b->arr, b->size);
		free(b->arr);
	}
	b->arr = (int *)malloc(sizeof(int) * (b->size + 1));
	copy_arr_until(b->arr, tmp, b->size + 1);
	b->size++;
	b->top = b->arr[0];
	free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(tmp, a->arr + 1, a->size - 1);
	free(a->arr);
	a->arr = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(a->arr, tmp, a->size - 1);
	a->size--;
	a->top = a->arr[0];
	free(tmp);
	write(1, "p", 1);
	write(1, &b->name, 1);
	write(1, "\n", 1);
}

void	rr(stack *a, stack *b)
{
	int	tmp;

	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	a->top = a->arr[0];
	tmp = b->arr[0];
	copy_arr_until(b->arr, b->arr + 1, b->size - 1);
	b->arr[b->size - 1] = tmp;
	b->top = b->arr[0];
	write(1, "rr\n", 3);
}

void	r(stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	a->top = a->arr[0];
	write(1, "r", 1);
	write(1, &a->name, 1);
	write(1, "\n", 1);
}

void	r_sim(stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	a->top = a->arr[0];
}

void	revr_sim(stack *a)
{
	int	tmp;

	tmp = a->arr[a->size - 1];
	copy_arr_until(a->arr + 1, a->arr, a->size - 1);
	a->arr[0] = tmp;
	a->top = a->arr[a->size - 1];
}

void	revr(stack *a)
{
	int	tmp;

	tmp = a->arr[a->size - 1];
	copy_arr_until(a->arr + 1, a->arr, a->size - 1);
	a->arr[0] = tmp;
	a->top = a->arr[a->size - 1];
	write(1, "rr", 2);
	write(1, &a->name, 1);
	write(1, "\n", 1);
}
