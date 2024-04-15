/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:28:30 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 17:49:03 by mitasci          ###   ########.fr       */
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
