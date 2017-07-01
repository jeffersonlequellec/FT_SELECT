/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:49:13 by jefferso          #+#    #+#             */
/*   Updated: 2017/06/07 14:20:32 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarray(char **array)
{
	size_t	index;

	index = 0;
	while (array[index])
	{
		ft_putendl(array[index]);
		index++;
	}
}
