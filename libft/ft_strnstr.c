/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 09:31:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/19 10:08:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int				index;
	const char		*len;

	len = big + n;
	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0' && big < len)
	{
		index = 0;
		while (*big == *little && big < len)
		{
			little++;
			big++;
			index++;
			if (*little == '\0')
				return ((char*)(big - index));
		}
		big = big - index;
		little = little - index;
		big++;
	}
	return (NULL);
}
