/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:59:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 15:16:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_end_of_program(t_list **node)
{
	CHK_II(ft_to_non_canonique());
	ft_dellst(node);
	return (0);
}

static int		ft_initialisation(char **argv, t_list **node)
{
	*node = ft_populate_list(argv + 1);
	CHK_II(ft_initiate_terms());
	CHK_II(ft_to_canonique());
	CHK_II(ft_clear_shell());
	ft_printlst(*node);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list		*node;

	if (argc < 2)
		return (ft_errno(NO_ARGV));
	signal(SIGQUIT, ft_sigquit);
	CHK_II(ft_initialisation(argv, &node));
	CHK_II(ft_select());
	CHK_II(ft_end_of_program(&node));
	return (0);
}
