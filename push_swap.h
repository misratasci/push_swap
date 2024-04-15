/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/15 23:12:08 by mitasci          ###   ########.fr       */
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
}	t_stack;

//libft
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);

//checks
void	ft_checks(char **t_stack, int arg_size);

//stack_init
t_stack	initialize_stack_a(int argc, char **argv);
t_stack	initialize_stack_b(t_stack a);
void	clean_stacks(t_stack *a, t_stack *b);

//utils
void	fill_with_zeroes(int *a, int size);
int		listlen(char **l);
void	free_list(char **l);
void	copy_arr_until(int *dst, int *src, int n);
int		count_digits(int a);
int		find_min(int *a, int size);
int		find_max(int *a, int size);
int		find_ind(int *a, int size, int value);
int		find_next_min(int *a, int size, int prev_min);
int		is_sorted_dec(int *a, int size);

//sort_basic
void	sort_3_inc(t_stack *a);
void	sort_5_inc(t_stack *a, t_stack *b);

//operations
void	s(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	p(t_stack *a, t_stack *b);
void	r(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	revr(t_stack *a);
void	revrr(t_stack *a, t_stack *b);
void	r_n(t_stack *a, int n);
void	revr_n(t_stack *a, int n);

//sort
void	sort(t_stack *a, t_stack *b);
int		get_digit(int a, int digit);

//main
void	ft_error(void);
void	print_stacks(t_stack a, t_stack b); //sil

#endif