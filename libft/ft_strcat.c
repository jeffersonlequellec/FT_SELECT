/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:34:45 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/13 11:14:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		index;
	int		len;

	index = 0;
	len = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[len] != '\0')
	{
		s1[index] = s2[len];
		index++;
		len++;
	}
	s1[index] = '\0';
	return (s1);
}
