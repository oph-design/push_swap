/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/28 16:04:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		test[5] = {78, 37, 100, -6, 8999};
	int		i;

	if (argc < 2)
		return (1);
	a = convert(argc, argv);
	if (ft_condom(&a))
		return (1);
	i = 0;
	b = ft_lstnew(&test[i]);
	while (i++ < 4)
		ft_lstadd_back(&b, ft_lstnew(&test[i]));
	print_list(a);
	print_list(b);
	operate(&a, &b, 'r', rrotate);
	print_list(a);
	print_list(b);
}
