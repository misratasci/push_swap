/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:25 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/01 17:53:18 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	listlen(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	free_list(char **l)
{
	int	i;

	i = 0;
	while(l[i])
		free(l[i++]);
	free(l);
}

static void	parse_arg(stack *a, char **argv)
{
	char	**list;
	int		i;

	list = ft_split(argv[1], ' ');
	a->size = listlen(list);
	a->arr = (int*)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		a->arr[i] = ft_atoi(list[i]);
	free_list(list);
}

static void	parse_args(stack *a, int argc, char **argv)
{
	int	i;
	
	a->size = argc - 1;
	a->arr = (int*)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		a->arr[i] = ft_atoi(argv[i + 1]);
}

static void	sorted_init(stack *a)
{
	int curr_min;
	int	i;

	a->sorted = (int*)malloc(sizeof(int) * a->size);
	i = 0;
	curr_min = find_min(a->arr, a->size);
	a->sorted[i] = curr_min;
	while (++i < a->size)
		a->sorted[i] = find_next_min(a->arr, a->size, a->sorted[i - 1]);
}

static void	index_init(stack *a)
{
	int	i;

	a->index = (int*)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		a->index[i] = find_ind(a->sorted, a->size, a->arr[i]);
}

stack	initialize_stack_a(int argc, char **argv)
{
	stack	a;

	a.name = 'a';
	if (argc == 2)
		parse_arg(&a, argv);
	else
		parse_args(&a, argc, argv);
	sorted_init(&a);
	index_init(&a);
	a.pivot = a.size - 1;
	return (a);
}

stack	initialize_stack_b(stack a)
{
	stack	b;
	
	b.name = 'b';
	b.size = 0;
	b.arr = NULL;
	b.sorted = NULL;
	b.index = NULL;
	b.pivot = a.pivot / 2;
	return (b);
}

void	clean_stack(stack a)
{
	if (a.arr)
		free(a.arr);
}

void	copy_arr_until(int *dst, int *src, int n)
{
	int		i;

	if (!dst && !src)
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