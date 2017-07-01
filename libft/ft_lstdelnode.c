/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:52:45 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/07 15:07:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelnode(t_list *node)
{
	t_list	*temp;
	t_list	*rm;

	temp = node;
	rm = node;
	temp = temp->next;
	free(rm);
	return (temp);
}
