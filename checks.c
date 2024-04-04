/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:12:02 by aerbosna          #+#    #+#             */
/*   Updated: 2024/04/04 04:37:43 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_digit(char **t_stack, int arg_size)
{
	int	i;

	i = -1;
	while (arg_size >= 0)
	{
		while (t_stack[arg_size][++i])
		{
			if (t_stack[arg_size][i] == '-' && i == 0)
				continue ;
			else if (!ft_isdigit(t_stack[arg_size][i]))
				ft_error();
		}
		arg_size--;
		i = -1;
	}
}

void	has_duplicates(char **t_stack, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= arg_size)
	{
		j = i + 1;
		while (j < arg_size)
			if (!ft_strcmp(t_stack[i], t_stack[j++]))
				ft_error();
		i++;
	}
}

void	int_limit(char **t_stack, int arg_size)
{
	while (arg_size >= 0)
	{
		ft_int_max(t_stack[arg_size]);
		arg_size--;
	}
}

void	is_sorted(char **t_stack, int arg_size)
{
	int	i;

	i = arg_size;
	while (--i >= 0)
	{
		if (ft_atoi(t_stack[i]) > ft_atoi(t_stack[arg_size--]))
			return ;
	}
	exit(0);
}

void	ft_checks(char **t_stack, int arg_size)
{
	all_digit(t_stack, arg_size);
	has_duplicates(t_stack, arg_size);
	int_limit(t_stack, arg_size);
	is_sorted(t_stack, arg_size);
}
