/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:33:12 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/16 13:56:01 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int			index;
	size_t		len;

	index = 0;
	len = 0;
	while (s1[index] != '\0')
		index++;
	while (len < n && s2[len] != '\0')
	{
		s1[index] = s2[len];
		index++;
		len++;
	}
	s1[index] = '\0';
	return (s1);
}
