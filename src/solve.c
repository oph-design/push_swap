/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:02:25 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/07 16:39:03 by oheinzel         ###   ########.fr       */
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

static int	rotate_batch(t_list **stack, size_t j, unsigned int args)
{
	int	count;

	count = 0;
	if (j > (args / 2))
	{
		j = args - j;
		while (j--)
		{
			rrotate(stack, 'a');
			count++;
		}
		return (count);
	}
	while (j--)
	{
		rotate(stack, 'a');
		count++;
	}
	return (count);
}

static void	presort(t_list **a, t_list **b, t_list *batch, unsigned int *stats)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;
	int		count;

	i = 0;
	j = 0;
	tmp = *a;
	count = 0;
	while (i < stats[2])
	{
		while (!compare(tmp, batch) && ++j)
			tmp = (tmp)->next;
		count += rotate_batch(a, j, stats[0]);
		push(a, b, 'b');
		count++;
		tmp = *a;
		j = 0;
		stats[0]--;
		i++;
	}
	stats[3] += count;
}

/*
*	Batch_Stats Array:
*	[0] = total number of arguments
*	[1] = number of batches
*	[2] = number of arguments per batch
*/

void	solve(t_list **a, t_list **b, int argc)
{
	unsigned int	batch_stats[4];
	t_list			**batches;
	size_t			i;
	int				count;

	batch_stats[3] = 0;
	batch_stats[0] = (unsigned int)argc;
	batch_stats[1] = 1;
	if (argc > 10)
		batch_stats[1] = 0.013 * argc + 3.75;
	batch_stats[2] = batch_stats[0] / batch_stats[1];
	batches = get_batches(*a, batch_stats[1], batch_stats[0]);
	i = 0;
	while (batches[i + 1] != NULL)
		presort(a, b, batches[i++], batch_stats);
	ft_printf("count %d\n", batch_stats[3]);
	print_list(*b);
	print_list(*a);
	i = 0;
	while (batches[i] != NULL)
		ft_lstclear_ps(&batches[i++]);
	free(batches);
}
