/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:09 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:33:19 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		doscreenshot(t_map *ptr)
{
	int file;
	int filesize;
	int	pad;

	pad = (4 - ((int)ptr->winx * 3) % 4) % 4;
	filesize = 60 + (3 * ((int)ptr->winx + pad) * (int)ptr->winy);
	remove("screenshot.bmp");
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, 777)) < 0)
		return (0);
	if (!bmp_header(file, filesize, ptr))
		return (0);
	if (!bmp_data(file, ptr, pad))
		return (0);
	close(file);
	return (1);
}

void	to_img(t_map *ptr)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img, 0, 0);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->wlone[5], ptr->fpposx, ptr->fpposy);
	if (ptr->screenshot == 1)
	{
		doscreenshot(ptr);
		exit(1);
	}
	mlx_destroy_image(ptr->mlx_ptr, ptr->img);
}
