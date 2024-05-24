/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/24 15:38:53 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decision(numnode **stack_a)
{
	getindex(stack_a);
	showindex(stack_a);
	if (countelements(*stack_a) <= 5)
	{
		if (sorted(stack_a) == 0)
			// hardcodeme();
		ft_printf("Less or equal than 5\n");
		// sa(stack_a);
		// rra(stack_a);
		printnums(*stack_a);
	}
	else
	{
		if (sorted(stack_a) == 0)
			// ft_radix();
		ft_printf("More than 5\n");
		// sa(stack_a);
		printnums(*stack_a);
	}
}

int	main(int ac, char **av)
{
	numnode		*stack_a;
	/* numnode		*stack_b; */
	char		**spliter;

	stack_a = (void *)0;
	/* stack_b = (void *)0; */
	if (ac == 2)
	{
		spliter = ft_split(av[1], ' ');
		get_numbers(&stack_a, spliter);
		freeme(spliter);
	}
	else if (ac > 2)
		get_numbers(&stack_a, &av[1]);
	else
		return (ft_printf("Error\n"), 1);
	if (repeated(stack_a) == 1)
		decision(&stack_a);
	else
		return (cleaner(&stack_a), 1);
	return (cleaner(&stack_a), 0);
}

// printnums(stack_a);

// 4 5 6 7 0 1 2 3 4 5 6

// system("leaks push_swap");
