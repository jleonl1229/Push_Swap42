/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:05 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/22 12:47:15 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    sorted(numnode **stack_a)
{
    if (*stack_a)
    {
        while (*stack_a)
        {
            if ((*stack_a)->num > (*stack_a)->next->num)
                return (0);
            *stack_a = (*stack_a)->next;
        }
    }
    return (1);
}

void    radix(numnode **stack_a, numnode **stack_b)
{
    long    i;

    i = 7;
    
}