/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 11:22:02 by jle-quel          #+#    #+#             */
/*   Updated: 2017/06/24 11:22:07 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_threejoin(char *s1, char *separator, char *s2)
{
	char	*str;

	str = ft_memalloc(ft_strlen(s1) + ft_strlen(separator) + ft_strlen(s2) + 1);
	ft_strcpy(str, s1);
	ft_strcat(str, separator);
	ft_strcat(str, s2);
	return (str);
}
