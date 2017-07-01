/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:21:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/16 13:52:02 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		index;
	size_t		size;

	index = 0;
	size = ft_strlen(src);
	if (dst || src)
	{
		while (index < len)
		{
			if (index > size)
				dst[index] = '\0';
			else
				dst[index] = src[index];
			index++;
		}
		return (dst);
	}
	return (NULL);
}
