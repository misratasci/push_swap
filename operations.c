/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:45:47 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/01 18:19:23 by mitasci          ###   ########.fr       */
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

static void	p_for_ind(stack *a, stack *b)
{
	int *tmp;
	
	tmp = (int *)malloc(sizeof(int) * (b->size));
	tmp[0] = a->index[0];
	if (b->size - 1 > 0)
	{
		copy_arr_until(tmp + 1, b->index, b->size - 1);
		free(b->index);
	}
	b->index = (int *)malloc(sizeof(int) * (b->size));
	copy_arr_until(b->index, tmp, b->size);
	free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(tmp, a->index + 1, a->size);
	free(a->index);
	a->index = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(a->index, tmp, a->size);
	free(tmp);
}

static void	p_for_dist(stack *a, stack *b)
{
	int *tmp;
	
	tmp = (int *)malloc(sizeof(int) * (b->size));
	tmp[0] = a->dists[0];
	if (b->size - 1 > 0)
	{
		copy_arr_until(tmp + 1, b->dists, b->size - 1);
		free(b->dists);
	}
	b->dists = (int *)malloc(sizeof(int) * (b->size));
	copy_arr_until(b->dists, tmp, b->size);
	free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(tmp, a->dists + 1, a->size);
	free(a->dists);
	a->dists = (int *)malloc(sizeof(int) * (a->size));
	copy_arr_until(a->dists, tmp, a->size);
	free(tmp);
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
	free(tmp);
	tmp = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(tmp, a->arr + 1, a->size - 1);
	free(a->arr);
	a->arr = (int *)malloc(sizeof(int) * (a->size - 1));
	copy_arr_until(a->arr, tmp, a->size - 1);
	a->size--;
	free(tmp);
	p_for_ind(a, b);
	p_for_dist(a, b);
	write(1, "p", 1);
	write(1, &b->name, 1);
	write(1, "\n", 1);
}

void	rr(stack *a, stack *b)
{
	int	tmp;

	if (!a->arr || a->index || b->arr || b->index)
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