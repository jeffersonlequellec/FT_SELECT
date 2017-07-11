/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:59:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/11 18:24:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** EOP = End Of Program.
** CHK_II = If (a == -1) return (-1).
**
** Global_(Node && Height) are used by the window size signal, to be able
** to reprint the arguments flawlessly.
*/

t_list			*g_node;
int				g_height;

static int		ft_end_of_program(t_list **node, termios *eop, char **line)
{
	if (tcsetattr(0, TCSADRAIN, eop) == 1)
		return (ft_errno(NO_SET));
	CHK_II(ft_cursor_visible());
	CHK_II(ft_clear_shell());
	**line == ENTER ? ft_print_arguments(*node) : 0;
	ft_strdel(line);
	ft_dellst(node);
	return (0);
}

static int		ft_initialisation(char **argv, t_list **node, termios *eop)
{
	*node = ft_populate_list(argv + 1);
	g_node = *node;
	CHK_II(ft_initiate_terms(eop));
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
	struct termios	eop;

	if (argc < 2)
		return (ft_errno(NO_ARGV));
	CHK_II(ft_initialisation(argv, &node, &eop));
	CHK_CI((line = ft_select(&node)));
	CHK_II(ft_end_of_program(&node, &eop, &line));
	return (0);
}
