/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 18:36:13 by oheinzel         ###   ########.fr       */
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
	if (check_dups(a))
		return (ft_putendl_fd("\033[0;31mERROR: DUPLICATE", 2), 1);
	i = 0;
	b = ft_lstnew((void *)test[i]);
	while (i++ < 4)
		ft_lstadd_back(&b, ft_lstnew((void *)test[i]));
	print_list(a);
	print_list(b);
	swap(&a, 'a');
	swap(&b, 'b');
	multi_swap(&a, &b);
	rotate(&a, 'a');
	rotate(&b, 'b');
	multi_rotate(&a, &b);
	rrotate(&a, 'a');
	rrotate(&b, 'b');
	multi_rrotate(&a, &b);
	push(&a, &b, 'a');
	push(&b, &a, 'b');
	print_list(a);
	print_list(b);
	system("leaks push_swap");
	return (0);
}
