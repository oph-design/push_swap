/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:43:50 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/26 10:57:35 by oheinzel         ###   ########.fr       */
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
		ft_printf("%d\n", conv_content(ls));
		ls = ls->next;
	}
	ft_printf("---\n");
}

long	*acatoip(int argc, char **stacka)
{
	size_t	i;
	long	*res;

	i = 0;
	res = ft_calloc(argc - 1, sizeof(int));
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
	int		*vals;

	vals = acatoip(argc, stacka);
	res = ft_lstnew(vals);
	argc -= 2;
	while (argc--)
		ft_lstadd_back(&res, ft_lstnew(++vals));
	return (res);
}
