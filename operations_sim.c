/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:45:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/02 00:52:53 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_sim(stack *a)
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
}

void	ss_sim(stack *a, stack *b)
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
	}
}

static void	p_for_ind(stack *a, stack *b)
{
	int *tmp;
	
	tmp = (int *)malloc(sizeof(int) * (b->size));
	tmp[0] = a->index[0];
	if (b->size - 1 > 0 && b->index)
	{
		copy_arr_until(tmp + 1, b->index, b->size - 1);
		free(b->index);
	}
	b->index = (int *)malloc(sizeof(int) * (b->size));
	copy_arr_until(b->index, tmp, b->size);
	if (tmp)
		free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(tmp, a->index + 1, a->size);
	if (a->index)
		free(a->index);
	a->index = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(a->index, tmp, a->size);
	if (tmp)
		free(tmp);
}

void	p_sim(stack *a, stack *b)
{
	int *tmp;
	
	if (a->size == 0)
		return ;
	tmp = (int *)malloc(sizeof(int) * (b->size + 1));
	tmp[0] = a->arr[0];
	if (b->size > 0 && b->arr)
	{
		copy_arr_until(tmp + 1, b->arr, b->size);
		free(b->arr);
	}
	b->arr = (int *)malloc(sizeof(int) * (b->size + 1));
	copy_arr_until(b->arr, tmp, b->size + 1);
	b->size++;
	if (tmp)
		free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(tmp, a->arr + 1, a->size - 1);
	if (a->arr)
		free(a->arr);
	a->arr = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(a->arr, tmp, a->size - 1);
	a->size--;
	if (tmp)
		free(tmp);
	p_for_ind(a, b);
}

void	rr_sim(stack *a, stack *b)
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
}

void	r_sim(stack *a)
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
}

void	revr_sim(stack *a)
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
}