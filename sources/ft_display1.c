/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:24:21 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/14 18:14:00 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	static size_t	len = 0;

	if (len == 0)
		len = ft_longest_word(node) - 5;
	if (var->row == var->ws.ws_row)
	{
		var->row = 0;
		var->col += len;
	}
	if (var->col + ft_strlen(str) >= var->ws.ws_col)
	{
		ft_clear_shell();
		ft_putendl(
			"ft_select: The windows is too small to print all the arguments.");
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
