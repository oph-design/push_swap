/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:11:36 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/29 19:23:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include "libft.h"
# include <limits.h>

//list-utils
t_list	*convert(int argc, char **argv);
int		check_dups(t_list *stack);
int		check_nbr(t_list **stack, int split);
void	print_list(t_list *ls);
int		check_spcs(char *arg);

//operations
void	swap(t_list **st, char id);
void	push(t_list **push, t_list **pushto, char id);
void	rotate(t_list **stack, char id);
void	rrotate(t_list **stack, char id);
void	multi_rrotate(t_list **a, t_list **b);
void	multi_rotate(t_list **a, t_list **b);
void	multi_swap(t_list **a, t_list **b);

#endif
