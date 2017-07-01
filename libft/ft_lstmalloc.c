/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 22:58:01 by jefferso          #+#    #+#             */
/*   Updated: 2017/06/07 14:32:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmalloc(size_t len)
{
	t_list	*node;

	if (!len)
		return (NULL);
	if (!(node = ft_lstnew("\0", sizeof(char*))))
		return (NULL);
	while (len--)
		ft_lstaddnext(&node, ft_lstnew("\0", sizeof(char*)));
	return (node);
}
