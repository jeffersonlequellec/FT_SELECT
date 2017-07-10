/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:44:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/10 19:04:39 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_sigcont(int sig)
{
	(void)	sig;
	ft_putendl("SIGCONT");
}

static void		ft_sigtstp(int sig)
{
	(void)	sig;
	ft_putendl("SIGTSTP");
}

static void		ft_sigwinch(int sig)
{
	(void)	sig;
}

static void		ft_other_signals(int sig)
{
	(void)					sig;
	static struct termios	eop;

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
