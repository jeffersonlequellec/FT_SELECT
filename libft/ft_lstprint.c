/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:35:52 by jefferso          #+#    #+#             */
/*   Updated: 2017/06/07 14:33:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *node)
{
	t_list	*temp;

	temp = node;
	while (temp)
	{
		ft_putendl(temp->content);
		temp = temp->next;
	}
}
