/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:19 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 01:12:47 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	all_digit(char **stack, int arg_size)
{
	int i;

	i = -1;
	while(arg_size >= 0)
	{
		while(stack[arg_size][++i])
		{
			if(stack[arg_size][i] == '-' && i == 0)
				continue;
			else if(!ft_isdigit(stack[arg_size][i]))
				ft_error();
		}
		arg_size--;
		i = -1;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void	has_duplicates(char **stack, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= arg_size)
	{
		j = i + 1;
		while (j < arg_size)
			if (!ft_strcmp(stack[i], stack[j++]))
				ft_error();
		i++;
	}
}

void ft_int_max(char *str)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	if (str[0] == '-')
	{
		minus = 1;
		i++;
	}
	if ((ft_strlen(str) > 10 && minus == 0) || (ft_strlen(str) > 11 && minus == 1))
		ft_error();
	if ((ft_strlen(str) == 10 && minus == 0) || (ft_strlen(str) == 11 && minus == 1))
	{
		if (str[i] > '2' || str[i + 1] > '1' || str[i + 2] > '4' 
		|| str[i + 3] > '7' || str[i + 4] > '4' || str[i + 5] > '8' 
		|| str[i + 6] > '3' || str[i + 7] > '6' || str[i + 8] > '4' 
		|| (str[i + 9] > '7' && minus == 0) || (str[i + 9] > '8' && minus == 1))
			ft_error();
	}
}

void int_limit(char **stack, int arg_size)
{
	while (arg_size >= 0)
	{
		ft_int_max(stack[arg_size]);
		arg_size--;
	}
}

void is_sorted(char **stack, int arg_size)
{
	int i;

	i = arg_size;
	while (--i >= 0)
	{
		if (ft_atoi(stack[i]) > ft_atoi(stack[arg_size--]))
			return ;
	}
	exit(0);
}

void	ft_checks(char **stack, int arg_size)
{
	all_digit(stack, arg_size);
	has_duplicates(stack, arg_size);
	int_limit(stack, arg_size);
	is_sorted(stack, arg_size);
}

int	main(int argc, char **argv)
{
	stack a;
	stack b;
	
	if (argc <= 1)
		return (0);
	else
		ft_checks((argv + 1), (argc - 2));
	
	a = initialize_stack_a(argc, argv);
	b = initialize_stack_b(a);

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