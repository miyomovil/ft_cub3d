/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:33:33 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:33:04 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pxl_to_img(t_map *ptr, int x, int y)
{
	int n;

	if (x < ptr->winx && y < ptr->winy)
	{
		n = abs((((y * (ptr->h[ptr->id] * 4) - ptr->winy * (ptr->h[ptr->id] * 2)
			+ ptr->lineheight * (ptr->h[ptr->id] * 2)) * ptr->h[ptr->id])
					/ ptr->lineheight) / (ptr->h[ptr->id] * 4));
		ft_memcpy(ptr->img_ptr + (ptr->wbpp[ptr->id] / 8) * ptr->winx * y
			+ x * (ptr->wbpp[ptr->id] / 8),
			&ptr->wdata[ptr->id][n % ptr->h[ptr->id] * ptr->wsl[ptr->id] +
			ptr->x_text % ptr->w[ptr->id] *
			ptr->wbpp[ptr->id] / 8], sizeof(int));
	}
}

void	auxline(t_map *ptr)
{
	if (ptr->side == 1 && ptr->raydiry < 0)
		ptr->id = 0;
	ptr->x_text = (int)(ptr->x_wall * (double)ptr->w[ptr->id]);
	ptr->x_text = abs(ptr->x_text);
	while (ptr->j <= ptr->drawend)
		put_pxl_to_img(ptr, ptr->col, ptr->j++);
	while (ptr->j < ptr->winy)
	{
		ft_memcpy(ptr->img_ptr + 4 * ptr->winx * ptr->j +
			ptr->col * 4, &ptr->c, sizeof(int));
		ptr->j++;
	}
}

void	ft_verline(t_map *ptr)
{
	ptr->j = 0;
	while (ptr->j < ptr->drawstart)
	{
		ft_memcpy(ptr->img_ptr + 4 * ptr->winx *
			ptr->j + ptr->col * 4,
			&ptr->f, sizeof(int));
		ptr->j++;
	}
	ptr->j = ptr->drawstart;
	if (ptr->side == 0)
	{
		ptr->id = 3;
		ptr->x_wall = ptr->posy + ptr->perpwalldist * ptr->raydiry;
	}
	else
	{
		ptr->id = 4;
		ptr->x_wall = ptr->posx + ptr->perpwalldist * ptr->raydirx;
	}
	if (ptr->side == 0 && ptr->raydirx > 0)
		ptr->id = 2;
	auxline(ptr);
}
