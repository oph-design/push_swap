/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/08 23:43:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Batch_Stats Array:
*	[0] = total number of arguments
*	[1] = number of batches
*	[2] = number of arguments per batch
*	[3] = number of operations
*/

void	solve(t_list **a, t_list **b, int argc)
{
	int				batch_stats[4];
	t_list			**batches;
	size_t			i;
	int				count;

	batch_stats[0] = argc;
	batch_stats[1] = 1;
	if (argc > 10)
		batch_stats[1] = 0.013 * argc + 3.75;
	batch_stats[2] = batch_stats[0] / batch_stats[1];
	batch_stats[3] = 0;
	batches = get_batches(*a, batch_stats[1], batch_stats[0]);
	i = 0;
	while (batches[i] != NULL)
		presort(a, b, batches[i++], batch_stats);
	batch_stats[0] = argc;
	while (i--)
		sort(a, b, batches[i], batch_stats);
	ft_printf("COUNT: %d\n", batch_stats[3]);
	print_list(*b);
	print_list(*a);
	free(batches);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (1);
	b = NULL;
	a = convert(argc, argv);
	argc = 0;
	if (check_nbr(&a))
		return (ft_putendl_fd("\033[0;31mERROR: NON INTEGER", 2), 1);
	if (check_dups(a, &argc))
		return (ft_putendl_fd("\033[0;31mERROR: DUPLICATE", 2), 1);
	solve(&a, &b, argc);
	system("leaks push_swap");
	return (0);
}
