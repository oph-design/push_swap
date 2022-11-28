/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:46 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/28 15:58:41 by oheinzel         ###   ########.fr       */
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
	while (split != NULL)
	{
		ft_lstadd_back(res, ft_lstnew(*split));
		free(*split);
		split++;
	}
	free(*split);
	free(split);
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
