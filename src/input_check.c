/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:19:05 by oheinzel          #+#    #+#             */
/*   Updated: 2022/11/26 11:28:56 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nbr(int argc, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i++ < argc)
	{
		j = 0;
		if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			return (1);
		while (argv[i][j++])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	check_spcs(char *arg)
{
	while (arg)
	{
		if (*arg == 32)
			return (1);
		arg++;
	}
	return (0);
}

static int	check_int(int argc, long *vals)
{
	argc -= 2;
	while (argc--)
	{
		if (*vals < INT_MIN || *vals > INT_MAX)
			return (1);
		vals++;
	}
	return (0);
}

static int	check_dups(int argc, long *vals)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	argc--;
	while (i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (vals[i] == vals [i + j])
				return (1);
		}
	}
	return (0);
}

int	ft_condom(int argc, char *argv[])
{
	long	*vals;

	if (argc < 2)
		return (ft_putstr_fd("ERROR: TOO FEW ARGS\n", 2), 1);
	if (check_spcs(argv[1]) && argv[2] != NULL)
		return (ft_putstr_fd("ERROR: FORMAT NOT SUPPORTED\n", 2), 1);
	if (check_nbr(argc, argv))
		return (ft_putstr_fd("ERROR: NON DIGIT DETECTED\n", 2), 1);
	vals = acatoip(argc, argv);
	if (check_int(argc, vals))
		return (ft_putstr_fd("ERROR: NON INTEGER DETECTED\n", 2), 1);
	if (check_dups(argc, vals))
		return (ft_putstr_fd("ERROR: DUPLICATE DETECTED\n", 2), 1);
	return (0);
}
