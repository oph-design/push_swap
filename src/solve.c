/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:06 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rm_min(t_list **stack, void	*content)
{
	t_list	*tmp;

	tmp = *stack;
	if (((int)(*stack)->content) == (int)content)
	{
		tmp = (*stack)->next;
		ft_lstdelone(*stack, free);
		*stack = tmp;
		return ;
	}
	*stack = (*stack)->next;
	while (*stack != NULL)
	{
		if (((int)(*stack)->content) == (int)content)
		{
			tmp->next = (*stack)->next;
			ft_lstdelone(*stack, free);
			return ;
		}
		tmp = *stack;
		*stack = (*stack)->next;
	}
}

t_list	*min_value(t_list	**stack)
{
	t_list	*res;
	t_list	*tmp;

	tmp = *stack;
	res = tmp;
	while (tmp != NULL)
	{
		if ((int)tmp->content < (int)res->content)
			res = tmp;
		tmp = tmp->next;
	}
	rm_min(stack, res->content);
	return (ft_lstnew(res->content));
}

t_list	**get_badges(t_list *stack, unsigned int badge_num, int argc)
{
	t_list	**badges;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	badges = malloc((badge_num + 1) * sizeof(t_list));
	while (i < (size_t)badge_num)
	{
		badges[i] = min_value(&stack);
		while (j++ < (argc / badge_num))
			ft_lstadd_back(&badges[i], min_value(&stack));
		j = 0;
		i++;
	}
	badges[i] = NULL;
	return (badges);
}

void	solve(t_list **a, t_list **b, int argc)
{
	unsigned int	badge_num;
	t_list			**badges;

	badge_num = 1;
	if (argc > 10)
		badge_num = 0.013 * argc + 3.75;
	badges = get_badges(*a, badge_num, argc);
	while(*badges != NULL)
		print_list(*badges);
}
