/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/07 13:44:31 by oheinzel         ###   ########.fr       */
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

static void	rotate_batch(t_list **stack, size_t j, unsigned int args)
{
	if (j > (args / 2))
	{
		j = args - j;
		while (j--)
			rrotate(stack, 'a');
		return ;
	}
	while (j--)
		rotate(stack, 'a');
}

static void	presort(t_list **a, t_list **b, t_list *batch, unsigned int *stats)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = *a;
	while (i < stats[2])
	{
		while (!compare(tmp, batch) && tmp != NULL)
		{
			tmp = (tmp)->next;
			j++;
		}
		rotate_batch(a, j, stats[0]);
		push(a, b, 'b');
		tmp = *a;
		j = 0;
		stats[0]--;
		i++;
	}
}

/*
*	Batch_Stats Array:
*	[0] = total number of arguments
*	[1] = number of batches
*	[2] = number of arguments per batch
*/

void	solve(t_list **a, t_list **b, int argc)
{
	unsigned int	batch_stats[3];
	t_list			**batches;
	size_t			i;

	batch_stats[0] = (unsigned int)argc;
	batch_stats[1] = 1;
	if (argc > 10)
		batch_stats[1] = 0.013 * argc + 3.75;
	batch_stats[2] = batch_stats[0] / batch_stats[1];
	batches = get_batches(*a, batch_stats[1], batch_stats[0]);
	i = 0;
	print_list(*a);
	while (batches[i] != NULL)
		presort(a, b, batches[i++], batch_stats);
	print_list(*b);
	i = 0;
	while (batches[i] != NULL)
		ft_lstclear_ps(&batches[i++]);
	free(batches);
}
