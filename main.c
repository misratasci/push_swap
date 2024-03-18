/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 15:05:33 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(stack *a, int ind)
{
	int	i;
	
	if (ind < a->size / 2)
	{
		i = -1;
		while (++i <= ind)
		{
			revr(a);
			ft_putendl_fd("rra", 1);
		}
	}
	else if (ind >= a->size / 2 && ind != a->size - 1)
	{
		i = -1;
		while (++i < a->size - ind - 1)
		{
			r(a);
			ft_putendl_fd("ra", 1);
		}
	}
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
		printf("Moved up\n");
		print_arr(a->arr, a->size);
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
		printf("Moved down\n");
		print_arr(a->arr, a->size);
	}
}

void	sort_inc(stack *a)
{
	int	min;
	int	min_ind;
	int next_min;
	int	min_ind2;
	int	j;

	min = find_min(a->arr, a->size);
	next_min = min;
	min_ind = find_ind(a->arr, a->size, next_min);
	j = -1;
	while (++j < a->size)
	{
		next_min = find_next_min(a->arr, a->size, next_min);
		min_ind2 = find_ind(a->arr, a->size, next_min);
		if (distance(min_ind, min_ind2, a->size) != 1)
			rotate_to_top(a, min_ind2);
		if (distance(min_ind, min_ind2, a->size) > 0)
			move_up(a, distance(min_ind, min_ind2, a->size) - 1);
		else
			move_down(a, -distance(min_ind, min_ind2, a->size));
		min = next_min;
		min_ind = find_ind(a->arr, a->size, min);
	}
	min = find_min(a->arr, a->size);
	min_ind = find_ind(a->arr, a->size, min);
	rotate_to_top(a, min_ind);
}

void	sort_dec(stack *a)
{
	int	max;
	int	max_ind;
	int next_max;
	int	max_ind2;
	int	j;

	max = find_max(a->arr, a->size);
	next_max = max;
	max_ind = find_ind(a->arr, a->size, next_max);
	j = -1;
	while (++j < a->size)
	{
		next_max = find_next_max(a->arr, a->size, next_max);
		max_ind2 = find_ind(a->arr, a->size, next_max);
		if (distance(max_ind, max_ind2, a->size) != 1)
			rotate_to_top(a, max_ind2);
		if (distance(max_ind, max_ind2, a->size) > 1)
			move_up(a, distance(max_ind, max_ind2, a->size) - 1);
		else
			move_down(a, -distance(max_ind, max_ind2, a->size));
		max = next_max;
		max_ind = find_ind(a->arr, a->size, max);
	}
	max = find_max(a->arr, a->size);
	max_ind = find_ind(a->arr, a->size, max);
	rotate_to_top(a, max_ind);
}

void	split_stacks(stack *a, stack *b)
{
	int middle;
	int	i;
	int	size;

	size = a->size;
	middle = find_middle(a->arr, a->size);
	i = -1;
	printf("middle: %d\n", middle);
	while (++i < size)
	{
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

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	//error if duplicate, not num, bigger than int
	a = initialize_stack_a(argc, argv);
	b = initialize_stack_b();
	
	//split_stacks(&a, &b);
	p(&a, &b);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	revr(&a);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	r(&a);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	//sort_inc(&a);

	//print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);
	
	clean_stack(a);
	clean_stack(b);
}