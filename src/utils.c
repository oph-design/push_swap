/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:55 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/09 15:28:22 by oheinzel         ###   ########.fr       */
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

void	print_list(t_list *ls)
{
	static int	x;

	ft_printf("---%d---\n", x);
	while (ls != NULL)
	{
		ft_printf("%d\n", (int *)ls->content);
		ls = ls->next;
	}
	ft_printf("-----\n");
	x++;
}
