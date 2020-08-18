/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:33:43 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 05:55:13 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error(int i)
{
	write(1, "Error\n", 7);
	if (i == 0)
		write(1, "Incorrect file entered\n", 24);
	else if (i == 1)
		write(1, "Check the map, it´s wrong\n", 28);
	else if (i == 2)
		write(1, "Wrong arguments, leaving CUB3D\n", 32);
	else if (i == 3)
		write(1, "Malloc error\n", 14);
	else if (i == 4)
		write(1, "Bad argument\n", 14);
	else if (i == 5)
		write(1, "Two or more players in the map\n", 32);
	else if (i == 6)
		write(1, "Wrong map, close walls\n", 1);
	else if (i == 7)
		write(1, "The border´s map are wrong\n", 29);
	return (-1);
}
