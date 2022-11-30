/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/30 17:29:20 by oheinzel         ###   ########.fr       */
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

	i = 1;
	res = NULL;
	while (i++ < (argc - 1))
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
		i = 0;
		while (str[i])
		{
			if ((!ft_isdigit(str[0]) && str[0] != '-')
				|| (!ft_isdigit(str[i++]) && i != 0))
				return (1);
		}
		val = ft_atoi(str);
		if (val < INT_MIN || val > INT_MAX)
			return (1);
		tmp->content = (void *)val;
                free(str);
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
