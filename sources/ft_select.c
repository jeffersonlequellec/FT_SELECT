/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 20:24:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(void)
{
	char	*line;
	int		width;
	int		height;

	width = 0;
	height = 0;
	while (get_next_line(0, &line))
	{
		if (ft_atoi_mod(line) == UP_ARROW)
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height -= 1), 0);
		else if (ft_atoi_mod(line) == DO_ARROW)
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), width, height += 1), 0);
		ft_strdel(&line);
	}
	return (0);
}
