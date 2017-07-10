/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:07:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/07/10 12:11:12 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_lol(char *str)
{
	str++;
	ft_putstr(str);
}

int		main(void)
{
	// char	str[2];
	char	*str;

	str = "Hello";


	// str[0] = 'h';
	// str[1] = 'e';
	ft_lol(str);
	return (0);
}
