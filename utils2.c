/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:50 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 04:37:43 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_with_zeroes(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		a[i] = 0;
}

int	listlen(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	clean_t_stack(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	exit(0);
}

void	free_list(char **l)
{
	int	i;

	i = 0;
	if (!l)
		return ;
	while (l[i])
		free(l[i++]);
	free(l);
}

void	ft_int_max(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	if (str[0] == '-')
	{
		minus = 1;
		i++;
	}
	if ((ft_strlen(str) > 10 && minus == 0)
		|| (ft_strlen(str) > 11 && minus == 1))
		ft_error();
	if ((ft_strlen(str) == 10 && minus == 0)
		|| (ft_strlen(str) == 11 && minus == 1))
	{
		if (str[i] > '2' || str[i + 1] > '1' || str[i + 2] > '4'
			|| str[i + 3] > '7' || str[i + 4] > '4' || str[i + 5] > '8'
			|| str[i + 6] > '3' || str[i + 7] > '6' || str[i + 8] > '4'
			|| (str[i + 9] > '7' && minus == 0)
			|| (str[i + 9] > '8' && minus == 1))
			ft_error();
	}
}
