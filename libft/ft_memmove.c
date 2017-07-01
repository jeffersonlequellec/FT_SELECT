/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:44:59 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/19 10:07:12 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					index;
	unsigned char			*s1;
	const unsigned char		*s2;

	index = 0;
	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	if (s1 > s2)
	{
		s1 = s1 + len - 1;
		s2 = s2 + len - 1;
		while (index < len)
		{
			*s1-- = *s2--;
			index++;
		}
	}
	else
		while (index++ < len)
			*s1++ = *s2++;
	return (dst);
}
