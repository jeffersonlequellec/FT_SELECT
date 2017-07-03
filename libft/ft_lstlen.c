/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:37:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/03 17:10:22 by jefferson        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *node)
{
	size_t	ret;
	t_list	*temp;

	ret = 0;
	temp = node;
	while (temp)
	{
		ret++;
		temp = temp->next;
	}
	return (ret);
}
