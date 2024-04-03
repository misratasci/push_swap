/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:49:35 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/22 14:04:35 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	d = dst;
	i = 0;
	while (i < n)
	{
		d[i] = ((char *)src)[i];
		i += 1;
	}
	return (dst);
}
