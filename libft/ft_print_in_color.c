/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_in_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:43:39 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/07 15:43:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_in_color(char *str, char *color)
{
	char	*ret;

	ret = ft_memalloc(ft_strlen(str) + ft_strlen(color) * 2 + 1);
	ft_strcpy(ret, color);
	ft_strcat(ret, str);
	ft_strcat(ret, "\x1B[0m");
	ft_putendl(ret);
	ft_strdel(&ret);
}
