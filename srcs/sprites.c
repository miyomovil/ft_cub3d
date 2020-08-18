/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:35:15 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 09:59:30 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			spritepos(t_map *ptr, int x, int y)
{
	ptr->sprite[ptr->numsprite].spriteposx = x + 0.5;
	ptr->sprite[ptr->numsprite].spriteposy = y + 0.5;
	ptr->numsprite++;
}

static	void	how_spot(int *spot)
{
	*spot = (*spot * 10) / 13;
	if (*spot == 9 || *spot == 10)
		*spot = 11;
	if (*spot < 1)
		*spot = 1;
}

static void		sortsprite(t_map *ptr)
{
	int		spot;
	int		swapped;
	int		i;
	int		j;

	spot = ptr->numsprite;
	while (spot > 1 || swapped)
	{
		how_spot(&spot);
		swapped = 0;
		i = 0;
		while (i < ptr->numsprite - spot)
		{
			j = i + spot;
			if (ptr->spritedistance[i] < ptr->spritedistance[j])
			{
				ft_swap_double(&ptr->spritedistance[i],
					&ptr->spritedistance[j]);
				ft_swap_int(&ptr->spriteorder[i], &ptr->spriteorder[j]);
				swapped = 1;
			}
			i++;
		}
	}
}

void			sprite_order(t_map *ptr)
{
	int		i;

	i = 0;
	ptr->spriteorder = malloc(ptr->numsprite * sizeof(int));
	ptr->spritedistance = malloc(ptr->numsprite * sizeof(double));
	while (i < ptr->numsprite)
	{
		ptr->spriteorder[i] = i;
		ptr->spritedistance[i] = ((ptr->posx - ptr->sprite[i].spritex) *
			(ptr->posx - ptr->sprite[i].spritex) +
			(ptr->posy - ptr->sprite[i].spritey) *
			(ptr->posy - ptr->sprite[i].spritey));
		i++;
	}
	sortsprite(ptr);
}

void			draw_sprite(t_map *ptr)
{
	sprite_order(ptr);
	raysprite(ptr);
}
