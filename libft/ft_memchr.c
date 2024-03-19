/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:39:45 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/22 14:11:04 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	ss;

	i = 0;
	ch = c;
	while (i < n)
	{
		ss = *((char *)s);
		if (ss == ch)
			return ((void *)s);
		i += 1;
		s += 1;
	}
	return (NULL);
}
