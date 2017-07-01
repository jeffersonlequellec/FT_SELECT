/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:21:22 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/19 10:09:15 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen((char*)s);
	while (index > 0 && s[index] != (char)c)
		index--;
	if (s[index] == (char)c)
		return ((char*)s + index);
	return (NULL);
}
