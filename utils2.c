/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:50 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/18 17:18:00 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *a, int size)
{
	int	i;
	int	max;

	if (!a || size < 1)
		return (-1);
	max = a[0];
	i = -1;
	while (++i < size)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max);
}

int	find_min(int *a, int size)
{
	int	i;
	int	min;

	if (!a || size < 1)
		return (-1);
	min = a[0];
	i = -1;
	while (++i < size)
	{
		if (a[i] < min)
			min = a[i];
	}
	return (min);
}

int	find_ind(int *a, int size, int value)
{
	int	i;
	int	ind;

	if (!a || size < 1)
		return (-1);
	ind = 0;
	i = -1;
	while (++i < size)
	{
		if (a[i] == value)
			ind = i;
	}
	return (ind);
}

int	find_next_min(int *a, int size, int prev_min)
{
	int	i;
	int	res;

	if (!a || size < 2)
		return (-1);
	i = 0;
	while (a[i] <= prev_min)
		i++;
	if (i >= size)
		return (-1);
	res = a[i];
	while (i < size)
	{
		if (a[i] < res && a[i] > prev_min)
			res = a[i];
		i++;
	}
	return (res);
}

int	find_next_max(int *a, int size, int prev_max)
{
	int	i;
	int	res;

	if (!a || size < 2)
		return (-1);
	i = 0;
	while (a[i] >= prev_max)
		i++;
	res = a[i];
	while (i < size)
	{
		if (a[i] > res && a[i] < prev_max)
			res = a[i];
		i++;
	}
	return (res);
}