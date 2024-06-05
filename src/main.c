/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 18:01:58 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decision(t_nnode **stack_a, t_nnode **stack_b)
{
	getindex(stack_a);	
	if (countelements(*stack_a) <= 5)
	{
		if (sorted(stack_a) == 0)
			hardcodeme(stack_a, stack_b);
	}
	else
	{
		if (sorted(stack_a) == 0)
			radix(stack_a, stack_b, 0);
	}
}

int	main(int ac, char **av)
{
	t_nnode		*stack_a;
	t_nnode		*stack_b;
	char		**spliter;

	stack_a = (void *)0;
	stack_b = (void *)0;
	if (ac == 2)
	{
		spliter = ft_split(av[1], ' ');
		get_numbers(&stack_a, spliter, 2);
		freeme(spliter);
	}
	else if (ac > 2)
		get_numbers(&stack_a, &av[1], 0);
	else
		return (1);
	if (repeated(stack_a) == 1)
		decision(&stack_a, &stack_b);
	else
		return (cleaner(&stack_a), 1);
	return (cleaner(&stack_a), 0);
}
