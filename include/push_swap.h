/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:11:36 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/28 16:05:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include "libft.h"
# include <limits.h>

//list-utils
t_list	*convert(int argc, char **argv);
void	print_list(t_list *ls);

//opreations
void	swap(t_list **st);
void	push(t_list **push, t_list **pushto, char id);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
int		operate(t_list **a, t_list **b, char id, void (*op)(t_list **stack));

//protection
int		ft_condom(t_list **stack);

#endif
