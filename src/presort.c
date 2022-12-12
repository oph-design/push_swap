/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:25:47 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/12 14:53:37 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(t_list *stack, t_list *batch)
{
	if (!stack)
		return (1);
	while (batch != NULL)
	{
		if ((int)(stack->content) == (int)(batch->content))
			return (1);
		batch = batch->next;
	}
	return (0);
}

void	presort(t_list **a, t_list **b, t_list *batch, int *stats)
{
	size_t			i;
	int				j;
	t_list			*tmp;
	static int		check = 0;

	j = 0;
	tmp = *a;
	i = stats[2];
	if (check == (stats[1] - 1))
		i = stats[3];
	while (i)
	{
		while (!compare(tmp, batch) && ++j)
			tmp = (tmp)->next;
		rotate_batch(a, j, stats[0], 'a');
		push(a, b, 'b');
		tmp = *a;
		j = 0;
		stats[0]--;
		i--;
	}
	check++;
}
