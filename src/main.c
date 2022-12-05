/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:17:26 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/05 15:58:51 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*useless(void *v)
{
	return (v);
}

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

void	test(t_list *a)
{
	t_list	*b;
	t_list	*a2;

	a2 = ft_lstmap(a, useless, free);
	b = min_value(&a2);
	ft_lstadd_back(&b, min_value(&a2));
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
	test(a);
	print_list(a);
	//solve(&a, &b, argc);
	return (0);
}
