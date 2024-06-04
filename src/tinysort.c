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
    t_nnode *tmp;

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

static void fivesort(t_nnode **stack_a, t_nnode **stack_b)
{
    t_nnode *tmp;
    t_nnode *next_node;
    t_nnode *insert_node;

    tmp = *stack_a;
    while (tmp && tmp->next)
    {
        if (tmp->next->index == 1 || tmp->next->index == 2)
            next_node = tmp->next, tmp->next = next_node->next, 
            	next_node->next = *stack_b, *stack_b = next_node;
        else
            tmp = tmp->next;
    }
    if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
        next_node = *stack_a, *stack_a = next_node->next, 
        	next_node->next = *stack_b, *stack_b = next_node;
    threesort(stack_a);
    if (sorted(stack_b) == 1)
        sa(stack_b);
    while (*stack_b)
        insert_node = *stack_b, *stack_b = (*stack_b)->next, 
        	insert_node->next = *stack_a, *stack_a = insert_node;
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