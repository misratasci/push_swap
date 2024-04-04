/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:12:10 by  mitasci          #+#    #+#             */
/*   Updated: 2024/04/04 06:04:22 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*clone_and_sort_array(int *array, int size)
{
	int	*cloned_array;
	int	i;

	i = 0;
	cloned_array = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		cloned_array[i] = array[i];
		i++;
	}
	fake_sort(cloned_array, size);
	return (cloned_array);
}

static int	*find_index(int *array, int size)
{
	int	*cloned_array;
	int	*rank_array;
	int	i;
	int	j;

	cloned_array = clone_and_sort_array(array, size);
	rank_array = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == cloned_array[j])
			{
				rank_array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(cloned_array);
	return (rank_array);
}

static int	*ft_atoi_array(char **list, int size)
{
	int	i;
	int	*arr;

	i = -1;
	list++;
	arr = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		arr[i] = ft_atoi(list[i]);
	return (arr);
}

static void	split_and_stack(int ac, char **av, t_stack *stack, int label)
{
	char	**tmp;

	if (label == 2)
	{
		tmp = ft_split(av[1], ' ');
		stack->size = listlen(tmp);
		ft_checks(tmp, stack->size);
		stack->arr = (int *)malloc(sizeof(int) * stack->size);
		fill_with_zeroes(stack->arr, stack->size);
		stack->tmp_arr = ft_atoi_array(tmp, stack->size);
		stack->arr = find_index(stack->tmp_arr, stack->size);
		free_list(tmp);
	}
	else
	{
		stack->size = (ac - 1);
		stack->arr = (int *)malloc(sizeof(int) * stack->size);
		fill_with_zeroes(stack->arr, stack->size);
		stack->tmp_arr = ft_atoi_array(av, stack->size);
		stack->arr = find_index(stack->tmp_arr, stack->size);
	}
}

void	initialize_stack(int ac, char **av, t_stack *a, t_stack *b)
{
	if (b == NULL)
	{
		a->name = 'a';
		if (ac == 2)
			split_and_stack(ac, av, a, 2);
		else
			split_and_stack(ac, av, a, 3);
	}
	else
	{	
		b->name = 'b';
		b->size = 0;
		b->arr = (int *)malloc(sizeof(int) * a->size);
		fill_with_zeroes(b->arr, a->size);
		b->index = (int *)malloc(sizeof(int) * a->size);
		fill_with_zeroes(b->index, a->size);
	}
}
