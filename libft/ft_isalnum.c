/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:50:29 by mitasci           #+#    #+#             */
/*   Updated: 2023/12/11 16:05:30 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	isdigit;
	int	isalpha;

	isdigit = (c >= '0' && c <= '9');
	isalpha = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	return (isdigit || isalpha);
}
