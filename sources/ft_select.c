/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/08 19:05:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(char *line, int argc, int *height)
{
	if (ft_atoi_mod(line) == UP_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height -= 1), 0);
	else if (ft_atoi_mod(line) == DO_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height += 1), 0);
	if (*height >= argc)
	{
		*height = 0;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height), 0);
	}
	else if (*height < 0)
	{
		*height = argc - 1;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height), 0);
	}
}


static void		ft_display(char *line, int argc, t_list **node, int *height)
{
	if (*line == SPACE)
	{
		ft_iter_list(*node, *height);
		*height += 1;
	}
	if (*line == DELETE)
		// remove node from list
	ft_move_cursor(line, argc, height);
	ft_clear_shell();
	ft_print_underline(*node, *height);
}

int				ft_select(int argc, t_list **node)
{
	int		height;
	char	*line;

	height = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (*line == 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_display(line, argc, node, &height);
		ft_strdel(&line);
	}
	return (0);
}
