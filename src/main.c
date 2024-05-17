/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:55 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/17 11:16:19 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printnums(numnode *stack_a)
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

long	countelements(numnode *stack_a)
{
	long	i;
	numnode	*tmp;

	i = 0;
	tmp = stack_a;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	stack_a = tmp;
	return (i);
}

void	decision(numnode **stack_a)
{
	if (countelements(*stack_a) <= 5)
	{
		// hardcodeme();
		ft_printf("Less or eqal than 5 \n");
		// sa(stack_a);
		printnums(*stack_a);
	}
	else
	{
	// 	ft_radix();
		ft_printf("More than 5\n");
		// sa(stack_a);
		printnums(*stack_a);
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

static long	numcheck(char **num, long *i, long *ii)
{
	if (num[*i][*ii] == '-' || num[*i][*ii] == '+' || 
		(num[*i][*ii] >= '0' && num[*i][*ii] <= '9'))
	{
		(*ii)++;
		while (num[*i][*ii] >= '0' && num[*i][*ii] <= '9')
			(*ii)++;
		if (num[*i][*ii] != '\0')
			return (0);
	}
	exit(1);
}

long	ft_isnum(char **numarr)
{
	long	i;
	long	ii;

	i = 0;
	ii = 0;
	while (numarr[i])
	{
		ii = 0;
		while (numarr[i][ii])
		{
			if (numcheck(numarr, &i, &ii) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void	get_numbers(numnode **stack_a, char **numarr)
{
	long	i;
	long	ii;
	long	*count;

	i = 0;
	ii = 0;
	if (!numarr[i] || !stack_a || ft_isnum(numarr) == 0)
		exit(1);
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

long	repeated(numnode *stack_a)
{
	numnode	*tmp;
	long	i;

	tmp = stack_a;
	while (stack_a)
	{
		i = stack_a->num;
		tmp = stack_a->next;
		while (tmp)
		{
			if (tmp->num == i)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
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
	if (repeated(stack_a) == 1)
		decision(&stack_a);
	else
		return (cleaner(&stack_a), 1);
	return (cleaner(&stack_a), 0);
}

// printnums(stack_a);

// 4 5 6 7 0 1 2 3 4 5 6

// system("leaks push_swap");
