/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/12 19:51:01 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	initialize_stack(int argc, char **argv)
{
	stack	a;
	int		i;
	
	a.size = argc - 1;
	i = -1;
	while (++i < a.size)
		a.stack[i] = ft_atoi(argv[i]);
	a.top = a.stack[a.size];
	return (a);
}