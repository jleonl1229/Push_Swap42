/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameterer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:50:38 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/22 12:09:42 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (ft_printf("Error\n"), 0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
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
	while (num[*i][*ii] == ' ' || 
		(num[*i][*ii] >= 9 && num[*i][*ii] <= 13))
		(*ii)++;
	if (num[*i][*ii] == '-' || num[*i][*ii] == '+' || 
		(num[*i][*ii] >= '0' && num[*i][*ii] <= '9'))
	{
		(*ii)++;
		while (num[*i][*ii] >= '0' && num[*i][*ii] <= '9')
			(*ii)++;
		if (num[*i][*ii] == '\0')
			return (1);
	}
	return (0);
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
	{
		ft_printf("Error\n");
		exit(1);
	}
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
