/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:23:43 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/22 13:59:36 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize - 1 && src[i] && dstsize != 0)
	{
		dst[i] = src[i];
		i += 1;
	}
	if (dstsize != 0)
		dst[i] = 0;
	i = 0;
	while (src[i])
		i += 1;
	return (i);
}
