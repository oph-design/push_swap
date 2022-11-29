/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:50:38 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 18:13:13 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char id)
{
	t_list	*tmp;

	if (!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (id == 'a' || id == 'b')
		ft_printf("s%c\n", id);
}

void	push(t_list **push, t_list **pushto, char id)
{
	t_list	*tmp;

	if (!push || !*push)
		return ;
	tmp = *push;
	*push = (*push)->next;
	ft_lstadd_front(pushto, tmp);
	if (id == 'a' || id == 'b')
		ft_printf("p%c\n", id);
}

void	rotate(t_list **stack, char id)
{
	t_list	*tmp;

	if (!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	if (id == 'a' || id == 'b')
		ft_printf("r%c\n", id);
}

void	rrotate(t_list **stack, char id)
{
	t_list	*tmp;

	if (!stack || !(*stack) || ft_lstlast(*stack) == (*stack))
		return ;
	tmp = *stack;
	ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
	while ((tmp)->next->next != NULL)
		tmp = (tmp)->next;
	free((tmp)->next);
	(tmp)->next = NULL;
	if (id == 'a' || id == 'b')
		ft_printf("rr%c\n", id);
}
