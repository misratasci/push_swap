/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/04/04 06:58:20 by mitasci          ###   ########.fr       */
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
	int		max_bit;
	int		*tmp_arr;
}	t_stack;

//libft_funcs
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//utils
int		abs(int a);
int		count_digits(int a);
int		check_if_sorted(int *a, int size);
int		find_ind(int *a, int size, int value);
void	copy_arr_until(int *dst, int *src, int n);

//utils2
void	ft_error(void);
int		listlen(char **l);
void	free_list(char **l);
void	ft_int_max(char *str);
void	clean_stack(t_stack *a, t_stack *b);
void	fill_with_zeroes(int *a, int size);

//checks
void	all_digit(char **t_stack, int arg_size);
void	int_limit(char **t_stack, int arg_size);
void	ft_checks(char **t_stack, int arg_size);
void	is_sorted(char **t_stack, int arg_size);
void	has_duplicates(char **t_stack, int arg_size);

//init_stack
void	initialize_stack(int ac, char **av, t_stack *a, t_stack *b);
void	fake_sort(int *array, int size);

//operations
void	s(t_stack *a);
void	r(t_stack *a);
void	p(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);

//operations2
void	revr(t_stack *a);
void	revrr(t_stack *a, t_stack *b);

//sort
void	max_bit_calculation(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
void	lil_sort(t_stack *a, t_stack *b);

#endif