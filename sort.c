/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:59:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/28 10:47:38 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_digit(int a, int digit)
{
	int	i;
	int	res;

	i = 0;
	while (i < digit)
	{
		res = a % 10;
		a /= 10;
		i++;
	}
	return (res);
}

int	*get_digit_arr(stack a, int digit)
{
	int *res;
	int	i;
	
	res = (int *)malloc(sizeof(int) * a.size);
	i = 0;
	while (i < a.size)
	{
		res[i] = get_digit(a.index[i], digit);
		i++;
	}
	return (res);
}

int	find_place_dec(int val, int digit, stack *b)
{
	int	i;
	int	max;
	int	min;
	int	*dig_arr;
	int	res;

	dig_arr = get_digit_arr(*b, digit);
	max = find_max(dig_arr, b->size);
	min = find_min(dig_arr, b->size);
	res = -1;
	if (max <= val)
		res = find_ind(dig_arr, b->size, max);
	else if (min >= val)
		res = (find_ind(dig_arr, b->size, min) + 1) % b->size;
	else if (val >= dig_arr[0] && val <= dig_arr[b->size - 1])
		res = 0;
	i = -1;
	while (++i < b->size)
	{	
		if (val < dig_arr[i] && val >= dig_arr[(i + 1) % b->size])
			res = (i + 1) % b->size;
	}
	free(dig_arr);
	return (res);
}
/*
int	get_push_ind_dig(stack *a, stack *b, int digit)
{
	int	i;
	int	ind;
	int	*dig_arr;
	
	dig_arr = get_digit_arr(*a, digit);
	i = -1;
	ind = INT32_MAX;
	while (++i < min(a->size, b->size))
	{
		if (i == find_place(a->arr[i], b)) {
		//printf("place: %d\n", find_place(a->arr[i], b));
			ind = i;
			break;
		}
	}
	i = a->size;
	while (--i > abs(a->size - b->size))
	{
		if (a->size - i == b->size - find_place(a->arr[i], b))
		{
			if (ind == -1 || ind > a->size - i)
				ind = i - a->size;
		}
	}
	return (ind);
}
*/
void	sort(stack *a, stack *b)
{
	p(a, b);
	p(a, b);
	p(a, b);
	sort_3_dec_dig(a, 1);
	print_stacks(*a, *b);
	printf("place: %d\n", find_place_dec(1, 1, b));
	
}
