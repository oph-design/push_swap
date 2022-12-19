/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:14:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Batch_Stats Array:
*	[0] = total number of arguments
*	[1] = number of batches
*	[2] = number of arguments per batch
*	[3] = arguments of last batch
*/

void	solve(t_list **a, t_list **b, int argc)
{
	int				batch_stats[4];
	t_list			**batches;
	size_t			i;

	batch_stats[0] = argc;
	batch_stats[1] = 1;
	if (argc >= 60)
		batch_stats[1] = 0.018 * argc + 3.25;
	batch_stats[2] = (batch_stats[0] / batch_stats[1]);
	batch_stats[3] = batch_stats[0] - (batch_stats[2] * (batch_stats[1] - 1));
	batches = get_batches(*a, batch_stats[1], batch_stats[0]);
	i = 0;
	while (batches[i] != NULL)
		presort(a, b, batches[i++], batch_stats);
	quicksort(a, b, 5);
	batch_stats[0] = argc - 5;
	while (i--)
		sort(a, b, batches[i], batch_stats);
	free(batches);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	b = NULL;
	a = convert(argc, argv);
	argc = 0;
	if (check_nbr(&a))
		return (lc(&a), ft_putendl_fd("Error", 2), 1);
	if (check_dups(a, &argc))
		return (lc(&a), ft_putendl_fd("Error", 2), 1);
	if (argc == 1 || check_for_order(a, argc))
		return (lc(&a), 0);
	if (argc < 6)
		return (quicksort(&a, &b, argc), lc(&a), 0);
	solve(&a, &b, argc);
	return (lc(&a), 0);
}
