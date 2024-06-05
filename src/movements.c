/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:27 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 17:50:56 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_nnode **stack_a)
{
	t_nnode	*node;

	if (countelements(*stack_a) <= 1)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = (*stack_a)->next;
	(*stack_a)->next = node;
	ft_printf("sa\n");
}

void	rra(t_nnode **stack_a)
{
	t_nnode	*node;
	t_nnode	*tmp;

	if (countelements(*stack_a) <= 1)
		return ;
	node = *stack_a;
	while ((*stack_a)->next->next != (void *)0)
		*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = node;
	tmp->next = (void *)0;
	ft_printf("rra\n");
}

void	ra(t_nnode **stack_a)
{
	t_nnode	*node;
	t_nnode	*tmp;

	if (countelements(*stack_a) <= 1)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp = *stack_a;
	while (tmp->next != (void *)0)
		tmp = tmp->next;
	tmp->next = node;
	node->next = (void *)0;
	ft_printf("ra\n");
}

void	pa(t_nnode **stack_a, t_nnode **stack_b)
{
	t_nnode	*node;

	if (countelements(*stack_b) <= 0)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	ft_printf("pa\n");
}

void	pb(t_nnode **stack_a, t_nnode **stack_b)
{
	t_nnode	*node;

	if (countelements(*stack_a) <= 0)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	ft_printf("pb\n");
}
