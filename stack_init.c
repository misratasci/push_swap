/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:29:53 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 17:46:20 by mitasci          ###   ########.fr       */
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

	a->index = (int *)malloc(sizeof(int) * a->capacity);
	fill_with_zeroes(a->index, a->capacity);
	sorted = sorted_init(a);
	i = -1;
	while (++i < a->size)
		a->index[i] = find_ind(sorted, a->size, a->arr[i]);
	if (sorted)
		free(sorted);
}

t_stack	initialize_stack_a(int argc, char **argv, int capacity)
{
	t_stack	a;
	int		i;
	char	**list;
	int		arr_valid;

	arr_valid = 1;
	a.name = 'a';
	a.capacity = capacity;
	a.arr = (int *)malloc(sizeof(int) * a.capacity);
	fill_with_zeroes(a.arr, a.capacity);
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		a.size = listlen(list);
		i = -1;
		while (++i < a.size)
		{
			if (!is_num(list[i]) || !num_valid(list[i]))
				arr_valid = 0;
			a.arr[i] = ft_atoi(list[i]);
		}
		free_list(list);
	}
	else
	{
		a.size = argc - 1;
		i = -1;
		while (++i < a.size)
		{
			if (!is_num(argv[i + 1]) || !num_valid(argv[i + 1]))
				arr_valid = 0;
			a.arr[i] = ft_atoi(argv[i + 1]);
		}
	}
	if (!arr_valid || check_for_dups(a.arr, a.size))
	{
		write(0, "Error\n", 6);
		clean_stack(&a);
		exit(0);
	}
	index_init(&a);
	a.pivot = a.size - 1;
	return (a);
}

t_stack	initialize_stack_b(t_stack a, int capacity)
{
	t_stack	b;

	b.name = 'b';
	b.capacity = capacity;
	b.size = 0;
	b.arr = (int *)malloc(sizeof(int) * b.capacity);
	fill_with_zeroes(b.arr, b.capacity);
	b.index = (int *)malloc(sizeof(int) * b.capacity);
	fill_with_zeroes(b.index, b.capacity);
	b.pivot = a.pivot / 2;
	return (b);
}

void	clean_stack(t_stack *a)
{
	if (a->arr)
		free(a->arr);
	if (a->index)
		free(a->index);
}
