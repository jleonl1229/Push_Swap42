/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleon-la <jleon-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:22:26 by jleon-la          #+#    #+#             */
/*   Updated: 2024/06/04 14:46:39 by jleon-la         ###   ########.fr       */
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

void	printnums(t_nnode *stack_a)
{
	t_nnode *copy;

    copy = stack_a;
	if (copy != (void *)0)
	{
		while (copy != (void *)0)
		{
			ft_printf("Num of the node: %l\n", copy->num);
			copy = copy->next;
		}	
	}
}

void	cleaner(t_nnode **lst)
{
	t_nnode	*check;

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

long	countelements(t_nnode *stack_a)
{
	long	i;
	t_nnode	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		i++;
		if (tmp->num < -2147483648 || tmp->num > 2147483647)
			ft_printf("Error\n"), exit(1);
		tmp = tmp->next;
	}
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
	if (str[0] == '\0')
		ft_printf("Error\n"), exit(1);
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i + 1] == '\0')
			ft_printf("Error\n"), exit(1);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num * sign);
}
