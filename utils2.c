/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:17:50 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/28 10:27:37 by mitasci          ###   ########.fr       */
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
	ind = -1;
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

int	count_val(int *arr, int size, int val)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (++i < size)
	{
		if (arr[i] == val)
			count++;
	}
	return (count);
}

int	arr_sum(int *arr, int size)
{
	int	sum;
	int	i;

	sum = 0;
	i = -1;
	while (++i < size)
		sum += arr[i];
	return (sum);
}

int	all_els_eq(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (arr[i] != arr[i + 1])
			return (0);
	}
	return (1);
}

int	all_els_neg(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] > 0)
			return (0);
	}
	return (1);
}

void	sort_3_inc(stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
		return ;
	else if (a->arr[0] < a->arr[2] && a->arr[2] < a->arr[1])
	{
		s(a);
		r(a);
	}
	else if (a->arr[1] < a->arr[0] && a->arr[0] < a->arr[2])
		s(a);
	else if (a->arr[2] < a->arr[0] && a->arr[0] < a->arr[1])
		revr(a);
	else if (a->arr[1] < a->arr[2] && a->arr[2] < a->arr[0])
		r(a);
	else
	{
		s(a);
		revr(a);
	}
}

void	sort_3_dec(stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
	{
		s(a);
		revr(a);
	}
	else if (a->arr[0] < a->arr[2] && a->arr[2] < a->arr[1])
		r(a);
	else if (a->arr[1] < a->arr[0] && a->arr[0] < a->arr[2])
		revr(a);
	else if (a->arr[2] < a->arr[0] && a->arr[0] < a->arr[1])
		s(a);
	else if (a->arr[1] < a->arr[2] && a->arr[2] < a->arr[0])
	{
		revr(a);
		s(a);
	}
}

void	sort_3_inc_dig(stack *a, int digit)
{
	int	*dig_arr;

	dig_arr = get_digit_arr(*a, digit);
	if (dig_arr[0] < dig_arr[1] && dig_arr[1] < dig_arr[2])
		return ;
	else if (dig_arr[0] < dig_arr[2] && dig_arr[2] < dig_arr[1])
	{
		s(a);
		r(a);
	}
	else if (dig_arr[1] < dig_arr[0] && dig_arr[0] < dig_arr[2])
		s(a);
	else if (dig_arr[2] < dig_arr[0] && dig_arr[0] < dig_arr[1])
		revr(a);
	else if (dig_arr[1] < dig_arr[2] && dig_arr[2] < dig_arr[0])
		r(a);
	else
	{
		s(a);
		revr(a);
	}
	free(dig_arr);
}

void	sort_3_dec_dig(stack *a, int digit)
{
	int	*dig_arr;

	dig_arr = get_digit_arr(*a, digit);
	if (dig_arr[0] < dig_arr[1] && dig_arr[1] < dig_arr[2])
	{
		s(a);
		revr(a);
	}
	else if (dig_arr[0] < dig_arr[2] && dig_arr[2] < dig_arr[1])
		r(a);
	else if (dig_arr[1] < dig_arr[0] && dig_arr[0] < dig_arr[2])
		revr(a);
	else if (dig_arr[2] < dig_arr[0] && dig_arr[0] < dig_arr[1])
		s(a);
	else if (dig_arr[1] < dig_arr[2] && dig_arr[2] < dig_arr[0])
	{
		revr(a);
		s(a);
	}
	free(dig_arr);
}