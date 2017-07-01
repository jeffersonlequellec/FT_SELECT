/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:39:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/19 11:40:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *s, char c)
{
	int		index[2];

	index[0] = 0;
	index[1] = 0;
	while (*s != '\0')
	{
		if (index[0] == 1 && *s == c)
			index[0] = 0;
		if (index[0] == 0 && *s != c)
		{
			index[0] = 1;
			index[1]++;
		}
		s++;
	}
	return (index[1]);
}
