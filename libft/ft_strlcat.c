/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:35:27 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/12 15:45:04 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlength(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i += 1;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = strlength(dst);
	while (i < dstsize - dstlen - 1 && src[i] && dstlen < dstsize)
	{
		dst[dstlen + i] = src[i];
		i += 1;
	}
	if (dstsize != 0 && dstlen < dstsize)
		dst[dstlen + i] = 0;
	if (dstlen > dstsize)
		dstlen = dstsize;
	return (dstlen + strlength(src));
}
