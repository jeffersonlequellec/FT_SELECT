/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:59:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/08 18:57:15 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_end_of_program(t_list **node, t_select var)
{
	if (tcsetattr(0, TCSADRAIN, &var.eop) == 1)
		return (ft_errno(NO_SET));
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	CHK_II(ft_clear_shell());
	ft_print_arguments(*node);
	ft_dellst(node);
	return (0);
}

static int		ft_initialisation(char **argv, t_list **node, t_select *var)
{
	*node = ft_populate_list(argv + 1);
	CHK_II(ft_initiate_terms(var));
	CHK_II(ft_to_non_canonique());
	CHK_II(ft_clear_shell());
	ft_print_underline(*node, 0);
	CHK_II(ft_place_cursor());
	return (0);
}

int		main(int argc, char **argv)
{
	t_list		*node;
	t_select	var;

	if (argc < 2)
		return (ft_errno(NO_ARGV));
	CHK_II(ft_initialisation(argv, &node, &var));
	CHK_II(ft_select(argc - 1, &node));
	CHK_II(ft_end_of_program(&node, var));
	return (0);
}
