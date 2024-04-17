/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/16 15:08:23 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	else
		ft_checks((argv + 1), (argc - 1));
	a = initialize_stack_a(argc, argv);
	b = initialize_stack_b(a);
	if (a.size == 2)
		s(&a);
	else if (a.size == 3)
		sort_3_inc(&a);
	else if (a.size == 5)
		sort_5_inc(&a, &b);
	else
		sort(&a, &b);
	clean_stacks(&a, &b);
}
