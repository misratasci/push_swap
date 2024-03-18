/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:35 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:20:37 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrr(stack *a, stack *b)
{
	revr(a);
	revr(b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	distance(int val1, int val2, int *a, int size)
{
	int diff;
	int	ind1;
	int	ind2;
	
	ind1 = find_ind(a, size, val1);
	ind2 = find_ind(a, size, val2);
	diff = abs(ind1 - ind2);	
	if (diff <= size / 2)
	{
		return (diff);
	}
	else
		return (diff - size);
}