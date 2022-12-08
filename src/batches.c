/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batches.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:02:53 by oheinzel          #+#    #+#             */
/*   Updated: 2022/12/08 10:25:28 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*useless(void *v)
{
	void	*r;

	r = v;
	return (r);
}

static t_list	*min_value(t_list	**stack)
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

t_list	**get_batches(t_list *stack, unsigned int batch_num, int argc)
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
		batches[i] = min_value(&cpy);
		while (j++ < ((argc / batch_num) - 1))
			ft_lstadd_back(&batches[i], min_value(&cpy));
		j = 0;
		i++;
	}
	batches[i] = NULL;
	return (batches);
}