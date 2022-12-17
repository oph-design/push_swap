/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/17 15:01:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_list **stack, t_list *batch)
{
	int		count;
	t_list	*tmp_stack;
	t_list	*tmp_batch;
	t_list	*max;

	if (!stack || !(*stack) || !batch)
		return (0);
	tmp_stack = *stack;
	tmp_batch = batch;
	max = tmp_batch;
	count = 0;
	while (tmp_batch != NULL)
	{
		if ((int)tmp_batch->content > (int)max->content)
			max = tmp_batch;
		tmp_batch = tmp_batch->next;
	}
	while ((int)tmp_stack->content != (int)max->content)
	{
		tmp_stack = tmp_stack->next;
		count++;
	}
	rm_val(&batch, max->content);
	return (count);
}

void	sort(t_list **a, t_list **b, t_list *batch, int *stats)
{
	size_t	i;

	i = stats[2];
	if ((*a)->next->next->next->next->next == NULL)
		i = stats[3] - 5;
	while (i && batch != NULL)
	{
		rotate_batch(b, find_max(b, batch), stats[0], 'b');
		push(b, a, 'a');
		stats[0]--;
		i--;
	}
}
