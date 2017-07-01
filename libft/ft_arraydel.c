/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:45:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/28 18:45:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char ***array, size_t len)
{
	size_t	index;
	char	**tmp;

	index = 0;
	tmp = *array;
	while (index < len)
	{
		free(tmp[index]);
		tmp[index] = NULL;
		index++;
	}
	free(tmp);
	tmp = NULL;
}
