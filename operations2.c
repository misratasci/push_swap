/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:19:35 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 14:42:45 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
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

int	ind_distance(int ind1, int ind2, int size)
{
	int diff;

	diff = abs(ind1 - ind2);	
	if (diff <= size / 2)
	{
		return (diff);
	}
	else
		return (diff - size);
}