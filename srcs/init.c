/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:16 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:39:12 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	initvars(t_map *ptr)
{
	ptr->no = NULL;
	ptr->so = NULL;
	ptr->we = NULL;
	ptr->ea = NULL;
	ptr->mlx_ptr = NULL;
	ptr->win_ptr = NULL;
	ptr->id = 0;
	ptr->movespeed = 0.12;
	ptr->rotspeed = 0.08;
	ptr->planex = 0;
	ptr->planey = 0.66;
	ptr->pos = 0;
	ptr->dirx = -1;
	ptr->diry = 0;
	ptr->sprite = NULL;
}

void	read_map(t_map *ptr)
{
	ptr->height = get_height(ptr->mapchar);
	ptr->width = get_width(ptr->mapchar);
	mapchars(ptr);
	enter_matrix(ptr);
}

void	readfile(int argc, char **flname, t_map *ptr)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	ptr->mapchar = ft_strdup("");
	if (!(fd = open(flname[1], O_RDONLY, 0)))
	{
		perror(flname[1]);
		strerror(fd);
		close(fd);
		exit(0);
	}
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		info(ptr, line);
		free(line);
	}
	close(fd);
	if (argc == 3)
		ptr->screenshot = 1;
	if (argc == 3 && ft_strncmp(flname[2], "--save", 6))
		exit(error(4) * -1);
}

void	openall(t_map *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->winx,
		ptr->winy, "CUB3D 42");
	wall_texture(ptr);
	ptr->fpposx = ptr->winx / 2 - ptr->w[5] / 2;
	ptr->fpposy = ptr->winy - ptr->h[5];
	raycasting(ptr);
	mlx_hook(ptr->win_ptr, 2, 1L << 0, nopulsed, ptr);
	mlx_hook(ptr->win_ptr, 3, 1L << 1, pulsed, ptr);
	mlx_hook(ptr->win_ptr, 17, 1L << 17, ft_close, ptr);
	mlx_loop_hook(ptr->mlx_ptr, deal_key, ptr);
	mlx_loop(ptr->mlx_ptr);
}
