/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 08:53:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/10 15:42:32 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./../libft/libft.h"
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>

# define UP_ARROW 4283163
# define DO_ARROW 4348699
# define SPACE 32
# define ESCAPE 27 && !line[1]
# define DELETE 2117294875
# define BACKSPACE 127
# define ENTER 0
# define SURLINE "\033[45m"
# define ENDLINE "\033[0m"
# define NO_ARGV 666
# define NO_VAR 667
# define NO_ENTRY 668
# define NO_DB 669
# define NO_ID 670
# define NO_STR 671
# define NO_TMS 672
# define NO_SET 673
# define NO_READ 674
# define NO_CUR 675

typedef struct termios termios;
typedef struct			s_select
{
	int					col;
	int					row;
	struct winsize		ws;
}						t_select;

/*
** FT_CURSOR.C
*/

void					ft_move_cursor(char *line, int *height);
void					ft_check_cursor(int *height, t_list *node);

/*
** FT_TOOLS.C
*/

int						ft_longest_word(t_list *node);
int						ft_errno(int error);
t_list					*ft_populate_list(char **argv);
void					ft_delete_from_list(t_list **node, int height);

/*
** FT_DISPLAY.C
*/
void					ft_print_underline(t_list *node, int height);
void					ft_iter_list(t_list *node, int height);
void					ft_print_arguments(t_list *node);

/*
** FT_INITIALISATION.C
*/

int						ft_initiate_terms(struct termios *eop);
int						ft_to_non_canonique(void);
int						ft_clear_shell(void);
int						ft_place_cursor(void);
int						ft_cursor_invisible(void);
int						ft_cursor_invisible(void);
int						ft_cursor_visible(void);

/*
** FT_SELECT.C
*/

char					*ft_select(t_list **node);

/*
** FT_SIGNAL.C
*/

void					ft_signal(void);

#endif
