/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 16:56:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *ls)
{
	ft_printf("---\n");
	while (ls != NULL)
	{
		ft_printf("%d\n", (int *)ls->content);
		ls = ls->next;
	}
	ft_printf("---\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		test[5] = {78, 37, 100, -6, 8999};
	int		i;

	if (argc < 2)
		return (1);
	a = convert(argc, argv);
	if (check_nbr(&a))
		return (ft_putendl_fd("\033[0;31mERROR: NON INTEGER", 2), 1);
	print_list(a);
	if (check_dups(a))
		return (ft_putendl_fd("\033[0;31mERROR: DUPLICATE", 2), 1);
	print_list(a);
	i = 0;
	b = ft_lstnew((void *)test[i]);
	while (i++ < 4)
		ft_lstadd_back(&b, ft_lstnew((void *)test[i]));
	print_list(b);
	operate(&a, &b, 'r', rrotate);
	print_list(a);
	print_list(b);
}
