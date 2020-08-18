/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:52 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:50:23 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		put_spr(t_map *ptr)
{
	ptr->sprite[ptr->count].texy = fabs((ptr->countb -
		ptr->sprite[ptr->count].spstarty) / (ptr->sprite[ptr->count].sph /
		(double)ptr->h[7]));
	if (ptr->wdata[7][ptr->sprite[ptr->count].texy * ptr->wsl[7] +
		ptr->sprite[ptr->count].texx * ptr->wbpp[7] / 8] != 0)
		ft_memcpy(ptr->img_ptr + (ptr->wbpp[7] / 8) * ptr->winx * ptr->countb +
			ptr->stripe * (ptr->wbpp[7] / 8),
			&ptr->wdata[7][ptr->sprite[ptr->count].texy * ptr->wsl[7] +
			ptr->sprite[ptr->count].texx * ptr->wbpp[7] / 8], sizeof(int));
	ptr->countb++;
}

void		dy(t_map *ptr)
{
	ptr->stripe = ptr->sprite[ptr->count].spstartx - 1;
	while (ptr->stripe < ptr->sprite[ptr->count].spendx)
	{
		ptr->sprite[ptr->count].texx = (int)((ptr->stripe -
			ptr->sprite[ptr->count].spstartx) / (ptr->sprite[ptr->count].spw /
			(double)ptr->w[7]));
		ptr->countb = ptr->sprite[ptr->count].spstarty;
		if (ptr->sprite[ptr->count].changey > 0 && ptr->stripe > 0 &&
			ptr->stripe < ptr->winx
			&& ptr->sprite[ptr->count].changey < ptr->zbuffer[ptr->stripe])
		{
			while (ptr->countb < ptr->sprite[ptr->count].spendy)
				put_spr(ptr);
		}
		ptr->stripe++;
	}
	ptr->obj = 0;
}

void		calc_transf(t_map *ptr)
{
	double	inv_det;
	double	calc_det;

	calc_det = (ptr->planex * ptr->diry - ptr->dirx * ptr->planey);
	inv_det = 1.0 / calc_det;
	ptr->sprite[ptr->count].changex = inv_det * (ptr->diry *
		ptr->sprite[ptr->count].spritex - ptr->dirx *
		ptr->sprite[ptr->count].spritey);
	ptr->sprite[ptr->count].changey = inv_det * (-ptr->planey *
		ptr->sprite[ptr->count].spritex + ptr->planex *
		ptr->sprite[ptr->count].spritey);
	ptr->sprite[ptr->count].scx = (int)((ptr->winx / 2) *
		(1 + ptr->sprite[ptr->count].changex /
		ptr->sprite[ptr->count].changey));
	ptr->sprite[ptr->count].sph = abs((int)(ptr->winy /
		ptr->sprite[ptr->count].changey));
	ptr->sprite[ptr->count].spw = abs((int)(ptr->winy /
		ptr->sprite[ptr->count].changey));
}

void		calc_sprite_place(t_map *ptr)
{
	ptr->sprite[ptr->count].spstarty = -ptr->sprite[ptr->count].sph / 2 +
		ptr->winy / 2;
	if (ptr->sprite[ptr->count].spstarty < 0)
		ptr->sprite[ptr->count].spstarty = 0;
	ptr->sprite[ptr->count].spendy = ptr->sprite[ptr->count].sph / 2 +
		ptr->winy / 2;
	if (ptr->sprite[ptr->count].spendy >= ptr->winy)
		ptr->sprite[ptr->count].spendy = ptr->winy - 1;
	ptr->sprite[ptr->count].spstartx = -1 * ptr->sprite[ptr->count].spw / 2 +
		ptr->sprite[ptr->count].scx;
	if (ptr->sprite[ptr->count].spstartx < 0)
		ptr->sprite[ptr->count].spstartx = 0;
	ptr->sprite[ptr->count].spendx = ptr->sprite[ptr->count].spw / 2 +
		ptr->sprite[ptr->count].scx;
	if (ptr->sprite[ptr->count].spendx >= ptr->winx)
		ptr->sprite[ptr->count].spendx = ptr->winx - 1;
}

void		raysprite(t_map *ptr)
{
	ptr->count = 0;
	while (ptr->count < ptr->numsprite)
	{
		ptr->sprite[ptr->count].spritex =
			ptr->sprite[ptr->spriteorder[ptr->count]].spriteposx - ptr->posx;
		ptr->sprite[ptr->count].spritey =
			ptr->sprite[ptr->spriteorder[ptr->count]].spriteposy - ptr->posy;
		calc_transf(ptr);
		calc_sprite_place(ptr);
		dy(ptr);
		ptr->count++;
	}
}
