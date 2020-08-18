/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:20:13 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 04:01:47 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	int					neg;

	neg = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (num > __LONG_LONG_MAX__ || i >= 19)
		{
			if (neg == 1)
				return (-1);
			else
				return (0);
		}
		num = num * 10 + (str[i++] - 48);
	}
	return ((int)num * neg);
}
