/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:37 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:33:52 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			prsnam(char **argv)
{
	char *aux;

	if (!(aux = ft_strchr(argv[1], '.')))
		return (-1);
	if (*(++aux) != 'c')
		return (-1);
	if (*(++aux) != 'u')
		return (-1);
	if (*(++aux) != 'b')
		return (-1);
	return (1);
}

static int	checkborder(t_map *ptr)
{
	int i;

	i = -1;
	while (i++ < ptr->width)
		if (ptr->maparray[0][i] != 1 && ptr->maparray[0][i] != 9)
			return (-1);
	i = -1;
	while (i++ < ptr->width)
		if (ptr->maparray[ptr->height][i] != 1 &&
			ptr->maparray[ptr->height][i] != 9)
			return (-1);
	i = -1;
	while (i++ < ptr->height)
		if (ptr->maparray[i][0] != 1 && ptr->maparray[i][0] != 9)
			return (-1);
	i = -1;
	while (i++ < ptr->height)
		if (ptr->maparray[i][ptr->width] != 1 &&
			ptr->maparray[i][ptr->width] != 9)
			return (-1);
	return (1);
}

static void	getdirandpos(t_map *ptr, int x, int y)
{
	ptr->pos++;
	ptr->posx = x + 0.5;
	ptr->posy = y + 0.5;
	if (ptr->dir == 'S')
	{
		ptr->dirx = 1;
		ptr->diry = 0;
		ptr->planex = 0;
		ptr->planey = -0.66;
	}
	if (ptr->dir == 'W')
	{
		ptr->dirx = 0;
		ptr->diry = -1;
		ptr->planex = -0.66;
		ptr->planey = 0;
	}
	if (ptr->dir == 'E')
	{
		ptr->dirx = 0;
		ptr->diry = 1;
		ptr->planex = 0.66;
		ptr->planey = 0;
	}
}

static int	checkcontent(t_map *ptr)
{
	int	i;
	int	j;

	i = 1;
	while (i < ptr->height)
	{
		j = 0;
		while (j < ptr->width)
		{
			ptr->maparray[i][j] == 3 ? getdirandpos(ptr, i, j) : 0;
			ptr->maparray[i][j] == 2 ? spritepos(ptr, i, j) : 0;
			if (((ptr->maparray[i][j] == 0) || (ptr->maparray[i][j] == 2) ||
				(ptr->maparray[i][j] == 3)) && ((ptr->maparray[i - 1][j] == 9)
				|| (ptr->maparray[i + 1][j] == 9) ||
				(ptr->maparray[i][j - 1] == 9) ||
				(ptr->maparray[i][j + 1] == 9)))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			checkmap(t_map *ptr)
{
	if (checkborder(ptr) == -1)
		return (error(7));
	if (checkcontent(ptr) == -1)
		return (error(6));
	if (ptr->pos > 1)
		return (error(5));
	if (ptr->no == NULL || ptr->so == NULL || ptr->we == NULL ||
		ptr->ea == NULL)
		return (-1);
	if (ptr->winx > MAXX)
		ptr->winx = MAXX;
	if (ptr->winy > MAXY)
		ptr->winy = MAXY;
	return (1);
}
