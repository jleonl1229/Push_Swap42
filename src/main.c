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

void	chargelongs(numnode **stack_a, long *count)
{
	long	i;

	i = 0;
	while (count[i])
	{
		stack_a = malloc(sizeof(numnode) * 1);
		stack_a->num = count[i];
		stack_a->next;
		i++;
	}
}

void	getnumbers(numnode **stack_a, char **numarr)
{
	long	i;
	long	ii;
	long	*count;

	i = 0;
	while (numarr[i] != (void *)0)
		i++;
	count = (long *)malloc(sizeof(long) * i + 1);
	ii = 0;
	while (numarr[ii] != (void *)0)
	{
		count[ii] = ft_atol(numarr[ii]);
		ii++;
	}
	count[ii] = (void *)0;
	if (!count)
		return (free(count), (void *)0);
	/* return (count); */
	chargelongs(&stack_a, count);
}

static void	hollow(void *node)
{
	if (node)
		return ;
	else
		return ;
}

int	main(int ac, char **av)
{
	numnode		*stack_a;
	numnode		*stack_b;

	stack_a = (void *)0;
	stack_b = (void *)0;
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
