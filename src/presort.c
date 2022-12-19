/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:25:47 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:54:53 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if a value is part of a batch
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

//changes the position of the last pushed node
static void	sort_b(t_list **b)
{
	if (!(*b)->next)
		return ;
	if ((int)ft_lstlast(*b)->content < (int)(*b)->content)
		rotate(b, 'b');
	if ((int)(*b)->content < (int)(*b)->next->content)
		swap(b, 'b');
}

//finds the values of each batch in stack a and pushes them to stack b
void	presort(t_list **a, t_list **b, t_list *batch, int *stats)
{
	size_t		i;
	int			pos;
	t_list		*tmp;
	static int	check = 0;

	pos = 0;
	tmp = *a;
	i = stats[2];
	if (check == (stats[1] - 1))
		i = stats[3] - 5;
	while (i)
	{
		while (!compare(tmp, batch) && ++pos)
			tmp = tmp->next;
		rotate_batch(a, pos, stats[0], 'a');
		push(a, b, 'b');
		sort_b(b);
		tmp = *a;
		pos = 0;
		stats[0]--;
		i--;
	}
	check++;
}
