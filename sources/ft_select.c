/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/07 16:03:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_display(char *line, int argc, t_list *node, int *height)
{
	ft_move_cursor(line, argc, height);
	CHK_IV(ft_clear_shell());
	ft_print_underline(node, *height);
}

int				ft_select(int argc, t_list *node)
{
	int		height;
	char	*line;

	height = 0;
	while (get_next_line(0, &line))
	{
		if (*line == 'Q') // MEMORY LEAKS (LINE IS NOT FREE IF BREAK)
			break ;
		ft_display(line, argc, node, &height);
		ft_strdel(&line);
	}
	return (0);
}
