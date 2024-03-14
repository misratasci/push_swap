/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 16:16:31 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct stack 
{
	char	name;
	int		size;
	int		*arr;
	int		top;
} stack;

//libft
int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);

//utils
stack	initialize_stack_a(int argc, char **argv);
stack	initialize_stack_b();
void	clean_stack(stack a);
void	copy_arr_until(int *dst, int *src, int n);
int		find_max(int *a, int size);
int		find_min(int *a, int size);
int		find_middle(int *a, int size);
int		abs(int a);
int		find_min_ind(int *a, int size);
int		distance(int ind1, int ind2, int size);
void	print_arr(int *a, int size); //sil

//operations
void	s(stack *a);
void	ss(stack *a, stack *b);
void	p(stack *a, stack *b);
void	r(stack *a);
void	rr(stack *a, stack *b);
void	revr(stack *a);
void	revrr(stack *a, stack *b);

//main
void	split_stacks(stack *a, stack *b);

#endif