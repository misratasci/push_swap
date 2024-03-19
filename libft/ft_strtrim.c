/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:16:28 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/25 15:45:55 by mitasci          ###   ########.fr       */
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

static int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (i < strlength(set))
	{
		if (c == set[i])
			return (1);
		i += 1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1[0])
		return (ft_strdup(""));
	start = 0;
	while (in_set(s1[start], set))
		start += 1;
	end = strlength(s1) - 1;
	while (in_set(s1[end], set) && end > 0)
		end -= 1;
	if (end >= start)
		str = (char *)malloc((end - start + 2) * sizeof(char));
	else
		str = (char *)malloc(1);
	if (!str)
		return (0);
	i = -1;
	while (++i < end - start + 1 && end >= start)
		str[i] = s1[start + i];
	str[i] = 0;
	return (str);
}
