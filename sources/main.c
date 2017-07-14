/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:59:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/14 22:28:34 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list			*g_node;
int				g_height;

static int		ft_end_of_program(t_list **node, char **line)
{
	CHK_II(ft_to_canonique());
	CHK_II(ft_cursor_visible());
	CHK_II(ft_clear_shell());
	**line == ENTER ? ft_print_arguments(*node) : 0;
	ft_strdel(line);
	ft_dellst(node);
	return (0);
}

static int		ft_initialisation(char **argv, t_list **node)
{
	*node = ft_populate_list(argv + 1);
	g_node = *node;
	CHK_II(ft_initiate_terms());
	CHK_II(ft_cursor_invisible());
	CHK_II(ft_to_non_canonique());
	CHK_II(ft_clear_shell());
	ft_print_underline(*node, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_list			*node;
	char			*line;

	if (argc < 2)
		return (ft_errno(NO_ARGV));
	ft_signal();
	CHK_II(ft_initialisation(argv, &node));
	CHK_CI((line = ft_select(&node)));
	CHK_II(ft_end_of_program(&node, &line));
	return (0);
}
