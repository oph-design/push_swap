/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/09 15:33:37 by oheinzel         ###   ########.fr       */
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

static void	rotate_batch(t_list **stack, int j, int args, char id)
{
	if (j > (args / 2))
	{
		j = args - j;
		while (j--)
			rrotate(stack, id);
		return ;
	}
	while (j--)
		rotate(stack, id);
}

void	presort(t_list **a, t_list **b, t_list *batch, int *stats)
{
	size_t			i;
	int				j;
	t_list			*tmp;

	i = 0;
	j = 0;
	tmp = *a;
	while (i < stats[2])
	{
		while (!compare(tmp, batch) && ++j)
			tmp = (tmp)->next;
		rotate_batch(a, j, stats[0], 'a');
		push(a, b, 'b');
		tmp = *a;
		j = 0;
		stats[0]--;
		i++;
	}
}

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

	i = 0;
	while (i < stats[2] && batch != NULL)
	{
		rotate_batch(b, find_max(b, batch), stats[0], 'b');
		push(b, a, 'a');
		stats[0]--;
		i++;
	}
}
