/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:25:33 by jle-quel          #+#    #+#             */
/*   Updated: 2017/04/15 14:32:17 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;
	t_list		*node;

	if (alst)
	{
		node = *alst;
		while (node)
		{
			temp = node->next;
			del(node->content, node->content_size);
			free(node);
			node = temp;
		}
		*alst = NULL;
	}
}
