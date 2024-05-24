/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:15:51 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/24 15:33:21 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct numnode
{
	long			num;
	long			index;
	struct	numnode	*next;
	struct	numnode	*prev;
}			numnode;

long		ft_atol(const char *str);
void		freeme(char **spliter);
void		cleaner(numnode **lst);
void		get_numbers(numnode **stack_a, char **numarr);
void		chargelongs(numnode **stack_a, long *count, long size);
void		printnums(numnode *stack_a);
long		countelements(numnode *stack_a);
void		decision(numnode **stack_a);
long		repeated(numnode *stack_a);
long		sorted(numnode **stack_a);
void		getindex(numnode **stack_a);
void		sa(numnode **stack_a);
void		ra(numnode **stack_a);
void		rra(numnode **stack_a);

#endif
