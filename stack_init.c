/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:29:53 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 21:32:17 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sorted_init(t_stack *a)
{
	int	curr_min;
	int	i;
	int	*sorted;

	sorted = (int *)malloc(sizeof(int) * a->size);
	curr_min = find_min(a->arr, a->size);
	sorted[0] = curr_min;
	i = 1;
	while (i < a->size)
	{
		sorted[i] = find_next_min(a->arr, a->size, sorted[i - 1]);
		i++;
	}
	return (sorted);
}

static void	index_init(t_stack *a)
{
	int	i;
	int	*sorted;

	a->index = (int *)malloc(sizeof(int) * a->size);
	sorted = sorted_init(a);
	i = -1;
	while (++i < a->size)
		a->index[i] = find_ind(sorted, a->size, a->arr[i]);
	if (sorted)
		free(sorted);
}

t_stack	initialize_stack_a(int argc, char **argv)
{
	t_stack	a;
	int		i;
	char	**list;

	a.name = 'a';
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		a.size = listlen(list);
		a.arr = (int *)malloc(sizeof(int) * a.size);
		i = -1;
		while (++i < a.size)
			a.arr[i] = ft_atoi(list[i]);
		free_list(list);
	}
	else
	{
		a.size = argc - 1;
		a.arr = (int *)malloc(sizeof(int) * a.size);
		i = -1;
		while (++i < a.size)
			a.arr[i] = ft_atoi(argv[i + 1]);
	}
	index_init(&a);
	return (a);
}

t_stack	initialize_stack_b(t_stack a)
{
	t_stack	b;

	b.name = 'b';
	b.size = 0;
	b.arr = (int *)malloc(sizeof(int) * a.size);
	fill_with_zeroes(b.arr, a.size);
	b.index = (int *)malloc(sizeof(int) * a.size);
	fill_with_zeroes(b.index, a.size);
	return (b);
}

void	clean_stacks(t_stack *a, t_stack *b)
{
	if (a->arr)
		free(a->arr);
	if (a->index)
		free(a->index);
	if (b->arr)
		free(b->arr);
	if (b->index)
		free(b->index);
}
