/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:53:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 15:17:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./../libft/libft.h"
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>

/*
** ERRNO
*/

# define NO_ARGV 0
# define NO_VAR 1
# define NO_ENTRY 2
# define NO_DB 3
# define NO_ID 4
# define NO_STR 5
# define NO_TMS 6
# define NO_SET 7
# define NO_READ 8

/*
** FT_TOOLS.C
*/

int					ft_errno(int error);

/*
** FT_INITIALISATION.C
*/

int					ft_initiate_terms(void);
int					ft_to_canonique(void);
int					ft_clear_shell(void);

/*
** FT_END_OF_PROGRAM.C
*/

int					ft_to_non_canonique(void);

/*
** FT_SIGNAL.C
*/

void				ft_sigquit(int sig);

/*
** FT_SELECT.C
*/

int					ft_select(void);

#endif
