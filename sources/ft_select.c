/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/14 12:53:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_display(char *line, t_list **node, int *height)
{
	if (*line == SPACE)
	{
		ft_iter_list(*node, *height);
		*height += 1;
	}
	else if (ft_atoi_mod(line) == DELETE || *line == BACKSPACE)
		ft_delete_from_list(node, *height);
	ft_move_cursor(line, height);
	ft_check_cursor(height, *node);
	ft_clear_shell();
	ft_print_underline(*node, *height);
	if (ft_lstlen(*node) == 0)
		return (-1);
	return (0);
}

char			*ft_select(t_list **node)
{
	int		height;
	char	*line;

	height = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (*line == ENTER || ft_lstlen(*node) == 0)
			break ;
		if (*line == ESCAPE)
			break ;
		if (ft_display(line, node, &height) == -1)
			break ;
		g_height = height;
		ft_strdel(&line);
	}
	return (line);
}
