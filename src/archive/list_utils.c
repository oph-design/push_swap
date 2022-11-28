/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:43:50 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/28 13:33:40 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	conv_content(t_list *node)
{
	int	*conv;

	conv = node->content;
	return (*conv);
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

long	*strltoval(int argc, char **stacka)
{
	size_t	i;
	long	*res;

	i = 0;
	res = ft_calloc(argc, sizeof(long));
	while (i < (size_t)(argc - 1))
	{
		stacka++;
		res[i] = ft_atoi(*stacka);
		i++;
	}
	return (res);
}

t_list	*convert_input(int argc, char **stacka)
{
	t_list	*res;
	long	*vals;
	size_t	i;

	vals = strltoval(argc, stacka);
	res = ft_lstnew(vals);
	i = 0;
	while (i < (argc - 2))
		ft_lstadd_back(&res, ft_lstnew(vals[i++]));
	return (free(vals), res);
}