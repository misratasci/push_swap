/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:25:23 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/19 16:02:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(stack *a, int val)
{
	int	i;
	int	ind;

	ind = find_ind(a->arr, a->size, val);
	if (ind < a->size / 2)
	{
		i = -1;
		while (++i < ind )
			r(a);
	}
	else
	{
		i = -1;
		while (++i < a->size - ind)
			revr(a);
	}
	//printf("Rotated %d to top\n", val);
	//print_arr(a->arr, a->size);
}

void	r_together(stack *a, stack *b, int ind_a, int ind_b)
{
	int	i;

	i = -1;
	while (++i < min(ind_a, ind_b))
		rr(a, b);
	while (i < ind_a)
	{
		r(a);
		i++;
	}
	while (i++ < ind_b)
		r(b);
}

void revr_together(stack *a, stack *b, int ind_a, int ind_b)
{
	int	i;

	i = -1;
	while (++i < min(a->size - ind_a, b->size - ind_b))
		revrr(a, b);
	while (i < a->size - ind_a)
	{
		revr(a);
		i++;
	}
	while (i++ < b->size - ind_b)
		revr(b);
}

int	sep_rot_cost(stack *a, stack *b, int ind_a, int ind_b)
{
	return (min(ind_a, a->size - ind_a) + min(ind_b, b->size - ind_b));
}

int	tog_rot_cost(stack *a, stack *b, int ind_a, int ind_b)
{
	return (min(max(ind_b, ind_a), max(b->size - ind_b, a->size - ind_a)));
}

void rotate_to_top_together(stack *a, stack *b, int val_a, int val_b)
{
	int ind_a;
	int ind_b;

	ind_a = find_ind(a->arr, a->size, val_a);
	ind_b = find_ind(b->arr, b->size, val_b);

	if (tog_rot_cost(a, b, ind_a, ind_b) < sep_rot_cost(a, b, ind_a, ind_b))
	{
		if (ind_b < a->size - ind_a)
			r_together(a, b, ind_a, ind_b);
		else
			revr_together(a, b, ind_a, ind_b);
	}
	else
	{
		rotate_to_top(a, val_a);
		rotate_to_top(b, val_b);
	}
	printf("rotated to top together\n");
	print_arr(a->arr, a->size);
	print_arr(b->arr, b->size);
}

void	move_up(stack *a, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		revr(a);
		s(a);
		printf("Moved up\n");
		print_arr(a->arr, a->size);
	}
}

void	move_up_together(stack *a, stack *b, int dist_a, int dist_b)
{
	int	i;

	i = -1;
	while (++i < min(dist_a - 1, dist_b - 1))
	{
		revrr(a, b);
		ss(a, b);
	}
	while (i < dist_a - 1)
	{
		revr(a);
		s(a);
		i++;
	}
	while (i++ < dist_b - 1)
	{
		revr(b);
		s(b);
	}
	printf("moved up together\n");
	print_arr(a->arr, a->size);
	print_arr(b->arr, b->size);
}

void	move_down(stack *a, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		s(a);
		if (i < n - 1)
			r(a);
		printf("Moved down\n");
		print_arr(a->arr, a->size);
	}
}

void	move_down_together(stack *a, stack *b, int dist_a, int dist_b)
{
	int	i;

	i = -1;
	while (++i < min(-dist_a, -dist_b))
	{
		ss(a, b);
		rr(a, b);
	}
	while (i < -dist_a)
	{
		s(a);
		if (i < -dist_a - 1)
			r(a);
		i++;
	}
	while (i++ < -dist_b)
	{
		s(b);
		if (i < -dist_b - 1)
			r(b);
	}
	printf("moved down together\n");
	print_arr(a->arr, a->size);
	print_arr(b->arr, b->size);
}

void	sort_inc(stack *a)
{
	int	min;
	int next_min;
	int	i;
	int	dist;

	min = find_min(a->arr, a->size);
	next_min = min;
	i = -1;
	while (++i < a->size - 1)
	{
		next_min = find_next_min(a->arr, a->size, next_min);
		dist = distance(min, next_min, a->arr, a->size);
		//printf("min: %d, next min: %d, dist: %d\n", min, next_min, dist);
		if (dist != 1)
			rotate_to_top(a, next_min);
		if (dist > 1)
			move_up(a, dist - 1);
		else if (dist < 0)
			move_down(a, -dist);
		min = next_min;
	}
	min = find_min(a->arr, a->size);
	rotate_to_top(a, min);
}

void	sort_dec(stack *a)
{
	int	max;
	int next_max;
	int	i;
	int	dist;

	max = find_max(a->arr, a->size);
	next_max = max;
	i = -1;
	while (++i < a->size - 1)
	{
		next_max = find_next_max(a->arr, a->size, next_max);
		dist = distance(max, next_max, a->arr, a->size);
		//printf("max: %d, next max: %d, dist: %d\n", max, next_max, dist);
		if (dist != 1)
			rotate_to_top(a, next_max);
		if (dist > 1)
			move_up(a, dist - 1);
		else if (dist < 0)
			move_down(a, -dist);
		max = next_max;
	}
	max = find_max(a->arr, a->size);
	rotate_to_top(a, max);
}
/*
void	sort(stack *a, stack *b)
{
	int	aa[3];
	int	bb[3];
	int	i;

	aa[0] = find_min(a->arr, a->size);
	bb[0] = find_max(b->arr, b->size);
	aa[1] = aa[0];
	bb[1] = bb[0];
	i = -1;
	while (++i < b->size - 1)
	{
		aa[1] = find_next_min(a->arr, a->size, aa[1]);
		bb[1] = find_next_max(b->arr, b->size, bb[1]);
		aa[2] = distance(aa[0], aa[1], a->arr, a->size);
		bb[2] = distance(bb[0], bb[1], b->arr, b->size);
		printf("a min: %d, a min 2: %d\nb max: %d, b max 2: %d\na dist: %d, b dist: %d\n", aa[0], aa[1], bb[0], bb[1], aa[2], bb[2]);
		if (aa[2] != 1 || bb[2] != 1)
			rotate_to_top_together(a, b, aa[1], bb[1]);
		if (aa[2] > 1 && bb[2] > 1)
			move_up_together(a, b, aa[2], bb[2]);
		else if (aa[2] < 0 && bb[2] < 0)
			move_down_together(a, b, aa[2], bb[2]);
		else if (aa[2] < 0 && bb[2] > 0)
		{
			move_down(a, -aa[2]);
			move_up(b, bb[2] - 1);
		}
		else if (aa[2] > 0 && bb[2] < 0)
		{
			move_down(a, aa[2] - 1);
			move_up(b, -bb[2] - 1);
		}
		aa[0] = aa[1];
		bb[0] = bb[1];
	}
	aa[0] = find_min(a->arr, a->size);
	bb[0] = find_max(b->arr, b->size);
	rotate_to_top_together(a, b, aa[0], bb[0]);
}
*/