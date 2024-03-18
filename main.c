/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:05:28 by mitasci          ###   ########.fr       */
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
		{
			r(a);
			ft_putendl_fd("ra", 1);
		}
	}
	else
	{
		i = -1;
		while (++i < a->size - ind)
		{
			revr(a);
			ft_putendl_fd("rra", 1);
		}
	}
	//printf("Rotated %d to top\n", val);
	//print_arr(a->arr, a->size);
}

void	move_up(stack *a, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		revr(a);
		ft_putendl_fd("rra", 1);
		s(a);
		ft_putendl_fd("sa", 1);
		//printf("Moved up\n");
		//print_arr(a->arr, a->size);
	}
}

void	move_down(stack *a, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		s(a);
		ft_putendl_fd("sa", 1);
		if (i < n - 1)
		{
			r(a);
			ft_putendl_fd("ra", 1);
		}
		//printf("Moved down\n");
		//print_arr(a->arr, a->size);
	}
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

void	split_stacks(stack *a, stack *b)
{
	int middle;
	int	i;
	int	size;

	size = a->size;
	middle = find_middle(a->arr, a->size);
	i = -1;
	//printf("middle: %d\n", middle);
	while (++i < size)
	{
		//printf("top: %d\n", a->top);
		if (a->top < middle)
		{
			p(a, b);
			ft_putendl_fd("pb", 1);
		} 
		else
		{
			r(a);
			ft_putendl_fd("ra", 1);
		}
		//print_arr(a->arr, a->size);
		//print_arr(b->arr, b->size);
	}
}

void	merge_stacks(stack *a, stack *b)
{
	while (b->size > 0)
	{
		p(b, a);
		ft_putendl_fd("pa", 1);
	}
}

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	if (argc <= 1)
		return (1);
	//error if duplicate, not num, bigger than int
	a = initialize_stack_a(argv);
	b = initialize_stack_b();
	
	split_stacks(&a, &b);

	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);

	sort_inc(&a);
	sort_dec(&b);

	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);

	merge_stacks(&a, &b);
	
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	
	clean_stack(a);
	clean_stack(b);
}