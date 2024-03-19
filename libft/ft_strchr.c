/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:10:59 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/25 14:37:52 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlength(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			slen;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	slen = strlength(s);
	while (i <= slen)
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		i += 1;
		s += 1;
	}
	return (NULL);
}
