/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 11:12:41 by jefferso          #+#    #+#             */
/*   Updated: 2017/06/07 14:52:52 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddnext(t_list **node, t_list *new)
{
	t_list	*temp;

	temp = *node;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
