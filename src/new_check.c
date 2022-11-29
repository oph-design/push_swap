/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:02:41 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 07:53:17 by oheinzel         ###   ########.fr       */
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
		if (val < INT_MIN || val > INT_MAX)
			return (1);
		(*stack)->content = &val;
		(*stack) = (*stack)->next;
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
