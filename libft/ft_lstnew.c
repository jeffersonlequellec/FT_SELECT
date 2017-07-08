/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:54:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/08 14:31:16 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const char *content, size_t content_size, char *color)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		node->content = ft_strdup(content);
		node->color = color;
		node->content_size = content_size;
		if (!node->content || !node->color)
		{
			free(node);
			return (NULL);
		}
	}
	node->next = NULL;
	return (node);
}
