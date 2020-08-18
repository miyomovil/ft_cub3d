/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:33:22 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:38:49 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_height(char *str)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			h++;
		i++;
	}
	return (h);
}

int			get_width(char *str)
{
	int		w;
	int		i;
	int		temp;

	w = 0;
	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			temp++;
		if (str[i] == '\n')
		{
			if (temp > w)
				w = temp - 1;
			temp = 0;
		}
		i++;
	}
	return (w);
}

void		mapchars(t_map *ptr)
{
	int	i;

	i = 0;
	while (ptr->mapchar[i] != '\0')
	{
		if (ptr->mapchar[i] == '\t')
			ptr->mapchar[i] = '8';
		if (ptr->mapchar[i] == ' ')
			ptr->mapchar[i] = '9';
		if (ptr->mapchar[i] == 'N' || ptr->mapchar[i] == 'S'
			|| ptr->mapchar[i] == 'W' || ptr->mapchar[i] == 'E')
		{
			ptr->dir = ptr->mapchar[i];
			ptr->mapchar[i] = '3';
		}
		if (ptr->mapchar[i] == '2')
			ptr->numsprite++;
		i++;
	}
	ptr->sprite = malloc(ptr->numsprite * sizeof(t_sprite));
	ptr->numsprite = 0;
}

void		stringarray(t_map *ptr)
{
	if (ptr->mapchar[ptr->n] == '8')
	{
		ptr->maparray[ptr->x][ptr->y++] = 9;
		ptr->maparray[ptr->x][ptr->y++] = 9;
		ptr->maparray[ptr->x][ptr->y++] = 9;
		ptr->maparray[ptr->x][ptr->y] = 9;
	}
	else if (ptr->mapchar[ptr->n] == '9')
		ptr->maparray[ptr->x][ptr->y] = 9;
	else if (ptr->mapchar[ptr->n] == '\n' || ptr->mapchar[ptr->n] == '\0')
	{
		while (ptr->y <= get_width(ptr->mapchar))
		{
			ptr->maparray[ptr->x][ptr->y] = 9;
			ptr->y++;
		}
		ptr->n -= 1;
	}
	else
		ptr->maparray[ptr->x][ptr->y] = ptr->mapchar[ptr->n] - 48;
	ptr->n++;
	ptr->y++;
}

void		enter_matrix(t_map *ptr)
{
	ptr->x = 0;
	ptr->n = 0;
	if (!(ptr->maparray = malloc(sizeof(int *) *
		(get_height(ptr->mapchar) + 1))))
		return ;
	while (ptr->x <= get_height(ptr->mapchar))
	{
		if (!(ptr->maparray[ptr->x] = malloc(sizeof(int) *
			(get_width(ptr->mapchar) + 1))))
			return ;
		ptr->y = 0;
		while (ptr->y <= get_width(ptr->mapchar))
			stringarray(ptr);
		ptr->n++;
		ptr->y = 0;
		ptr->x++;
	}
}
