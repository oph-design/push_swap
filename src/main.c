/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/06 09:19:28 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *ls)
{
	static int	x = 1;

	ft_printf("---%d---\n", x);
	while (ls != NULL)
	{
		ft_printf("%d\n", (int *)ls->content);
		ls = ls->next;
	}
	x++;
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
	//system("leaks push_swap");
	return (0);
}
