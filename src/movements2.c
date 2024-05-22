/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:20:27 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/22 12:22:05 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void    rb(numnode **stack_b)
// {
//     numnode *node;
//     numnode *tmp;

//     if (countelements(*stack_b) <= 1)
//         return ;
//     node = *stack_b;
//     *stack_b = (*stack_b)->next;
//     tmp = *stack_b;
//     while (tmp->next != (void *)0)
//         tmp = tmp->next;
//     tmp->next = node;
//     node->next = (void *)0;
// }

// void    rr(numnode **stack_a, numnode **stack_b)
// {
//     ra(stack_a);
//     rb(stack_b);
// }

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

// void    rrb(numnode **stack_b)
// {
//     numnode *node;
//     numnode *tmp;

//     if (countelements(*stack_b) <= 1)
//         return ;
//     node = *stack_b;
//     while ((*stack_b)->next->next != (void *)0)
//         *stack_b = (*stack_b)->next;
//     tmp = *stack_b;
//     *stack_b = (*stack_b)->next;
//     (*stack_b)->next = node;
//     tmp->next = (void *)0;
// }
