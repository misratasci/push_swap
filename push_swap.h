/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 17:45:29 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char	name;
	int		size;
	int		*arr;
	int		*index;
	int		pivot;
	int		capacity;
}	t_stack;

//libft
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//checks
int		num_valid(char *a);
int		is_num(char *a);
int		check_for_dups(int *a, int size);

//stack_init
t_stack	initialize_stack_a(int argc, char **argv, int capacity);
t_stack	initialize_stack_b(t_stack a, int capacity);
void	clean_stack(t_stack *a);

//utils
void	fill_with_zeroes(int *a, int size);
int		listlen(char **l);
void	free_list(char **l);
void	copy_arr_until(int *dst, int *src, int n);
int		check_if_sorted(int *a, int size);
int		count_digits(int a);
int		find_min(int *a, int size);
int		find_max(int *a, int size);
int		find_ind(int *a, int size, int value);
int		find_next_min(int *a, int size, int prev_min);

//sort_basic
void	sort_3_inc(t_stack *a);
void	sort_5_inc(t_stack *a, t_stack *b);

void	print_arr(int *a, int size); //sil
void	print_stacks(t_stack a, t_stack b); //sil

//operations
void	s(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	p(t_stack *a, t_stack *b);
void	r(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	revr(t_stack *a);
void	revrr(t_stack *a, t_stack *b);

//sort
void	sort(t_stack *a, t_stack *b);
int		get_digit(int a, int digit);

#endif