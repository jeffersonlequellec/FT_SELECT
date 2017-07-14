/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:09:52 by jefferso          #+#    #+#             */
/*   Updated: 2017/07/15 00:00:40 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_sigcont(int sig)
{
	(void)sig;
	ft_clear_shell();
	ft_cursor_invisible();
	ft_to_non_canonique();
	ft_print_underline(g_node, g_height);
}

void	ft_sigtstp(int sig)
{
	struct termios	term;
	char			c[2];

	signal(sig, SIG_DFL);
	tcgetattr(0, &term);
	c[0] = term.c_cc[VSUSP];
	c[1] = '\0';
	term.c_lflag |= (ICANON | ECHO);
	ioctl(0, TIOCSTI, c);
	ft_cursor_visible();
	tcsetattr(0, TCSADRAIN, &term);
}

void	ft_other_signals(int sig)
{
	(void)sig;
	ft_clear_shell();
	ft_to_canonique();
	ft_cursor_visible();
	exit(1);
}
