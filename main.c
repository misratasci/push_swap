/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/03 15:13:18 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	if (argc <= 1)
		return (0);
	//error if not num, bigger than int
	a = initialize_stack_a(argc, argv, 500);
	b = initialize_stack_b(a, 500);

	
	if (check_if_sorted(a.arr, a.size) || a.size == 1)
	{
		clean_stack(&a);
		clean_stack(&b);
		return (0);
	}
	if (a.size == 2)
	{
		s(&a);
		return (0);
	}
	if (a.size == 3)
	{
		sort_3_inc(&a);
		return (0);
	}
	sort(&a, &b);

	//print_stacks(a, b);
	
	clean_stack(&a);
	clean_stack(&b);
}