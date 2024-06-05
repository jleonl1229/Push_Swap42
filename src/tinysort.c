/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:08:14 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 18:24:38 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void threesort(t_nnode **stack_a)
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

static void foursort(t_nnode **stack_a, t_nnode **stack_b)
{
	while ((*stack_a)->index != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	threesort(stack_a);
	pa(stack_a, stack_b);
}

static void fivesort(t_nnode **stack_a, t_nnode **stack_b)
{
    while ((*stack_a)->index != 1)
		ra(stack_a);
    pb(stack_a, stack_b);
    while ((*stack_a)->index != 2)
		ra(stack_a);
    pb(stack_a, stack_b);
    threesort(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void    hardcodeme(t_nnode **stack_a, t_nnode **stack_b)
{
    if (countelements(*stack_a) == 2)
        sa(stack_a);
    else if (countelements(*stack_a) == 3)
        threesort(stack_a);
    else if (countelements(*stack_a) == 4)
        foursort(stack_a, stack_b);
    else if (countelements(*stack_a) == 5)
        fivesort(stack_a, stack_b);
}