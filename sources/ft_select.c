/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:15:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 17:11:19 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(void)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_putendl_fd(tgoto(tgetstr("cm", NULL), x, y), 0);
	while (42)
	{
	}
	return (0);
}
