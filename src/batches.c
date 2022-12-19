/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batches.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:02:53 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/19 13:42:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*useless(void *v)
{
	void	*r;

	r = v;
	return (r);
}

//finds lowest current value in a list and returns a new node with its value
static t_list	*min_val(t_list	**stack)
{
	t_list	*res;
	t_list	*tmp;

	if (!stack || !(*stack))
		return (NULL);
	tmp = *stack;
	res = tmp;
	while (tmp != NULL)
	{
		if ((int)tmp->content < (int)res->content)
			res = tmp;
		tmp = tmp->next;
	}
	rm_val(stack, res->content);
	return (ft_lstnew(res->content));
}

//finds highest current value in a list and returns its content
static void	*max_val(t_list	**stack)
{
	t_list	*res;
	t_list	*tmp;

	if (!stack || !(*stack))
		return (NULL);
	tmp = *stack;
	res = tmp;
	while (tmp != NULL)
	{
		if ((int)tmp->content > (int)res->content)
			res = tmp;
		tmp = tmp->next;
	}
	rm_val(stack, res->content);
	return (res->content);
}

//returns array with lists (one list for each batch)
//lists are sorted from smallest value to highest
t_list	**get_batches(t_list *stack, int batch_num, int argc)
{
	t_list	**batches;
	t_list	*cpy;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	cpy = ft_lstmap(stack, useless, NULL);
	batches = malloc((batch_num + 1) * sizeof(t_list));
	while (i < (size_t)(batch_num))
	{
		batches[i] = min_val(&cpy);
		while (j++ < (size_t)((argc / batch_num) - 1))
			ft_lstadd_back(&batches[i], min_val(&cpy));
		if (i == (size_t)(batch_num - 1))
			ft_lstlast(batches[i])->next = cpy;
		j = 0;
		i++;
	}
	while (j++ < 5)
		rm_val(&batches[i - 1], max_val(&batches[i - 1]));
	batches[i] = NULL;
	return (batches);
}
