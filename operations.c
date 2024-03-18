/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:45:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:19:58 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(stack *a)
{
	int	tmp;

	if (a->size < 2)
	{
		ft_putendl_fd("Less than 2 elements in stack, cannot swap", 1);
		return ;
	}
	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
	a->top = a->arr[0];
}

void	ss(stack *a, stack *b)
{
	s(a);
	s(b);
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
}

void	rr(stack *a, stack *b)
{
	r(a);
	r(b);
}

void	r(stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	copy_arr_until(a->arr, a->arr + 1, a->size - 1);
	a->arr[a->size - 1] = tmp;
	a->top = a->arr[0];
}

void	revr(stack *a)
{
	int	tmp;

	tmp = a->arr[a->size - 1];
	copy_arr_until(a->arr + 1, a->arr, a->size - 1);
	a->arr[0] = tmp;
	a->top = a->arr[a->size - 1];
}
