/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/09 17:00:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_str(char *str, t_list **res)
{
	size_t	i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	if (*res == NULL)
		*res = ft_lstnew(split[i++]);
	while (split[i] != NULL)
		ft_lstadd_back(res, ft_lstnew(split[i++]));
	free(split);
}

t_list	*convert(int argc, char **argv)
{
	size_t	i;
	t_list	*res;

	i = 0;
	res = NULL;
	while (i++ < (size_t)(argc - 1))
		split_str(argv[i], &res);
	return (res);
}

int	check_nbr(t_list **stack)
{
	size_t	i;
	char	*str;
	long	val;
	t_list	*tmp;

	tmp = (*stack);
	i = 0;
	while (tmp != NULL)
	{
		str = (char *)(tmp->content);
		while (str[i])
		{
			if ((!ft_isdigit(str[0]) && str[0] != '-')
				|| (!ft_isdigit(str[i++]) && i != 0))
				return (1);
		}
		val = ft_atol(str);
		if (val < INT_MIN || val > INT_MAX)
			return (1);
		tmp->content = (void *)val;
		tmp = tmp->next;
		free(str);
		i = 0;
	}
	return (0);
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
