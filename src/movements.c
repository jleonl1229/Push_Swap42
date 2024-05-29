/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:27 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/29 17:58:41 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(numnode **stack_a)
{
    numnode *node;

    if (countelements(*stack_a) <= 1)
        return ;
    node = *stack_a;
    *stack_a = (*stack_a)->next;
    node->next = (*stack_a)->next;
    (*stack_a)->next = node;
}

// void    sb(numnode **stack_b)
// {
//     numnode *node;

//     if (countelements(*stack_b) <= 1)
//         return ;
//     node = *stack_b;
//     *stack_b = (*stack_b)->next;
//     node->next = (*stack_b)->next;
//     (*stack_b)->next = node;
// }

// void    ss(numnode **stack_a, numnode **stack_b)
// {
//     sa(stack_a);
//     sb(stack_b);
// }

void    pa(numnode **stack_a, numnode **stack_b)
{
    numnode *node;

    if (countelements(*stack_b) <= 0)
        return ;
    node = *stack_b;
    *stack_b = (*stack_b)->next;
    node->next = *stack_a;
    *stack_a = node;
}   

void    pb(numnode **stack_a, numnode **stack_b)
{
    numnode *node;

    if (countelements(*stack_a) <= 0)
        return ;
    node = *stack_a;
    *stack_a = (*stack_a)->next;
    node->next = *stack_b;
    *stack_b = node;
}
