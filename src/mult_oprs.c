/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_oprs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:24 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 18:11:37 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multi_swap(t_list **a, t_list **b)
{
	swap(a, 'x');
	swap(b, 'x');
	ft_printf("ss\n");
}

void	multi_rotate(t_list **a, t_list **b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	ft_printf("rr\n");
}

void	multi_rrotate(t_list **a, t_list **b)
{
	rrotate(a, 'x');
	rrotate(b, 'x');
	ft_printf("rrr\n");
}
