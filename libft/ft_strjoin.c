/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:09:25 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/22 13:59:19 by mitasci          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(strlength(s1) + strlength(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < strlength(s1))
	{
		str[i] = s1[i];
		i += 1;
	}
	i = 0;
	while (i < strlength(s2))
	{
		str[strlength(s1) + i] = s2[i];
		i += 1;
	}
	str[strlength(s1) + i] = 0;
	return (str);
}
