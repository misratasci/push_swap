/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:51 by mitasci           #+#    #+#             */
/*   Updated: 2024/03/12 19:49:40 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct stack 
{
	int	size;
	int	*stack;
	int	top;
} stack;

int		ft_atoi(const char *str);
stack	initialize_stack(int argc, char **argv);

