/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/29 19:06:07 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decision(numnode **stack_a, numnode **stack_b)
{
	if (stack_b)
		ft_printf(":]>)\n");
	getindex(stack_a);
	showindex(stack_a);	
	if (countelements(*stack_a) <= 5)
	{
		if (sorted(stack_a) == 0)
			// hardcodeme(stack_a, stack_b);
		ft_printf("Less or equal than 5\n");
		ra(stack_a);
		// pb(stack_a, stack_b);
		// pa(stack_a, stack_b);
		// sa(stack_a);
		// printnums(*stack_a);
		showindex(stack_a);
	}
	else
	{
		if (sorted(stack_a) == 0)
			radix(stack_a, stack_b, 0);
		ft_printf("More than 5\n");
		// ra(stack_a);
		// pb(stack_a, stack_b);
		// pb(stack_a, stack_b);
		// pa(stack_a, stack_b);
		// pa(stack_a, stack_b);
		// pa(stack_a, stack_b);
		// sa(stack_a);
		// ft_printf("A Stack\n");
		printnums(*stack_a);
		// ft_printf("B Stack\n");
		// printnums(*stack_b);
		showindex(stack_a);
	}
}

int	main(int ac, char **av)
{
	numnode		*stack_a;
	numnode		*stack_b;
	char		**spliter;

	stack_a = (void *)0;
	stack_b = (void *)0;
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
		decision(&stack_a, &stack_b);
	else
		return (cleaner(&stack_a), 1);
	return (cleaner(&stack_a), 0);
}

// printnums(stack_a);

// 4 5 6 7 0 1 2 3 4 5 6

// system("leaks push_swap");
