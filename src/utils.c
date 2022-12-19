/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:55 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:54:22 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//removes a node with the same content as the given one
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

//returns a string of digits as a long number
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
	if (ft_strlen(str) > 11)
		return (3000000000);
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

//rotates a node from the given position to the top
void	rotate_batch(t_list **stack, int pos, int args, char id)
{
	if (pos == 1)
	{
		swap(stack, id);
		return ;
	}
	if (pos > (args / 2))
	{
		pos = args - pos;
		while (pos--)
			rrotate(stack, id);
		return ;
	}
	while (pos--)
		rotate(stack, id);
}

//checks a stack for duplicates
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

//clears a list completely
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
