/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:14:06 by jefferso          #+#    #+#             */
/*   Updated: 2017/07/14 18:14:12 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_surline(char **content, size_t *flag, char **color)
{
	char	*memory;
	char	*temp;

	if (*flag == 0)
	{
		temp = *content;
		memory = temp;
		*content = ft_strdup(*color);
		ft_strdel(&memory);
		memory = *color;
		*color = ft_strdup(temp);
		ft_strdel(&memory);
		*flag = 1;
	}
	else
	{
		temp = *color;
		memory = temp;
		*color = ft_strdup(*content);
		ft_strdel(&memory);
		memory = *content;
		*content = ft_strdup(temp);
		ft_strdel(&memory);
		*flag = 0;
	}
}

void			ft_iter_list(t_list *node, int height)
{
	int			index;
	t_list		*temp;

	index = 0;
	temp = node;
	while (temp)
	{
		if (index == height)
			ft_surline(&temp->content, &temp->content_size, &temp->color);
		index++;
		temp = temp->next;
	}
}
