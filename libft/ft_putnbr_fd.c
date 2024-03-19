/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:13 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/14 19:15:21 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_count(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		return (char_count(-n));
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static size_t	tenpow(size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 1;
	while (i++ < n)
		res *= 10;
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	len = char_count(n);
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (len > 0)
	{
		c = n / (tenpow(len - 1)) + '0';
		n = n % (tenpow(len - 1));
		write(fd, &c, 1);
		len--;
	}
}
