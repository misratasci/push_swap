/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 04:38:52 by aerbosna         ###   ########.fr       */
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
		ft_checks((argv + 1), (argc - 2));
	initialize_t_stack(argc, argv, 'a', &a, NULL);
	initialize_t_stack(0, NULL, 'b', &a, &b);
	if (check_if_sorted(a.arr, a.size) || a.size == 1)
		clean_t_stack(&a, &b);
	if (a.size == 2)
	{
		s(&a);
		exit (0);
	}
	if (a.size == 3)
		sort_3_inc(&a);
	radix_sort(&a, &b);
	clean_t_stack(&a, &b);
}
