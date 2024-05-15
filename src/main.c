/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/15 11:20:53 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleaner(numnode **lst)
{
	numnode	*check;

	if (lst != (void *)0)
	{
		while (*lst != (void *)0)
		{
			check = (*lst)->next;
			free(*lst);
			*lst = check;
		}
	}
}

void	printnums(numnode *stack_a)
{
	if (stack_a != (void *)0)
	{
		while (stack_a != (void *)0)
		{
			ft_printf("Num of the node: %l\n", stack_a->num);
			stack_a = stack_a->next;
		}
	}
}

void	chargelongs(numnode **stack_a, long *count, long size)
{
	long	i;
	numnode	*last;
	numnode	*new;

	i = 0;
	last = (void *)0;
	while (i < size)
	{
		new = malloc(sizeof(numnode) * 1);
		if (!new)
			return ;
		new->num = count[i];
		new->next = (void *)0;
		if (last == (void *)0)
			*stack_a = new;
		else
			last->next = new;
		last = new;
		i++;
	}
	free(count);
}

void	get_numbers(numnode **stack_a, char **numarr)
{
	long	i;
	long	ii;
	long	*count;

	i = 0;
	ii = 0;
	if (!numarr[i] || !stack_a)
		return ;
	while (numarr[i] != (void *)0)
		i++;
	count = (long *)malloc(sizeof(long) * i);
	if (!count)
		return ;
	while (ii < i)
	{
		count[ii] = ft_atol(numarr[ii]);
		ii++;
	}
	chargelongs(stack_a, count, i);
}

void freeme(char **spliter)
{
	long	i;

	i = 0;
	if (!spliter)
		return ;
	while (spliter[i] != (void *)0)
	{
		free(spliter[i]);
		i++;
	}
	free(spliter);
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
		return (1);
	printnums(stack_a);
	return (cleaner(&stack_a), 0);
}

// static void	hollow(void *node)
// {
// 	if (node)
// 		return ;
// 	else
// 		return ;
// }

// 4 5 6 7 0 1 2 3 4 5 6

// system("leaks push_swap");
