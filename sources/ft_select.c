/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/03 20:44:40 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(char *line, int argc)
{
	static int	width = 0;
	static int	height = 0;

	if (ft_atoi_mod(line) == UP_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height -= 1), 0);
	else if (ft_atoi_mod(line) == DO_ARROW)
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height += 1), 0);
	if (height >= argc)
	{
		height = 0;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height), 0);
	}
	else if (height < 0)
	{
		height = argc - 1;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height), 0);
	}
}

int		ft_select(int argc)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (*line == 'Q')
			break ;
		ft_putstr_fd(tgetstr("us", NULL), 0);
		ft_move_cursor(line, argc);
		ft_strdel(&line);
	}
	return (0);
}
