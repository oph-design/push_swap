/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:55 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 11:34:02 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rm_val(t_list **stack, void	*content)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *stack;
	prev = tmp;
	if (((int)(tmp)->content) == (int)content)
	{
		prev = (tmp)->next;
		free(tmp);
		*stack = prev;
		return ;
	}
	tmp = (tmp)->next;
	while (tmp != NULL)
	{
		if (((int)(tmp)->content) == (int)content)
		{
			prev->next = (tmp)->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = (tmp)->next;
	}
}

long	ft_atol(const char *str)
{
	int		i;
	long	f;
	long	r;

	i = 0;
	f = 1;
	r = 0;
	if (str[i] == 0)
		return (0);
	if (ft_strlen(str) > 10)
		return (30000000000);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while ((47 < str[i]) && (str[i] < 58))
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (f * r);
}

void	rotate_batch(t_list **stack, int j, int args, char id)
{
	if (j == 1)
	{
		swap(stack, id);
		return ;
	}
	if (j > (args / 2))
	{
		j = args - j;
		while (j--)
			rrotate(stack, id);
		return ;
	}
	while (j--)
		rotate(stack, id);
}

int	check_dups(t_list *stack, int *argc)
{
	t_list	*tmp;
	int		val;
	int		comp;

	tmp = NULL;
	val = 0;
	comp = 0;
	while (stack != NULL)
	{
		tmp = stack->next;
		val = (int)stack->content;
		while (tmp != NULL)
		{
			comp = (int)(tmp->content);
			if (val == comp)
				return (1);
			tmp = tmp->next;
		}
		(*argc)++;
		stack = stack->next;
	}
	return (0);
}

void	lc(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
