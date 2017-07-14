/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:55:34 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/14 18:06:04 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(char *line, int *height)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	if (ft_atoi_mod(line) == UP_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height -= 1), 0);
	else if (ft_atoi_mod(line) == DO_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height += 1), 0);
	else if (ft_atoi_mod(line) == LE_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height -= ws.ws_row), 0);
	else if (ft_atoi_mod(line) == RI_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height += ws.ws_row), 0);
}

void	ft_check_cursor(int *height, t_list *node)
{
	int		len;

	len = ft_lstlen(node);
	if (*height >= len)
	{
		*height = 0;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height), 0);
	}
	else if (*height < 0)
	{
		*height = len - 1;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height), 0);
	}
}

int		ft_place_cursor(void)
{
	char	*cursor;

	if (!(cursor = tgetstr("cm", NULL)))
		return (ft_errno(NO_STR));
	ft_putstr_fd(tgoto(cursor, 0, 0), 0);
	return (0);
}

int		ft_cursor_visible(void)
{
	char	*ve;

	if (!(ve = tgetstr("ve", NULL)))
		return (ft_errno(NO_CUR));
	ft_putstr_fd(ve, 0);
	return (0);
}

int		ft_cursor_invisible(void)
{
	char	*vi;

	if (!(vi = tgetstr("vi", NULL)))
		return (ft_errno(NO_CUR));
	ft_putstr_fd(vi, 0);
	return (0);
}
