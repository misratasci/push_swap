/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:22:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/26 23:38:53 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(stack a)
{
	int	i;

	i = -1;
	while (++i < a.size - 1)
	{
		if (a.arr[i] > a.arr[i + 1])
			return (0);
	}
	return (1);
}

int	find_place(int val, stack *b)
{
	int	i;
	int	max;
	int	min;

	max = find_max(b->arr, b->size);
	if (max < val)
		return (find_ind(b->arr, b->size, max));
	min = find_min(b->arr, b->size);
	if (min > val)
		return ((find_ind(b->arr, b->size, min) + 1) % b->size);
	if (val > b->arr[0] && val < b->arr[b->size - 1])
		return (0);
	i = -1;
	while (++i < b->size)
	{	
		if (val < b->arr[i] && val > b->arr[(i + 1) % b->size])
			return ((i + 1) % b->size);
	}
	return (-1);
}

int	get_push_ind(stack *a, stack *b)
{
	int	i;
	int	ind;
	
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

void	simulate_moves(stack *a, stack *b, int *moves, int move_count)
{
	int	i;
	
	i = -1;
	while (++i < move_count)
	{
		if (moves[i] == 0)
			r_sim(a);
		else if (moves[i] == 1)
			r_sim(b);
		else if (moves[i] == 2)
			s_sim(a);
		else if (moves[i] == 3)
			revr_sim(a);
		else if (moves[i] == 4)
			revr_sim(b);
	}
}

void	reverse_moves(stack *a, stack *b, int *moves, int move_count)
{
	int	*rev_moves;
	int	i;

	rev_moves = (int *)malloc(sizeof(int) * move_count);
	i = -1;
	while (++i < move_count)
		rev_moves[i] = 4 - moves[move_count - i];
	simulate_moves(a, b, rev_moves, move_count);
	free(rev_moves);
}

void	make_moves(stack *a, stack *b, int *moves, int move_count)
{
	int	i;
	
	i = -1;
	while (++i < move_count)
	{
		if (moves[i] == 0)
			r(a);
		else if (moves[i] == 1)
			r(b);
		else if (moves[i] == 2)
			s(a);
		else if (moves[i] == 3)
			revr(a);
		else if (moves[i] == 4)
			revr(b);
	}
}

int	get_profit(stack *a, stack *b, int *moves, int move_count)
{
	int	old;
	int	new;

	old = get_push_ind(a, b);
	simulate_moves(a, b, moves, move_count);
	new = get_push_ind(a, b);
	reverse_moves(a, b, moves, move_count);
	if (old == INT32_MAX && new == INT32_MAX)
		return (0);
	if (old == INT32_MAX)
		return (abs(new) + move_count);
	if (new == INT32_MAX)
		return (-1);
	return (abs(old) - (abs(new) + move_count));
}

int **get_move_arrs1()
{
	int	i;
	int	*moves;
	int	**move_arrs;

	move_arrs = (int **)malloc(sizeof(int *) * 5);
	i = -1;
	while (++i < 5)
	{
		moves = (int *)malloc(sizeof(int) * 1);
		moves[0] = i;
		move_arrs[i] = moves;
	}
	return (move_arrs);
}

int **get_move_arrs2()
{
	int	i;
	int	j;
	int	*moves;
	int **move_arrs;
	
	move_arrs = (int **)malloc(sizeof(int *) * 25);
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			moves = (int *)malloc(sizeof(int) * 2);
			moves[0] = i;
			moves[1] = j;
			move_arrs[i * 5 + j] = moves;
		}
	}
	return (move_arrs);	
}

void	simulate(stack *a, stack *b)
{
	int **move_arrs1;
	int	**move_arrs2;
	int	i;
	int	profit[30];
	int ind;

	move_arrs1 = get_move_arrs1();
	move_arrs2 = get_move_arrs2();
	i = 0;
	while (i < 5)
	{
		profit[i] = get_profit(a, b, move_arrs1[i], 1);
		i++;
	}
	while(i < 30)
	{
		profit[i] = get_profit(a, b, move_arrs2[i - 5], 2);
		i++;
	}
	if (all_els_neg(profit, 30))
		return ;
	//printf("profit arr:\n");
	//print_arr(profit, 30);
	ind = find_ind(profit, 25, find_max(profit, 25));
	//printf("ind: %d\n", ind);
	if (ind < 5)
		make_moves(a, b, move_arrs1[ind], 1);
	else
		make_moves(a, b, move_arrs2[ind], 2);
}

void	sort(stack *a, stack *b)
{
	int	push_ind;

	p(a, b);
	p(a, b);
	p(a, b);
	sort_3_dec(b);
	while (a->size > 3)
	{
		simulate(a, b);
		print_stacks(*a, *b);
		push_ind = get_push_ind(a, b);
		printf("push ind: %d\n", push_ind);
		if (push_ind != INT32_MAX)
			rotate_push(a, b, push_ind);
		else if (a->size > b->size)
			r(a);
		else
			r(b);
	}
	rotate_to_top(b, find_max(b->arr, b->size));
}
