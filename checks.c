/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:28:30 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 21:03:58 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_valid(char *a)
{
	size_t	len;

	len = ft_strlen(a);
	if ((len > 10 && a[0] != '-') || (a[0] == '-' && len > 11))
		return (0);
	if (len == 10 && a[0] != '-' && ft_strncmp(a, "2147483647", 10) > 0)
		return (0);
	if (len == 11 && a[0] == '-' && ft_strncmp(a, "-2147483648", 11) > 0)
		return (0);
	return (1);
}

int	is_num(char *a)
{
	int	i;

	i = 0;
	if (a[0] == '-')
		i++;
	while (a[i])
	{
		if (!ft_isdigit(a[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_dups(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


/*
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
*/