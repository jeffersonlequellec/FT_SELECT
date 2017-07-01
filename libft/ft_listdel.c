/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 10:28:46 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/01 10:30:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellst(t_list **node)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *node;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		ft_strdel(&temp2->content);
		free(temp2);
	}
}
