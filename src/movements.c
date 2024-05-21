/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:27 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/21 18:01:39 by jleon-la         ###   ########.fr       */
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

// void    pa(numnode **stack_a, numnode **stack_b)
// {
//     numnode *node;

//     if (countelements(*stack_b) <= 0)
//         return ;
//     node = *stack_b;
//     node->next = *stack_a;
//     *stack_a = node;
// }

void    ra(numnode **stack_a)
{
    numnode *node;
    numnode *tmp;

    if (countelements(*stack_a) <= 1)
        return ;
    node = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp = *stack_a;
    while (tmp->next != (void *)0)
        tmp = tmp->next;
    tmp->next = node;
    node->next = (void *)0;
}

void    rra(numnode **stack_a)
{
    numnode *node;
    numnode *tmp;

    if (countelements(*stack_a) <= 1)
        return ;
    node = *stack_a;
    while ((*stack_a)->next->next != (void *)0)
        *stack_a = (*stack_a)->next;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_a)->next = node;
    tmp->next = (void *)0;
}
