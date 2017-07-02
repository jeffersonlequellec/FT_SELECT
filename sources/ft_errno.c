/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:59:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/02 15:07:27 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_errno(int error)
{
	if (error == NO_ARGV)
		ft_putendl_fd("ft_select: Too few arguments.", 2);
	else if (error == NO_VAR)
		ft_putendl_fd("ft_select: Variable $TERM is not defined.", 2);
	else if (error == NO_ENTRY)
		ft_putendl_fd("ft_select: No such entry.", 2);
	else if (error == NO_DB)
		ft_putendl_fd("ft_select: Terminfo database could not be found.", 2);
	else if (error == NO_ID)
		ft_putendl_fd("ft_select: Numeric id is not available.", 2);
	else if (error == NO_STR)
		ft_putendl_fd("ft_select: String entry is not available.", 2);
	else if (error == NO_TMS)
		ft_putendl_fd("ft_select: Informations could not be found.", 2);
	else if (error == NO_SET)
		ft_putendl_fd("ft_select: Couldn't change value of struct termios.", 2);
	else if (error == NO_READ)
		ft_putendl_fd("ft_select: Error with function read", 2);
	return (-1);
}
