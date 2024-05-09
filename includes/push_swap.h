/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:15:51 by jleon-la          #+#    #+#             */
/*   Updated: 2024/04/29 17:49:56 by jleon-la         ###   ########.fr       */
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
	long	num;
	long	index;
	numnode	*next;
	numnode	*prev;
}		numnode;

long		ft_atol(const char *str);
static void	hollow(void *node);
void		getnumbers(numnode **stack_a, char **numarr);
void		chargelongs(numnode **stack_a, long *count);

#endif
