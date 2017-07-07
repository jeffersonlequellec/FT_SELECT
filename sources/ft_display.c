/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:24:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/07 16:01:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_print_underline(t_list *node, int height)
{
	int		index;
	t_list	*temp;

	index = 0;
	temp = node;
	while (temp)
	{
		if (index == height)
		{
			ft_putstr_fd(tgetstr("us", NULL), 0);
			ft_putendl(temp->content);
			ft_putstr_fd(tgetstr("ue", NULL), 0);
		}
		else
			ft_putendl(temp->content);
		index++;
		temp = temp->next;
	}
}

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
