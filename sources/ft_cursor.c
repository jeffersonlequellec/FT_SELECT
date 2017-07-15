/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:55:34 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/15 12:47:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_dynamic_search(char *line, t_list *node, int *height)
{
	int		ret;
	t_list	*temp;

	ret = 0;
	temp = node;
	while (ret < *height)
	{
		temp = temp->next;
		ret++;
	}
	while (temp->next)
	{
		temp = temp->next;
		ret++;
		if (*temp->content == *line)
			return (ret);
	}
	if (!temp->next)
		*height = 0;
	return (0);
}

void			ft_move_cursor(char *line, int *height, t_list *node)
{
	int				d_search;
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
	else if (!(
		ft_atoi_mod(line) == DELETE || *line == BACKSPACE || *line == SPACE))
		if ((d_search = ft_dynamic_search(line, node, height)) > 0)
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height = d_search), 0);
}

void			ft_check_cursor(int *height, t_list *node)
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

int				ft_cursor_visible(void)
{
	char	*ve;

	if (!(ve = tgetstr("ve", NULL)))
		return (ft_errno(NO_CUR));
	ft_putstr_fd(ve, 0);
	return (0);
}

int				ft_cursor_invisible(void)
{
	char	*vi;

	if (!(vi = tgetstr("vi", NULL)))
		return (ft_errno(NO_CUR));
	ft_putstr_fd(vi, 0);
	return (0);
}
