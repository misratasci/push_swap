/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:38:10 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/12 17:52:07 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_isdig(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	is_neg;

	res = 0;
	i = 0;
	is_neg = 1;
	while (is_whitespace(str[i]))
		i += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i += 1;
	}
	while (str[i])
	{
		if (!ft_isdig(str[i]))
			break ;
		res *= 10;
		res += str[i] - '0';
		i += 1;
	}
	return (is_neg * res);
}
