/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:15:51 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 14:47:10 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_nnode
{
	long			num;
	long			index;
	struct	s_nnode	*next;
	struct	s_nnode	*prev;
}			t_nnode;

long		ft_atol(const char *str);
void		freeme(char **spliter);
void		cleaner(t_nnode **lst);
void		get_numbers(t_nnode **stack_a, char **numarr);
void		chargelongs(t_nnode **stack_a, long *count, long size);
void		printnums(t_nnode *stack_a);
long		countelements(t_nnode *stack_a);
void		decision(t_nnode **stack_a, t_nnode **stack_b);
long		repeated(t_nnode *stack_a);
long		sorted(t_nnode **stack_a);
void		thinkit(t_nnode *copy, t_nnode *baton, long *max, long *i);
void		getindex(t_nnode **stack_a);
void    	showindex(t_nnode **stack_a);
void    	radix(t_nnode **stack_a, t_nnode **stack_b, long bits);
void		sa(t_nnode **stack_a);
void		ra(t_nnode **stack_a);
void		rra(t_nnode **stack_a);
void    	pa(t_nnode **stack_a, t_nnode **stack_b);
void    	pb(t_nnode **stack_a, t_nnode **stack_b);
void    	hardcodeme(t_nnode **stack_a, t_nnode **stack_b);

#endif
