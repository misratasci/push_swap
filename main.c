/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 10:12:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//önceden sort edip medyanını bulmayı dene
void	equalize_stacks(stack *a, stack *b)
{
	int val;
	
	if (a->size == b->size)
		return ;
	while (a->size > b->size)
	{
		val = find_min(a->arr, a->size);
		rotate_to_top(a, val);
		p(a, b);
	}
	while (a->size < b->size)
	{
		val = find_max(b->arr, b->size);
		rotate_to_top(b, val);
		p(b, a);
	}
}

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
		//printf("top: %d\n", a->arr[0]);
		if (a->arr[0] < middle)
			p(a, b);
		else
			r(a);
		//print_arr(a->arr, a->size);
		//print_arr(b->arr, b->size);
	}
	equalize_stacks(a, b);
}

void	merge_stacks(stack *a, stack *b)
{
	while (b->size > 0)
		p(b, a);
}

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	if (argc <= 1)
		return (1);
	//error if duplicate, not num, bigger than int
	a = initialize_stack_a(argc, argv);
	b = initialize_stack_b();
	
	print_stacks(a, b);
	rr(&a, &b);
	print_stacks(a, b);

	//print_arr(b.arr, b.size);

	//sort(&a, &b);
	
	//print_arr(b.arr, b.size);

	//merge_stacks(&a, &b);
	
	//print_arr(a.arr, a.size);
	clean_stack(a);
	clean_stack(b);
}