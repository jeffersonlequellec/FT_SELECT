/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:37:48 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/01 10:37:52 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_populate_list(char **argv)
{
	size_t	index;
	t_list	*node;

	index = 1;
	node = ft_lstnew(argv[0], 0);
	while(argv[index])
	{
		ft_lstaddnext(&node, ft_lstnew(argv[index], 0));
		index++;
	}
	return (node);
}
