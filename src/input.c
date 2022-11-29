/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 19:20:12 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spcs(char *arg)
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
	size_t	i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	*res = ft_lstnew(split[i++]);
	while (split[i] != NULL)
		ft_lstadd_back(res, ft_lstnew(split[i++]));
	free(split);
}

t_list	*convert(int argc, char **argv)
{
	size_t	i;
	t_list	*res;

	i = 1;
	res = NULL;
	if (check_spcs(argv[i]))
		return (split_str(argv[i], &res), res);
	while (i++ < (argc - 1))
	{
		if (check_spcs(argv[i]))
			return (NULL);
		else
			ft_lstadd_back(&res, ft_lstnew(argv[i]));
	}
	return (res);
}

int	check_nbr(t_list **stack, int split)
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
		if (split)
			free(str);
		tmp->content = (void *)val;
		tmp = tmp->next;
	}
	return (0);
}

int	check_dups(t_list *stack)
{
	t_list	*tmp;
	long	*val;

	tmp = NULL;
	val = malloc(2 * sizeof(long));
	while (stack != NULL)
	{
		tmp = stack->next;
		val[0] = (long)stack->content;
		if (val[0] < INT_MIN || val[0] > INT_MAX)
			return (1);
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
