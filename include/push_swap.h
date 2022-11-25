/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:11:36 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:32 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include "libft.h"

//list-utils
int		conv_content(t_list *node);
void	print_list(t_list *ls);
int		*acatoip(int argc, char **stacka);
t_list	*convert_input(int argc, char **stacka);

//opreations
void	swap(t_list **st);
void	push(t_list **push, t_list **pushto, char id);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
int		operate(t_list **a, t_list **b, char id, void (*op)(t_list **stack));

//functions

#endif
