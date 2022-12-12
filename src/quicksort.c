/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:07:13 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/12 18:10:32 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_thr(t_list	**a, t_list	**b)
{
	int min;

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

static int	quicksort(t_list **a, t_list **b, int argc)
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
	if (*b && (int)(*b)->content < (int)(*b)->next->content)
		swap(b, 'b');
	sort_thr(a, b);
	push(b, a, 'a');
	push(b, a, 'a');
	return (0);
}
