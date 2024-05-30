/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:14 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/30 10:41:53 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void threesort(numnode **stack_a)
{
    numnode *tmp;

    tmp = *stack_a;
    while (sorted(stack_a) == 0)
    {
        *stack_a = (*stack_a)->next;
        (*stack_a)->next = tmp;
        while (tmp->next->next->next != (void *)0)
            tmp = tmp->next;
        tmp->next = (void *)0;
    }
}

static void twosort(numnode **stack_a)
{
    numnode *tmp;

    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_a)->next = tmp;
    (*stack_a)->next->next = (void *)0;
}

void    hardcodeme(numnode **stack_a, numnode **stack_b)
{
    if (stack_b)
		ft_printf(":]>)\n");
    if (countelements(*stack_a) == 2)
        twosort(stack_a);
    else if (countelements(*stack_a) == 3)
        threesort(stack_a);
}