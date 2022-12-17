/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:25:47 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/17 15:06:51 by oheinzel         ###   ########.fr       */
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

static void	sort_b(t_list **b)
{
	if (!(*b)->next)
		return ;
	if ((int)ft_lstlast(*b)->content < (int)(*b)->content)
		rotate(b, 'b');
	if ((int)(*b)->content < (int)(*b)->next->content)
		swap(b, 'b');
}

void	presort(t_list **a, t_list **b, t_list *batch, int *stats)
{
	size_t		i;
	int			rotations;
	t_list		*tmp;
	static int	check = 0;

	rotations = 0;
	tmp = *a;
	i = stats[2];
	if (check == (stats[1] - 1))
		i = stats[3] - 5;
	while (i)
	{
		while (!compare(tmp, batch) && ++rotations)
			tmp = tmp->next;
		rotate_batch(a, rotations, stats[0], 'a');
		push(a, b, 'b');
		sort_b(b);
		tmp = *a;
		rotations = 0;
		stats[0]--;
		i--;
	}
	check++;
}
