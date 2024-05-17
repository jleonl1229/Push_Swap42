/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:22:26 by jleon-la          #+#    #+#             */
/*   Updated: 2024/05/17 13:33:04 by jleon-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}