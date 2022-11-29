/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 16:51:23 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spcs(char *arg)
{
	while (*arg)
	{
		if (*arg == 32)
			return (1);
		arg++;
	}
	return (0);
}

static void	split_str(char *str, t_list **res)
{
	char	**split;

	split = ft_split(str, ' ');
	while (*split != NULL)
	{
		ft_lstadd_back(res, ft_lstnew(*split));
		split++;
	}
	//free(*split);
	//free(split);
}

t_list	*convert(int argc, char **argv)
{
	size_t	i;
	t_list	*res;

	i = 1;
	res = ft_lstnew(argv[i]);
	while (i++ < (argc - 1))
	{
		if (check_spcs(argv[i]))
			split_str(argv[i], &res);
		else
			ft_lstadd_back(&res, ft_lstnew(argv[i]));
	}
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
		i = 0;
		if (!ft_isdigit(str[i]) && str[i++] != '-')
			return (1);
		while (str[i])
		{
			if (!ft_isdigit(str[i++]))
				return (1);
		}
		val = ft_atoi(str);
		if (val < INT_MIN || val > INT_MAX)
			return (1);
		tmp->content = (void *)val;
		tmp = tmp->next;
	}
	return (0);
}

int	check_dups(t_list *stack)
{
	t_list	*tmp;
	int		*val;

	tmp = NULL;
	val = malloc(2 * sizeof(int));
	while (stack != NULL)
	{
		tmp = stack->next;
		val[0] = (int)stack->content;
		while (tmp != NULL)
		{
			val[1] = (int)(tmp->content);
			if (val[0] == val[1])
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	free(val);
	return (0);
}
