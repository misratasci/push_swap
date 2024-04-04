/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:12:10 by aerbosna          #+#    #+#             */
/*   Updated: 2024/04/04 04:46:29 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fake_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*find_index(int *array, int size)
{
	int	*cloned_array;
	int	*rank_array;
	int	i;
	int	j;

	i = 0;
	j = 0;
	cloned_array = (int *)malloc(size * sizeof(int));
	rank_array = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		cloned_array[i] = array[i];
		i++;
	}
	fake_sort(cloned_array, size);
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
	free (cloned_array);
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

static void	split_and_t_stack(int ac, char **av, t_stack *t_stack, int label)
{
	char	**list;
	int		*arr;

	list = NULL;
	arr = NULL;
	if (label == 2)
	{
		list = ft_split(av[1], ' ');
		t_stack->size = listlen(list);
		ft_checks(list, t_stack->size);
		t_stack->arr = (int *)malloc(sizeof(int) * t_stack->size);
		fill_with_zeroes(t_stack->arr, t_stack->size);
		arr = ft_atoi_array(list, t_stack->size);
		t_stack->arr = find_index(arr, t_stack->size);
		free_list(list);
	}
	else
	{
		t_stack->size = (ac - 1);
		t_stack->arr = (int *)malloc(sizeof(int) * t_stack->size);
		fill_with_zeroes(t_stack->arr, t_stack->size);
		arr = ft_atoi_array(av, t_stack->size);
		t_stack->arr = find_index(arr, t_stack->size);
	}
}

void	initialize_t_stack(int ac, char **av, char flag, t_stack *a, t_stack *b)
{
	if (flag == 'a')
	{
		a->name = 'a';
		if (ac == 2)
			split_and_t_stack(ac, av, a, 2);
		else
			split_and_t_stack(ac, av, a, 3);
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
