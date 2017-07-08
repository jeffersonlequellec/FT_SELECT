/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:53:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/08 19:01:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./../libft/libft.h"
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>

# define UP_ARROW 4283163
# define DO_ARROW 4348699
# define SPACE 32
# define DELETE 127
# define SURLINE "\033[45m"
# define ENDLINE "\033[0m"

/*
** ERRNO
*/

# define NO_ARGV 666
# define NO_VAR 667
# define NO_ENTRY 668
# define NO_DB 669
# define NO_ID 670
# define NO_STR 671
# define NO_TMS 672
# define NO_SET 673
# define NO_READ 674

/*
** eop = End Of Program
*/

typedef struct		s_select
{
	struct termios	eop;
}					t_select;

/*
** FT_TOOLS.C
*/

int					ft_errno(int error);
t_list				*ft_populate_list(char **argv);
void				ft_remove_from_list(t_list **node, int height);

/*
** FT_DISPLAY.C
*/
void				ft_print_underline(t_list *node, int height);
void				ft_iter_list(t_list *node, int height);
void				ft_print_arguments(t_list *node);

/*
** FT_INITIALISATION.C
*/

int					ft_initiate_terms(t_select *var);
int					ft_to_non_canonique(void);
int					ft_clear_shell(void);
int					ft_place_cursor(void);

/*
** FT_SELECT.C
*/

int					ft_select(int argc, t_list **node);


#endif
