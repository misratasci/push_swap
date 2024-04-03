/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/03 13:11:53 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack 
{
	char	name;
	int		size;
	int		*arr;
	int		*index;
	int		pivot;
	int		capacity;
} stack;

//libft
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

//utils
stack	initialize_stack_a(int argc, char **argv, int capacity);
stack	initialize_stack_b(stack a, int capacity);
void	clean_stack(stack a);
void	copy_arr_until(int *dst, int *src, int n);
int		find_max(int *a, int size);
int		find_min(int *a, int size);
//int		find_middle(int *a, int size);
int		find_next_min(int *a, int size, int prev_min);
int		find_next_max(int *a, int size, int prev_max);
int		find_ind(int *a, int size, int value);
int		count_val(int *arr, int size, int val);
int		arr_sum(int *arr, int size);
int		all_els_eq(int *arr, int size);
int		all_els_neg(int *arr, int size);
void	sort_3_inc(stack *a);
void	sort_3_dec(stack *a);
void	sort_3_inc_dig(stack *a, int digit);
void	sort_3_dec_dig(stack *a, int digit);
void	print_arr(int *a, int size); //sil
void	print_stacks(stack a, stack b); //sil

//operations
void	s(stack *a);
void	ss(stack *a, stack *b);
void	p(stack *a, stack *b);
void	r(stack *a);
void	rr(stack *a, stack *b);
void	revr(stack *a);
void	revrr(stack *a, stack *b);
int		min(int a, int b);
int		max(int a, int b);
int		abs(int a);
int		distance(int val1, int val2, int *a, int size);
int		ind_distance(int ind1, int ind2, int size);
void	r_sim(stack *a);
void	revr_sim(stack *a);

//operations sim
void	s_sim(stack *a);
void	ss_sim(stack *a, stack *b);
void	p_sim(stack *a, stack *b);
void	r_sim(stack *a);
void	rr_sim(stack *a, stack *b);
void	revr_sim(stack *a);
void	revrr_sim(stack *a, stack *b);

//sort
void	sort(stack *a, stack *b);
int 	get_digit(int a, int digit);
int		*get_digit_arr(stack a, int digit);

//main
void	merge_stacks(stack *a, stack *b);

#endif