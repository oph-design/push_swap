/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:55 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/06 16:26:30 by oheinzel         ###   ########.fr       */
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