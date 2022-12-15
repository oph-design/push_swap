/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:25:47 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/13 16:12:58 by oheinzel         ###   ########.fr       */
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

void	print_list_ehre(t_list *ls, t_list *batch)
{
	static int	x;

	ft_printf("---%d---\n", x);
	while (ls != NULL)
	{
		if (compare(ls, batch))
			ft_printf("\033[0;32m%d\n\033[0m", (int *)ls->content);
		else
			ft_printf("%d\n", (int *)ls->content);
		ls = ls->next;
	}
	x++;
}

// static int	optimize(t_list *stack, t_list *batch, size_t i, int args)
// {
// 	t_list	*tmp;
// 	int		count;
// 	int		cmp;

// 	tmp = stack;
// 	count = 0;
// 	cmp = -1;
// 	while (!compare(tmp, batch) && ++count)
// 		tmp = tmp->next;
// 	tmp = stack;
// 	while (i && tmp != NULL)
// 	{
// 		if (compare(tmp, batch))
// 			i--;
// 		tmp = tmp->next;
// 		cmp++;
// 	}
// 	if (count > (args - cmp))
// 		return (cmp);
// 	return (count);
// }

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
		i = stats[3];
	while (i)
	{
		while (!compare(tmp, batch) && ++rotations)
			tmp = tmp->next;
		//rotations = optimize(*a, batch, i, stats[0]);
		rotate_batch(a, rotations, stats[0], 'a');
		push(a, b, 'b');
		tmp = *a;
		rotations = 0;
		stats[0]--;
		i--;
	}
	check++;
}

// while (!compare(tmp, batch) && ++j) // 	tmp = (tmp)->next;
