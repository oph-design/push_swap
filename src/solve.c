/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/06 08:37:42 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_list **a, t_list **b, int argc)
{
	unsigned int	badge_num;
	t_list			**badges;

	badge_num = 1;
	if (argc > 10)
		badge_num = 0.013 * argc + 3.75;
	badges = get_badges(*a, badge_num, argc);
	while (*badges != NULL)
	{
		print_list(*badges);
		badges++;
	}
	*b = ft_lstnew((*a)->content);
}
