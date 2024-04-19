/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:28:30 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/19 15:02:23 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_digit(char **t_stack, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_size)
	{
		j = 0;
		while (t_stack[i][j])
		{
			if (t_stack[i][0] == '-')
			{
				j++;
				continue ;
			}
			else if (!ft_isdigit(t_stack[i][j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	has_duplicates(char **a, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arg_size)
	{
		j = i + 1;
		while (j < arg_size)
		{
			if (ft_atoi(a[i]) == ft_atoi(a[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	int_limit(char **a, int arg_size)
{
	size_t	len;
	int		i;

	i = 0;
	while (i < arg_size)
	{
		len = ft_strlen(a[i]);
		if ((len > 10 && a[i][0] != '-') || (a[i][0] == '-' && len > 11))
			ft_error();
		if (len == 10 && a[i][0] != '-' &&
			ft_strncmp(a[i], "2147483647", 10) > 0)
			ft_error();
		if (len == 11 && a[i][0] == '-' &&
			ft_strncmp(a[i], "-2147483648", 11) > 0)
			ft_error();
		i++;
	}
}

static void	is_sorted(char **a, int arg_size)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < arg_size - 1)
	{
		if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
			sorted = 0;
		i++;
	}
	if (sorted)
		exit(0);
}

void	ft_checks(char **t_stack, int arg_size)
{
	char	**args;
	if (arg_size == 1 && ft_strchr(t_stack[0], ' '))
	{
		args = ft_split(t_stack[0], ' ');
		arg_size = listlen(args);
	}
	else
		args = t_stack;
	all_digit(args, arg_size);
	has_duplicates(args, arg_size);
	int_limit(args, arg_size);
	is_sorted(args, arg_size);
	if (arg_size == 1 && ft_strchr(t_stack[0], ' '))
		free_list(args);
	if (arg_size == 1 && !ft_strchr(t_stack[0], ' '))
		exit(0);
}
