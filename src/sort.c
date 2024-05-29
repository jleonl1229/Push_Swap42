/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:05 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/29 18:54:42 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    thinkit(numnode *copy, numnode *baton, long *max, long *i)
{
    while (copy)
    {
        if (copy->num < *max && copy->index == 0)
        {
            *max = copy->num;
            baton = copy;
        }
        copy = copy->next;
    }
    if (baton != (void *)0) 
        baton->index = *i;
}

void    getindex(numnode **stack_a)
{
    long    els;
    long    i;
    long    max;
    numnode *copy;
    numnode *baton;

    els = countelements(*stack_a);
    i = 1;
    while (i <= els)
    {
        max = LONG_MAX;
        copy = *stack_a;
        baton = (void *)0;
        thinkit(copy, baton, &max, &i);
        i++;
    }
}

void    showindex(numnode **stack_a)
{
    numnode *copy;

    copy = *stack_a;
    if (*stack_a != (void *)0)
    {
        while (copy != (void *)0)
        {
            ft_printf("Index: %l\n", copy->index);
            copy = copy->next;
        }
    }
}

long    sorted(numnode **stack_a)
{
    numnode *copy;

    copy = *stack_a;
    if (copy)
    {
        while (copy && copy->next)
        {
            if (copy->index > copy->next->index)
                return (0);
            copy = copy->next;
        }
    }
    return (ft_printf("Already sorted\n"), exit(1), 1);
}

void    radix(numnode **stack_a, numnode **stack_b, long bits)
{
    long    els;

    if (sorted(stack_a) == 0)
            return ;
    els = countelements(*stack_a);
    while (--els >= 0)
    {
        if (((*stack_a)->index >> bits) & 1)
            ra(stack_a);
        else
            pb(stack_a, stack_b);
    }
    while (*stack_b)
        pa(stack_a, stack_b);
    radix(stack_a, stack_b, ++bits);
}
