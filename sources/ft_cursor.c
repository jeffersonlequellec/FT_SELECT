/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:55:34 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/10 15:55:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(char *line, int *height)
{
	if (ft_atoi_mod(line) == UP_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height -= 1), 0);
	else if (ft_atoi_mod(line) == DO_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, *height += 1), 0);
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
