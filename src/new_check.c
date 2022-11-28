/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:02:41 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/28 16:04:08 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr(t_list **stack)
{
	size_t	i;
	char	*str;
	long	val;

	i = 0;
	while (*stack != NULL)
	{
		i = 0;
		str = (char *)((*stack)->content);
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (1);
		while (str[i])
		{
			if (!ft_isdigit(str[i++]))
				return (1);
		}
		val = ft_atoi(str);
		(*stack)->content = &val;
		(*stack) = (*stack)->next;
	}
	return (0);
}

static int	check_int(t_list *stack)
{
	long	*val;

	val = NULL;
	while (stack != NULL)
	{
		val = (long *)(stack->content);
		if (*val < INT_MIN || *val > INT_MAX)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	check_dups(t_list *stack)
{
	t_list	*tmp;
	long	*val;

	tmp = NULL;
	val = NULL;
	while (stack != NULL)
	{
		tmp = stack->next;
		val[0] = *((long *)(stack->content));
		while (tmp != NULL)
		{
			val[1] = *((long *)(tmp->content));
			if (val[0] == val [1])
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_condom(t_list **stack)
{
	if (check_nbr(stack))
		return (ft_putendl_fd("\033[0;31mERROR: NON DIGIT", 2), 1);
	if (check_int(*stack))
		return (ft_putendl_fd("\033[0;31mERROR: NON INTEGER", 2), 1);
	if (check_dups(*stack))
		return (ft_putendl_fd("\033[0;31mERROR: DUPLICATE", 2), 1);
	return (0);
}

void	print_list(t_list *ls)
{
	ft_printf("---\n");
	while (ls != NULL)
	{
		ft_printf("%d\n", *((long *)ls->content));
		ls = ls->next;
	}
	ft_printf("---\n");
}
