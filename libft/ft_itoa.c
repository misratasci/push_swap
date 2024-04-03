/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:13:13 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/22 14:28:24 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_count(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		return (char_count(-n) + 1);
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*handle_negmaxnum(int n)
{
	char	*s;
	size_t	len;

	len = 11;
	s = (char *)malloc(12);
	if (!s)
		return (NULL);
	s[0] = '-';
	s[1] = '2';
	while (n > 0)
	{
		s[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	s[11] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	org_len;

	if (n == -2147483648)
		return (handle_negmaxnum(147483648));
	len = char_count(n);
	org_len = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n /= 10;
	}
	str[org_len] = 0;
	return (str);
}
