/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:14 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:32 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static long    tiny_sorted(numnode **stack_a)
// {
//     numnode *copy;

//     copy = *stack_a;
//     if (copy)
//     {
//         while (copy && copy->next)
//         {
//             if (copy->index > copy->next->index)
//                 return (0);
//             copy = copy->next;
//         }
//     }
//     return (1);
// }

static void fivesort(numnode **stack_a)
{
    if (stack_a)
        return ;
}

static void foursort(numnode **stack_a)
{
    if (stack_a)
        return ;
}

static void threesort(numnode **stack_a)
{
    long	first;
	long	second;
	long	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if ((first < second) && (second < third) && (first < third))
		return ;
	else if ((first > second) && (first > third) && (second < third))
		ra(stack_a);
	else if ((first < second) && (first > third) && (second > third))
		rra(stack_a);
    else
	{
		sa(stack_a);
		threesort(stack_a);
	}
}

void    hardcodeme(numnode **stack_a, numnode **stack_b)
{
    if (stack_b)
		ft_printf(":]>)\n");
    if (countelements(*stack_a) == 2)
        sa(stack_a);
    else if (countelements(*stack_a) == 3)
        threesort(stack_a);
    else if (countelements(*stack_a) == 4)
        foursort(stack_a);
    else if (countelements(*stack_a) == 5)
        fivesort(stack_a);
}