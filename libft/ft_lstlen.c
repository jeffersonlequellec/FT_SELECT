/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:37:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/20 18:46:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **list)
{
	int		index;
	t_list	*node;

	index = 0;
	node = *list;
	while (node)
	{
		index++;
		node = node->next;
	}
	return (index);
}
