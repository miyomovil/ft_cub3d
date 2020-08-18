/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:23 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:46:49 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	w_and_s(t_map *ptr)
{
	if (ptr->buttw == 1)
	{
		if ((ptr->maparray[(int)(ptr->posx + ptr->dirx *
			(ptr->movespeed + 0.6))][(int)ptr->posy]) != 1)
			ptr->posx += ptr->dirx * ptr->movespeed;
		if ((ptr->maparray[(int)ptr->posx][(int)(ptr->posy + ptr->diry *
			(ptr->movespeed + 0.6))]) != 1)
			ptr->posy += ptr->diry * ptr->movespeed;
	}
	if (ptr->butts == 1)
	{
		if ((ptr->maparray[(int)(ptr->posx - ptr->dirx *
			(ptr->movespeed + 0.6))][(int)ptr->posy]) != 1)
			ptr->posx -= ptr->dirx * ptr->movespeed;
		if ((ptr->maparray[(int)ptr->posx][(int)(ptr->posy -
			ptr->diry * (ptr->movespeed + 0.6))]) != 1)
			ptr->posy -= ptr->diry * ptr->movespeed;
	}
}

void	a_and_d(t_map *ptr)
{
	if (ptr->butta == 1)
	{
		if ((ptr->maparray[(int)(ptr->posx - ptr->diry *
			(ptr->movespeed + 0.6))][(int)ptr->posy]) != 1)
			ptr->posx -= ptr->diry * ptr->movespeed;
		if ((ptr->maparray[(int)ptr->posx][(int)(ptr->posy +
			ptr->dirx * (ptr->movespeed + 0.6))]) != 1)
			ptr->posy += ptr->dirx * ptr->movespeed;
	}
	if (ptr->buttd == 1)
	{
		if ((ptr->maparray[(int)(ptr->posx + ptr->diry *
			(ptr->movespeed + 0.6))][(int)ptr->posy]) != 1)
			ptr->posx += ptr->diry * ptr->movespeed;
		if ((ptr->maparray[(int)ptr->posx][(int)(ptr->posy -
			ptr->dirx * (ptr->movespeed + 0.6))]) != 1)
			ptr->posy -= ptr->dirx * ptr->movespeed;
	}
}

void	l_and_r(t_map *ptr)
{
	ptr->olddirx = ptr->dirx;
	if (ptr->buttl == 1)
	{
		ptr->dirx = ptr->dirx * cos(ptr->rotspeed) - ptr->diry *
					sin(ptr->rotspeed);
		ptr->diry = ptr->olddirx * sin(ptr->rotspeed) +
					ptr->diry * cos(ptr->rotspeed);
		ptr->oldplanex = ptr->planex;
		ptr->planex = ptr->planex * cos(-ptr->rotspeed)
			- ptr->planey * sin(ptr->rotspeed);
		ptr->planey = ptr->oldplanex * sin(ptr->rotspeed)
			+ ptr->planey * cos(-ptr->rotspeed);
	}
	if (ptr->buttr == 1)
	{
		ptr->dirx = ptr->dirx * cos(-ptr->rotspeed) - ptr->diry *
					sin(-ptr->rotspeed);
		ptr->diry = ptr->olddirx * sin(-ptr->rotspeed) +
					ptr->diry * cos(-ptr->rotspeed);
		ptr->oldplanex = ptr->planex;
		ptr->planex = ptr->planex * cos(-ptr->rotspeed) -
			ptr->planey * sin(-ptr->rotspeed);
		ptr->planey = ptr->oldplanex * sin(-ptr->rotspeed)
			+ ptr->planey * cos(-ptr->rotspeed);
	}
}

int		ft_close(t_map *ptr, int win)
{
	free(ptr->maparray);
	free(ptr);
	if (win == 1)
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->mlx_ptr);
	exit(0);
}

int		deal_key(t_map *ptr)
{
	raycasting(ptr);
	w_and_s(ptr);
	a_and_d(ptr);
	l_and_r(ptr);
	if (ptr->buttesq == 1)
		ft_close(ptr, 1);
	return (1);
}
