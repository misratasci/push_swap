/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 14:13:46 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(stack *a, stack *b)
{
	int i;
	int	size;
	int	j;

	size = b->size;
	if (a->size > b->size)
		size = a->size;
	j = -1;
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size - j)
		{
			if (a->top > a->arr[a->size - 2] && b->top > b->arr[b->size - 2])
			{
				ss(a, b);
				ft_putendl_fd("ss", 1);
			}
			else if (a->top > a->arr[a->size - 2])
			{
				s(a);
				ft_putendl_fd("sa", 1);
			}
			else if (b->top > b->arr[b->size - 2])
			{
				s(b);
				ft_putendl_fd("sb", 1);
			}
			else
			{
				rr(a, b);
				ft_putendl_fd("rr", 1);
			}
			print_arr(a->arr, a->size);
			print_arr(b->arr, b->size);
		}
		//rr(a, b);
		//ft_putendl_fd("rr", 1);
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
	
	split_stacks(&a, &b);
	sort(&a, &b);

	//print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);
	
	clean_stack(a);
	clean_stack(b);
}