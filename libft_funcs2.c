/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:12:16 by  mitasci          #+#    #+#             */
/*   Updated: 2024/04/04 06:04:31 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whitespace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
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
		if (!ft_isdigit(str[i]))
			break ;
		res *= 10;
		res += str[i] - '0';
		i += 1;
	}
	return (is_neg * res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
		{
			if (c1 > c2)
				return (1);
			else
				return (-1);
		}
		i += 1;
		if (c1 == 0 && c2 == 0)
			break ;
	}
	return (0);
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
