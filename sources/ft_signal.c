/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:44:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/11 19:26:15 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_sigcont(int sig)
{
	sig = 0;
	ft_putendl("SIGCONT");
}

static void		ft_sigtstp(int sig)
{
	sig = 0;
	ft_putendl("SIGTSTP");
}

int			ft_can_print(t_list *node)
{
	t_select		var;
	t_list			*temp;

	var.col = 0;
	var.row = 0;
	temp = node;
	while (temp)
	{
		ioctl(0, TIOCGWINSZ, &var.ws);
		if (ft_check(&var, node, temp->content) == -1)
		{
			ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 0);
			return (-1);
		}
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), var.col, var.row++), 0);
		temp = temp->next;
	}
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 0);
	return (0);
}

static void		ft_sigwinch(int sig)
{
	sig = 0;
	ft_clear_shell();
	if (ft_can_print(g_node) == 0)
		ft_print_underline(g_node, g_height);
	else
	{
		ft_clear_shell();
		ft_putendl("ft_select: The windows is too small to print all the arguments.");
	}
}

static void		ft_other_signals(int sig)
{
	static struct termios	eop;

	sig = 0;
	tcgetattr(0, &eop);
	tcsetattr(0, 0, &eop);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	exit(1);
}

static void		ft_directionel(int sig)
{
	if (sig == 18)
		ft_sigtstp(sig);
	else if (sig == 19)
		ft_sigcont(sig);
	else if (sig == 28)
		ft_sigwinch(sig);
	else
		ft_other_signals(sig);
}

void			ft_signal(void)
{
	size_t	index;

	index = 0;
	while (++index <= 31)
		signal(index, ft_directionel);
}
