/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:32:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/20 19:18:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned char		*s1;
	const unsigned char	*s2;

	index = 0;
	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s2[index] == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
