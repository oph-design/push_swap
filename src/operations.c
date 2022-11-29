/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:50:38 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if(!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	ft_printf("s");
}

void	push(t_list **push, t_list **pushto, char id)
{
	t_list	*tmp;

	if (!push || !*push)
		return ;
	tmp = *push;
	*push = (*push)->next;
	ft_lstadd_front(pushto, tmp);
	ft_printf("p%c", id);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if(!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	ft_printf("r");
}

void	rrotate(t_list **stack)
{
	t_list	*tmp;

	if(!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	tmp = *stack;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	while ((tmp)->next->next != NULL)
		tmp = (tmp)->next;
	free((tmp)->next);
	(tmp)->next = NULL;
	ft_printf("rr");
}

int	operate(t_list **a, t_list **b, char id, void (*op)(t_list **stack))
{
	if (id == 'a')
		return (op(a), ft_printf("a\n"));
	if (id == 'b')
		return (op(b), ft_printf("b\n"));
	if (id == 's' || id == 'r')
		return (op(a), op(b), ft_printf("\n"));
	return (ft_printf("ERROR"));
}
