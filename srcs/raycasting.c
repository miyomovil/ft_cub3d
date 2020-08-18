/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:44 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:34:00 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycauxnext(t_map *ptr)
{
	if (ptr->side == 0)
		ptr->perpwalldist = (ptr->mapx - ptr->posx +
		(1 - ptr->stepx) / 2) / ptr->raydirx;
	else
		ptr->perpwalldist = (ptr->mapy - ptr->posy +
			(1 - ptr->stepy) / 2) / ptr->raydiry;
	ptr->lineheight = (int)(ptr->winy / ptr->perpwalldist);
	ptr->drawstart = -ptr->lineheight / 2 + ptr->winy / 2;
	if (ptr->drawstart < 0)
		ptr->drawstart = 0;
	ptr->drawend = ptr->lineheight / 2 + ptr->winy / 2;
	if (ptr->drawend >= ptr->winy)
		ptr->drawend = ptr->winy - 1;
	ft_verline(ptr);
	ptr->col++;
}

void	raycauxtwo(t_map *ptr)
{
	while (ptr->hit == 0)
	{
		if (ptr->sidedistx < ptr->sidedisty)
		{
			ptr->sidedistx += ptr->deltadistx;
			ptr->mapx += ptr->stepx;
			ptr->side = 0;
		}
		else
		{
			ptr->sidedisty += ptr->deltadisty;
			ptr->mapy += ptr->stepy;
			ptr->side = 1;
		}
		if (ptr->maparray[ptr->mapx][ptr->mapy] == 2)
			ptr->obj = 1;
		if (ptr->maparray[ptr->mapx][ptr->mapy] == 1)
			ptr->hit = 1;
	}
	raycauxnext(ptr);
}

void	raycaux(t_map *ptr)
{
	if (ptr->raydirx < 0)
	{
		ptr->stepx = -1;
		ptr->sidedistx = (ptr->posx - ptr->mapx) * ptr->deltadistx;
	}
	else
	{
		ptr->stepx = 1;
		ptr->sidedistx = (ptr->mapx + 1.0 - ptr->posx) * ptr->deltadistx;
	}
	if (ptr->raydiry < 0)
	{
		ptr->stepy = -1;
		ptr->sidedisty = (ptr->posy - ptr->mapy) * ptr->deltadisty;
	}
	else
	{
		ptr->stepy = 1;
		ptr->sidedisty = (ptr->mapy + 1.0 - ptr->posy) * ptr->deltadisty;
	}
	raycauxtwo(ptr);
}

void	raycasting(t_map *ptr)
{
	ptr->col = 0;
	ptr->img = mlx_new_image(ptr->mlx_ptr, ptr->winx, ptr->winy);
	ptr->img_ptr = mlx_get_data_addr(ptr->img, &ptr->bpp, &ptr->sl,
		&ptr->endian);
	while (ptr->col < ptr->winx)
	{
		ptr->camera = 2 * ptr->col / (double)ptr->winx - 1;
		ptr->raydirx = ptr->dirx + ptr->planex * ptr->camera;
		ptr->raydiry = ptr->diry + ptr->planey * ptr->camera;
		ptr->mapx = (int)ptr->posx;
		ptr->mapy = (int)ptr->posy;
		ptr->deltadistx = fabs((1 / ptr->raydirx));
		ptr->deltadisty = fabs((1 / ptr->raydiry));
		ptr->hit = 0;
		raycaux(ptr);
		ptr->zbuffer[ptr->col] = ptr->perpwalldist;
	}
	if (ptr->obj == 1)
		draw_sprite(ptr);
	to_img(ptr);
}
