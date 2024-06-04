/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:14 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 12:49:58 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void foursort(numnode **stack_a)
// {
//     // if (stack_a)
//     //     return ;
//     long first = (*stack_a)->index;
//     long second = (*stack_a)->next->index;
//     long third = (*stack_a)->next->next->index;
//     long fourth = (*stack_a)->next->next->next->index;

//     if (first > second)
// 		sa(stack_a);
//     if (second > third)
// 		sa(stack_a), ra(stack_a), sa(stack_a), rra(stack_a);
//     if (third > fourth)
// 		ra(stack_a), sa(stack_a), rra(stack_a);
//     if (sorted(stack_a) == 0)
// 		ra(stack_a), ra(stack_a), sa(stack_a), rra(stack_a), rra(stack_a);
// 	else
// 		foursort(stack_a);
// }

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
		sa(stack_a), threesort(stack_a);
}

static void foursort(numnode **stack_a, numnode **stack_b)
{
    numnode *tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->next->index == 1)
		{
			*stack_b = tmp->next;
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
	(*stack_b)->next = (void *)0;
	threesort(stack_a);
	pa(stack_a, stack_b);
}

static void fivesort(numnode **stack_a)
{
    if (stack_a)
        return ;
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
        foursort(stack_a, stack_b);
    else if (countelements(*stack_a) == 5)
        fivesort(stack_a);
}