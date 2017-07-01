/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:16:22 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/19 10:09:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		index;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		index = 0;
		while (*big == *little)
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
