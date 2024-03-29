/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:45:00 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//uses ft_split on every content in an array
//all resulting strings get added to a list
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

//creates stack a by initializing a list with argv
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

//checks if the current string is a valid number
static int	check_digit(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !(*str))
		return (1);
	if (!ft_isdigit(str[i]) && str[i] != '-')
		return (1);
	if (str[i] == '-' && !ft_isdigit(str[++i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	return (0);
}

//frees the list properly after an error
static void	free_helper(t_list **tmp, t_list **prev, t_list **stack)
{
	if (*tmp == *prev)
		*stack = NULL;
	ft_lstclear(tmp, free);
	(*prev)->next = NULL;
}

//finds non integer values in a list
//converts the list contents to integer
int	check_nbr(t_list **stack)
{
	size_t	i;
	char	*str;
	long	val;
	t_list	*tmp;
	t_list	*prev;

	tmp = (*stack);
	prev = tmp;
	i = 0;
	while (tmp != NULL)
	{
		str = (char *)(tmp->content);
		if (check_digit(str))
			return (free_helper(&tmp, &prev, stack), 1);
		val = ft_atol(str);
		if (val < INT_MIN || val > INT_MAX)
			return (free_helper(&tmp, &prev, stack), 1);
		tmp->content = (void *)val;
		prev = tmp;
		tmp = tmp->next;
		free(str);
		i = 0;
	}
	return (0);
}
