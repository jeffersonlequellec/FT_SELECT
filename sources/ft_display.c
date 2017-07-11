/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:24:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/11 19:26:07 by jle-quel         ###   ########.fr       */
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

void			ft_print(char *str, int fd, int index, int height)
{
	if (index == height)
	{
		ft_putstr_fd(tgetstr("us", NULL), 0);
		ft_putstr_fd(str, fd);
		ft_putstr_fd(tgetstr("ue", NULL), 0);
	}
	else
		ft_putstr_fd(str, fd);
}

int				ft_check(t_select *var, t_list *node, char *str)
{
	if (var->row == var->ws.ws_row)
	{
		var->row = 0;
		var->col += ft_longest_word(node);
	}
	if (var->col + ft_strlen(str) >= var->ws.ws_col)
	{
		ft_clear_shell();
		ft_putendl("ft_select: The windows is too small to print all the arguments.");
		return (-1);
	}
	return (0);
}

void			ft_print_underline(t_list *node, int height)
{
	int				index;
	t_select		var;
	static int		fd;
	t_list			*temp;

	index = 0;
	var.col = 0;
	var.row = 0;
	fd = open("/dev/tty", O_RDWR);
	temp = node;
	while (temp)
	{
		ioctl(0, TIOCGWINSZ, &var.ws);
		if (ft_check(&var, node, temp->content) == -1)
			break ;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), var.col, var.row++), 0);
		ft_print(temp->content, fd, index++, height);
		temp = temp->next;
	}
}

void			ft_print_arguments(t_list *node)
{
	size_t	ret;
	t_list	*temp;

	ret = 0;
	temp = node;
	while (temp)
	{
		if (temp->content_size == 1)
		{
			ft_putstr(temp->color);
			ft_putchar(' ');
			ret++;
		}
		temp = temp->next;
	}
	if (ret > 0)
		ft_putchar('\n');
}
