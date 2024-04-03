/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 01:11:20 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_with_zeroes(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		a[i] = 0;
}

/* static int	*sorted_init(stack *a)
{
	int curr_min;
	int	i;
	int	*sorted;
	
	sorted = (int*)malloc(sizeof(int) * a->size);
	curr_min = find_min(a->arr, a->size);
	sorted[0] = curr_min;
	i = 1;
	while (i < a->size)
	{
		sorted[i] = find_next_min(a->arr, a->size, sorted[i - 1]);
		i++;
	}
	return (sorted);
} */

/* static void	index_init(stack *a)
{
	int	i;
	int	*sorted;

	a->index = (int*)malloc(sizeof(int) * a->capacity);
	fill_with_zeroes(a->index, a->capacity);
	sorted = sorted_init(a);
	i = -1;
	while (++i < a->size)
		a->index[i] = find_ind(sorted, a->size, a->arr[i]);
	if (sorted)
		free(sorted);
} */

static int	listlen(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

static void	free_list(char **l)
{
	int	i;

	i = 0;
	if (!l)
		return ;
	while(l[i])
		free(l[i++]);
	free(l);
}

void fake_sort(int* array, int size)
{
    int i = 0, j, temp;
    while (i < size - 1) {
        j = i + 1;
        while (j < size) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int* find_index(int* array, int size)
{
    int* cloned_array = (int*)malloc(size * sizeof(int));
    int* rank_array = (int*)malloc(size * sizeof(int));
    int i = 0, j;
    
    while (i < size) {
        cloned_array[i] = array[i];
        i++;
    }
    fake_sort(cloned_array, size);
    i = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            if (array[i] == cloned_array[j]) {
                rank_array[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    free(cloned_array);
    return rank_array;
}

int *ft_atoi_array(char **list,int size)
{
	int i;
	int *arr;
	
	i = -1;
	list++;
	arr = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		arr[i] = ft_atoi(list[i]);
	return (arr);
}

void	split_and_stack(int ac, char **av, stack *stack, int label)
{
	char	**list;
	int		*arr;

	list = NULL;
	arr = NULL;
	if (label == 2)
	{
		list = ft_split(av[1], ' ');
		if (!list)
			return ;
		stack->size = listlen(list);
		ft_checks(list, stack->size);
		stack->arr = (int *)malloc(sizeof(int) * stack->size);
		fill_with_zeroes(stack->arr, stack->size);
		arr = ft_atoi_array(list, stack->size);
		stack->arr = find_index(arr, stack->size);
		stack->capacity = stack->size;
		free_list(list);
	}
	else
	{
		stack->size = (ac - 1);
		stack->arr = (int *)malloc(sizeof(int) * stack->size);
		fill_with_zeroes(stack->arr, stack->size);
		arr = ft_atoi_array(av, stack->size);
		stack->arr = find_index(arr, stack->size);
		stack->capacity = stack->size;
	}
}

void	index_init(stack *a)
{
	int	i;
	
	a->index = (int*)malloc(sizeof(int) * a->capacity);
	fill_with_zeroes(a->index, a->capacity);
	i = -1;
	while (++i < a->size)
	{
		a->index[i] = a->arr[i];
	}
}

stack	initialize_stack_a(int ac, char **av)
{
	stack	a;

	a.name = 'a';
	if (ac == 2)
		split_and_stack(ac, av,&a, 2);
	else
		split_and_stack(ac, av, &a, 3);
	index_init(&a);
	a.pivot = a.size - 1;
	return (a);
}

stack	initialize_stack_b(stack a)
{
	stack	b;
	
	b.name = 'b';
	b.capacity = a.capacity;
	b.size = 0;
	b.arr = (int *)malloc(sizeof(int) * b.capacity);
	fill_with_zeroes(b.arr, b.capacity);
	b.index = (int *)malloc(sizeof(int) * b.capacity);
	fill_with_zeroes(b.index, b.capacity);
	b.pivot = a.pivot / 2;
	return (b);
}

void	clean_stack(stack *a)
{
	if (a->arr)
		free(a->arr);
	if (a->index)
		free(a->index);
}

void	copy_arr_until(int *dst, int *src, int n)
{
	int		i;

	if (!dst || !src)
		return ;
	if (dst <= src)
	{
		i = -1;
		while (++i < n)
			dst[i] = src[i];
	}
	if (dst > src)
	{
		i = n;
		while (i-- > 0)
			dst[i] = src[i];
	}
}

int	check_if_sorted(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (1);
}

int	count_digits(int a)
{
	int res;
	
	res = 0;
	while (a != 0)
	{
		a /= 10;
		res++;
	}
	return (res);
}

void	print_arr(int *a, int size) //bunu sonradan sil
{
	int i = -1;
	printf("{");
	while (++i < size)
		printf("%d, ", a[i]);
	printf("}\n");
}

void	print_stacks(stack a, stack b) //bunu da sil
{
	printf("Stack A:\n");
	//print_arr(a.arr, a.size);
	print_arr(a.index, a.size);
	printf("Stack B:\n");
	//print_arr(b.arr, b.size);
	print_arr(b.index, b.size);
}