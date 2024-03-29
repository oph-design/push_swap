/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:13 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:48:43 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//finds the lowest content calue in a list and returns it
static int	find_min(t_list	**stack)
{
	t_list	*res;
	t_list	*tmp;

	if (!stack || !(*stack))
		return (0);
	tmp = *stack;
	res = tmp;
	while (tmp != NULL)
	{
		if ((int)tmp->content < (int)res->content)
			res = tmp;
		tmp = tmp->next;
	}
	return ((int)res->content);
}

//sorts a stack of 3 values within 3 operations or less
static void	sort_thr(t_list	**a, t_list	**b)
{
	int	min;

	min = find_min(a);
	if ((int)(*a)->content < (int)(*a)->next->content
		&& (int)(*a)->content < (int)(*a)->next->next->content)
		push(a, b, 'b');
	if ((int)(*a)->content > (int)(*a)->next->content)
		swap(a, 'a');
	if (*b && (int)(*b)->content == min)
		push(b, a, 'a');
	if ((int)(*a)->content < (int)(*a)->next->content
		&& (int)(*a)->next->content > (int)(*a)->next->next->content
		&& (int)(*a)->content < (int)(*a)->next->next->content)
		swap(a, 'a');
	if ((int)(*a)->content > (int)(*a)->next->next->content)
		rotate(a, 'a');
	if ((int)(*a)->content > (int)(*a)->next->next->content)
		rotate(a, 'a');
}

//sorts a stack of 5 values within 12 operations or less
int	quicksort(t_list **a, t_list **b, int argc)
{
	int	min;
	int	i;

	if (argc == 2)
		return (swap(a, 'a'), 0);
	i = argc - 3;
	while (i--)
	{
		min = find_min(a);
		if ((int)(*a)->next->content == min)
			swap(a, 'a');
		while ((int)(*a)->content != min)
			rrotate(a, 'a');
		push (a, b, 'b');
	}
	if (*b && (*b)->next && (int)(*b)->content < (int)(*b)->next->content)
		swap(b, 'b');
	sort_thr(a, b);
	push(b, a, 'a');
	push(b, a, 'a');
	return (0);
}

//checks if a given stack is already in the right order
int	check_for_order(t_list *stack, int argc)
{
	int		count;
	t_list	*tmp;

	tmp = stack;
	stack = stack->next;
	count = 1;
	while (stack != NULL
		&& (int)stack->content > (int)tmp->content)
	{
		tmp = stack;
		stack = stack->next;
		count++;
	}
	if (count == argc)
		return (1);
	return (0);
}
