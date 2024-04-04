/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:12:13 by aerbosna          #+#    #+#             */
/*   Updated: 2024/04/04 04:12:14 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	res;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
			break ;
	}
	res = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

static size_t	count_letters(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*write_word(const char *s, char c)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(count_letters(s, c) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	word;

	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			arr[word++] = write_word(s + i, c);
		i++;
	}
	arr[word] = 0;
	return (arr);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
