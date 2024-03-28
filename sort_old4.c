/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_old4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:59:31 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/28 16:09:54 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	get_digit(int a, int digit)
{
	int	i;
	int	ten;

	i = 0;
	ten = 1;
	while (i++ < digit)
		ten *= 10;
	return (a % ten);
}*/
/*
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
*/
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

int	find_place_dec(int value, int digit, stack *b)
{
	int	i;
	int	*dig_arr;
	int	res;
	int	val;

	val = get_digit(value, digit);
	dig_arr = get_digit_arr(*b, digit);
	res = -1;
	if (find_max(dig_arr, b->size) <= val)
		res = find_ind(dig_arr, b->size, find_max(dig_arr, b->size));
	else if (find_min(dig_arr, b->size) >= val)
		res = (find_ind(dig_arr, b->size, find_min(dig_arr, b->size)) + 1) % b->size;
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

int	get_push_ind_dec(stack *a, stack *b, int digit)
{
	int	i;
	int	ind;
	int	*dig_arr;
	
	dig_arr = get_digit_arr(*a, digit);
	i = -1;
	ind = INT32_MAX;
	while (++i < min(a->size, b->size))
	{
		if (i == find_place_dec(a->index[i], digit, b)) {
		//printf("place: %d\n", find_place(dig_arr[i], b));
			ind = i;
			break;
		}
	}
	i = a->size;
	while (--i > abs(a->size - b->size))
	{
		if (a->size - i == b->size - find_place_dec(a->index[i], digit, b))
		{
			if (ind == -1 || ind > a->size - i)
				ind = i - a->size;
		}
	}
	free(dig_arr);
	return (ind);
}

void	rotate_push(stack *a, stack *b, int push_ind)
{
	int	i;
	
	i = 0;
	//printf("hello\n");
	while (push_ind >= 0 && i++ < push_ind)
		rr(a, b);
	while (push_ind < 0 && i++ < -push_ind)
		revrr(a, b);
	p(a, b);
}

void	try_swap(stack *a, stack *b)
{
	int	old;
	int	new;
	
	old = get_push_ind_dec(a, b, 1);
	s_sim(a);
	new = get_push_ind_dec(a, b, 1);
	if (old == INT32_MAX && new == INT32_MAX)
		return ;
	if (abs(old) > abs(new) + 1)
	{
		s_sim(a);
		s(a);
	}
}
/*
void	push_to_b(stack *a, stack *b)
{
	int	push_ind;
	
	p(a, b);
	p(a, b);
	p(a, b);
	sort_3_dec_dig(a, 1);
	while (a->size > 0)
	{
		try_swap(a, b);
		print_stacks(*a, *b);
		push_ind = get_push_ind_dec(a, b, 1);
		//printf("push ind: %d\n", push_ind);
		if (push_ind != INT32_MAX)
			rotate_push(a, b, push_ind);
		else if (a->size > b->size)
			r(a);
		else
			r(b);
	}
}
*/
int	find_place_inc(int val, int digit, stack *a)
{
	int	i;
	int	*dig_arr;
	int	res;

	dig_arr = get_digit_arr(*a, digit);
	res = -1;
	if (find_max(dig_arr, a->size) <= val)
		res = (find_ind(dig_arr, a->size, find_max(dig_arr, a->size)) + 1) % a->size;
	else if (find_min(dig_arr, a->size) >= val)
		res = find_ind(dig_arr, a->size, find_min(dig_arr, a->size));
	else if (val <= dig_arr[0] && val >= dig_arr[a->size - 1])
		res = 0;
	i = -1;
	while (++i < a->size)
	{	
		if (val > dig_arr[i] && val <= dig_arr[(i + 1) % a->size])
			res = (i + 1) % a->size;
	}
	free(dig_arr);
	return (res);
}

int	get_push_ind_inc(stack *a, stack *b, int digit)
{
	int	i;
	int	ind;
	int	*dig_arr;
	
	dig_arr = get_digit_arr(*a, digit);
	i = -1;
	ind = INT32_MAX;
	while (++i < min(a->size, b->size))
	{
		//printf("forward place %d: %d\n", i, find_place_inc(a->index[i], digit, b));
		if (i == find_place_inc(a->index[i], digit, b)) {
			ind = i;
			break;
		}
	}
	
	i = a->size;
	while (--i > abs(a->size - b->size))
	{
		//printf("backward place %d: %d\n", a->size - i, b->size - find_place_inc(a->index[i], digit, b));
		if (a->size - i == b->size - find_place_inc(a->index[i], digit, b))
		{
			if (ind == -1 || ind > a->size - i)
				ind = i - a->size;
		}
	}
	
	free(dig_arr);
	return (ind);
}
/*
void	push_to_a(stack *a, stack *b)
{
	int	push_ind;
	
	p(b, a);
	p(b, a);
	if (get_digit(a->index[0], 2) > get_digit(a->index[1], 2))
		s(a);
	while (b->size > 0)
	{
		//print_stacks(*a, *b);
		push_ind = get_push_ind_inc(b, a, 2);
		//printf("push ind: %d\n", push_ind);
		if (push_ind != INT32_MAX)
			rotate_push(b, a, push_ind);
		else if (a->size > b->size)
			r(a);
		else
			r(b);
	}
}
*/
/*
void	sort(stack *a, stack *b)
{
	push_to_b(a, b);
	print_stacks(*a, *b);
	//push_to_a(a, b);
}
*/