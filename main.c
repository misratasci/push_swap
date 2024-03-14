/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 17:28:43 by mitasci          ###   ########.fr       */
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

void	sort(stack *a)
{
	int	min_ind;
	int	min_ind2;
	int	i;
	int	j;

	min_ind = find_min_ind(a->arr, a->size);
	printf("rotate to top min_ind\n");
	rotate_to_top(a, min_ind);
	print_arr(a->arr, a->size);
	j = -1;
	while (++j < a->size)
	{
		printf("j: %d\n", j);
		min_ind2 = find_min_ind(a->arr, a->size - j - 1);
		printf("min_ind2: %d\n", min_ind2);
		printf("rotate to top min_ind2\n");
		rotate_to_top(a, min_ind2);
		print_arr(a->arr, a->size);
		min_ind = find_min_ind(a->arr, a->size) - j;
		printf("min_ind: %d\n", min_ind);
		if (min_ind <= a->size / 2)
		{
			i = -1;
			while (++i < min_ind)
			{
				revr(a);
				ft_putendl_fd("rra", 1);
				print_arr(a->arr, a->size);
				s(a);
				ft_putendl_fd("sa", 1);
				print_arr(a->arr, a->size);
			}
		}
		else if (min_ind > a->size / 2 && min_ind != a->size - 2)
		{
			i = -1;
			while (++i < distance(min_ind, a->size - 1, a->size))
			{
				s(a);
				ft_putendl_fd("sa", 1);
				print_arr(a->arr, a->size);
				if (i < distance(min_ind, a->size - 1, a->size) - 1)
				{
					r(a);
					ft_putendl_fd("ra", 1);
					print_arr(a->arr, a->size);
				}
			}
		}
		min_ind = find_min_ind(a->arr, a->size);
		printf("rotate to top min_ind\n");
		rotate_to_top(a, min_ind);
		print_arr(a->arr, a->size);
	}
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

	print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);

	sort(&a);

	print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);
	
	clean_stack(a);
	clean_stack(b);
}