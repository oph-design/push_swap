/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/08 21:23:25 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(t_list *stack, t_list *badge)
{
	if (!stack)
		return (1);
	while (badge != NULL)
	{
		if ((int)(stack->content) == (int)(badge->content))
			return (1);
		badge = badge->next;
	}
	return (0);
}

static int	rotate_batch(t_list **stack, size_t j, unsigned int args, char id)
{
	int	count;

	count = 0;
	ft_printf("j: %d\n", j);
	if (j > (size_t)(args / 2))
	{
		j = (size_t)(args) - j;
		while (j-- && ++count)
			rrotate(stack, id);
		return (count);
	}
	while (j-- && ++count)
		rotate(stack, id);
	return (count);
}

void	presort(t_list **a, t_list **b, t_list *batch, unsigned int *stats)
{
	size_t			i;
	size_t			j;
	t_list			*tmp;
	unsigned int	count;

	i = 0;
	j = 0;
	tmp = *a;
	count = 0;
	while (i < stats[2])
	{
		while (!compare(tmp, batch) && ++j)
			tmp = (tmp)->next;
		count += rotate_batch(a, j, stats[0], 'a');
		push(a, b, 'b');
		tmp = *a;
		j = 0;
		stats[0]--;
		count++;
		i++;
	}
	stats[3] += count;
}

static size_t	find_max(t_list **stack, t_list *batch)
{
	size_t	count;
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
	while (!compare(max, *stack) && tmp_stack != NULL)
	{
		tmp_stack = tmp_stack->next;
		count++;
	}
	rm_val(&batch, max->content);
	ft_printf("c: %d\n", count);
	return (count);
}

void	sort(t_list **a, t_list **b, t_list *batch, unsigned int *stats)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < stats[2] && batch != NULL)
	{
		count += rotate_batch(b, find_max(b, batch), stats[0], 'b');
		push(b, a, 'a');
		count++;
		stats[0]--;
		i++;
	}
	stats[3] += count;
}
