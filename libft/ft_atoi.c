/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:31 by jle-quel          #+#    #+#             */
/*   Updated: 2017/03/22 16:06:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						index;
	int						neg;
	unsigned long long		value;

	index = 0;
	neg = 1;
	value = 0;
	while (*str == ' ' || *str == '\r' || *str == '\t' || *str == '\f'
			|| *str == '\v' || *str == '\n')
		str++;
	neg = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(str[index]))
	{
		value = value * 10 + str[index] - '0';
		index++;
	}
	if (index > 19 || value > 9223372036854775807)
		return ((neg == 1) ? -1 : 0);
	return (neg * (int)value);
}
