/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_of_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 14:31:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 15:14:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_to_non_canonique(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (ft_errno(NO_TMS));
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == 1)
		return (ft_errno(NO_SET));
	return (0);
}
