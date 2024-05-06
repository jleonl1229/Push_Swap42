/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/04/29 18:47:12 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void hollow(void *node)
{
	if (node)
		return ;
	else
		return ;
}

int	main(int ac, char **av)
{
	long		number;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		get_numbers(&stack_a, ft_split(av[1], ' '));
	else if (ac > 2)
		get_numbers(&stack_a, &av[1]);
	else
		return (1);
	return (ft_lstclear(&stack_a, hollow), 0);
}

// 4 5 6 7 0 1 2 3 4 5 6

// system("leaks push_swap");
