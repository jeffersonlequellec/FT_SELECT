/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:55:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/22 16:38:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_letters(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		words;
	char	**tab;

	if (!s || !c)
		return (0);
	i = 0;
	words = ft_countwords(s, c);
	tab = (char**)malloc(sizeof(tab) * words + 1);
	if (!tab)
		return (0);
	while (words--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, count_letters(s, c));
		if (!tab[i])
			return (0);
		s = s + count_letters(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
