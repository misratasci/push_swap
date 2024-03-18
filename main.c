/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:26:07 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stacks(stack *a, stack *b)
{
	int middle;
	int	i;
	int	size;

	size = a->size;
	middle = (find_max(a->arr, a->size) + find_min(a->arr, a->size)) / 2;
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

	//print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);

	sort_inc(&a);
	sort_dec(&b);

	//print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);

	merge_stacks(&a, &b);
	
	print_arr(a.arr, a.size);
	//print_arr(b.arr, b.size);
	
	clean_stack(a);
	clean_stack(b);
}