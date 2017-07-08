/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:59:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/08 19:05:17 by jle-quel         ###   ########.fr       */
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

t_list	*ft_populate_list(char **argv)
{
	size_t	index;
	t_list	*node;

	index = 1;
	node = ft_lstnew(argv[0], 0, ft_threejoin(SURLINE, argv[0], ENDLINE));
	while(argv[index])
	{
		ft_lstaddnext(&node, ft_lstnew(argv[index], 0, ft_threejoin(SURLINE, argv[index], ENDLINE)));
		index++;
	}
	return (node);
}
