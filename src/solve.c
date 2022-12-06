/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/06 13:38:57 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_ps(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		free(*lst);
		return ;
	}
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	compare(t_list *stack, t_list *badge)
{
	while (badge != NULL)
	{
		if ((int)stack->content == (int)badge->content)
			return (1);
		badge = badge->next;
	}
}

void	presort(t_list **a, t_list **b, t_list *badges, unsigned int *badge)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < badge[2])
	{
		while (!compare(*a, badges) && j++)
			*a = (*a)->next;
		if (j > (badge[0] / 2))
		{
			j = badge[0] - j;
			while (j--)
				rrotate(a, 'a');
		}
		else
		{
			while (j--)
				rotate(a, 'a');
		}
		push(a, b, 'b');
		j = 0;
		i++;
	}
}

void	solve(t_list **a, t_list **b, int argc)
{
	unsigned int	badge[3];
	t_list			**badges;
	size_t			i;

	badge[0] = (unsigned int)argc;
	badge[1] = 1;
	if (argc > 10)
		badge_num = 0.013 * argc + 3.75;
	badge[2] = badge[0] / badge[1];
	badges = get_badges(*a, badge[1], badge[0]);
	i = 0;
	while (badges[i] != NULL)
		presort(a, b, badges[i++], badge);
	i = 0;
	while (badges[i] != NULL)
		ft_lstclear_ps(badges[i++]);
}
