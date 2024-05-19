/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:27 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/17 18:29:27 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(numnode **stack_a)
{
    numnode *tmp;
    numnode *tmp2;

    if (!(*stack_a))
        return ;
    tmp = (void *)0;    
    tmp2 = (void *)0;
    if (countelements(*stack_a) <= 1)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp2 = *stack_a;
    *stack_a = tmp;
    *stack_a = (*stack_a)->prev;
    *stack_a = tmp2;
}
