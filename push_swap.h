/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/14 12:52:07 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct stack 
{
	int	size;
	int	*arr;
} stack;

//libft
int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);

//utils
stack	initialize_stack_a(int argc, char **argv);
stack	initialize_stack_b();
void	clean_stack(stack a);
void	copy_arr_until(int *src, int *dst, int n);
int		find_max(int *a, int size);
int		find_min(int *a, int size);
int		find_middle(int *a, int size);
int		abs(int a);
void	print_arr(int *a, int size); //sil

//operations
void	s(stack *a);
void	ss(stack *a, stack *b);
void	p(stack *a, stack *b);

#endif