/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 12:52:35 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	a = initialize_stack_a(argc, argv);
	b = initialize_stack_b();
	p(&a, &b);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	s(&a);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	p(&a, &b);
	print_arr(a.arr, a.size);
	print_arr(b.arr, b.size);
	clean_stack(a);
}