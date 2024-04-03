/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 00:16:47 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_valid(char *a)
{
	size_t	len;
	
	len = ft_strlen(a);
	//printf("a: %s, len: %zu, cmp: %d\n", a, len, ft_strncmp(a, "-2147483648", 11) > 0);
	if ((len > 10 && a[0] != '-') || (a[0] == '-' && len > 11))
		return (0);
	if (len == 10 && a[0] != '-' && ft_strncmp(a, "2147483647", 10) > 0)
		return (0);
	if (len == 11 && a[0] == '-' && ft_strncmp(a, "-2147483648", 11) > 0)
		return (0);
	return (1);
}

static int	is_num(char *a)
{
	int	i;

	i = 0;
	if (a[0] == '-')
		i++;
	while (a[i])
	{
		if (!ft_isdigit(a[i]))
			return (0);
		i++;
	}
	return (1);
}


static int	check_for_dups(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			//printf("a[%d]: %d, a[%d]: %d\n", i, a[i], j, a[j]);
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_with_zeroes(int *a, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		a[i] = 0;
}

static int	*sorted_init(stack *a)
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
}

static void	index_init(stack *a)
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
}

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

void sortArray(int* array, int size) {
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

int* findRanks(int* array, int size) {
    // Clone the original array.
    int* clonedArray = (int*)malloc(size * sizeof(int));
    int* rankArray = (int*)malloc(size * sizeof(int));
    int i = 0, j;
    
    while (i < size) {
        clonedArray[i] = array[i];
        i++;
    }

    sortArray(clonedArray, size);
    i = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            if (array[i] == clonedArray[j]) {
                rankArray[i] = j;
                break; // Found the rank, no need to continue inner loop.
            }
            j++;
        }
        i++;
    }
    free(clonedArray);

    return rankArray;
}

int *ft_atoi_array(list, size)
{
	int i;
	int *arr;
	
	i = -1;
	arr = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		arr[i] = ft_atoi(list[i]);
	return (arr);
}

int *ft_index_the_list(char **list, int size)
{
	int** arr = ft_atoi_array(list, size);
	
}

void	split_and_stack(char *av, stack *stack)
{
	char	**list;
	char	*tmp;
	
	list = ft_split(av, ' ');
	if (!list)
		return ;
	stack->size = listlen(list);
	ft_checks(list, stack->size);
	stack->arr = (int *)malloc(sizeof(int) * stack->size);
	fill_with_zeroes(stack->arr, stack->size);
	stack->arr = ft_index_the_list(list, stack->size);
}


stack	initialize_stack_a(int argc, char **argv)
{
	stack	a;
	int		i;
	int		arr_valid;

	arr_valid = 1;
	a.name = 'a';
	a.capacity = argc - 1;
	if (argc == 2)
		split_and_stack(argv[1], &a);
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
	index_init(&a);
	a.pivot = a.size - 1;
	return (a);
}

stack	initialize_stack_b(stack a, int capacity)
{
	stack	b;
	
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