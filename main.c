/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/29 12:58:44 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	b = initialize_stack_b(a);
	
	print_stacks(a, b);

	sort(&a, &b);

	print_stacks(a, b);
	
	//merge_stacks(&a, &b);
	
	clean_stack(a);
	clean_stack(b);
}