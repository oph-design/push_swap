/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/05 15:45:22 by oheinzel         ###   ########.fr       */
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
//ready to use aber stack a muss vorher kopiert werden Junge
void	rm_min(t_list **stack, void	*content)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *stack;
	prev = tmp;
	if (((int)(tmp)->content) == (int)content)
	{
		prev = (tmp)->next;
		//ft_lstdelone(*stack, free);
		*stack = prev;
		return ;
	}
	tmp = (tmp)->next;
	while (tmp != NULL)
	{
		if (((int)(tmp)->content) == (int)content)
		{
			prev->next = (tmp)->next;
			//ft_lstdelone(*stack, free);
			return ;
		}
		prev = tmp;
		tmp = (tmp)->next;
	}
}

t_list	*min_value(t_list	**stack)
{
	t_list	*res;
	t_list	*tmp;

	tmp = *stack;
	res = tmp;
	while (tmp != NULL)
	{
		if ((int)tmp->content < (int)res->content)
			res = tmp;
		tmp = tmp->next;
	}
	rm_min(stack, res->content);
	return (ft_lstnew(res->content));
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		return (1);
	b = NULL;
	a = convert(argc, argv);
	argc = 0;
	if (check_nbr(&a))
		return (ft_putendl_fd("\033[0;31mERROR: NON INTEGER", 2), 1);
	if (check_dups(a, &argc))
		return (ft_putendl_fd("\033[0;31mERROR: DUPLICATE", 2), 1);
	print_list(a);
	b = min_value(&a);
	print_list(a);
	print_list(b);
	ft_lstadd_back(&b, min_value(&a));
	print_list(a);
	print_list(b);
	//solve(&a, &b, argc);
	return (0);
}
