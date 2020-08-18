/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:30 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:47:20 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	othertexture(t_map *ptr)
{
	ptr->wlone[5] = mlx_xpm_file_to_image(ptr->mlx_ptr,
		"./srcs/textures/eagle.xpm", &ptr->w[5], &ptr->h[5]);
	ptr->wdata[5] = mlx_get_data_addr(ptr->wlone[5],
		&ptr->wbpp[5], &ptr->wsl[5], &ptr->wendian[5]);
	ptr->wlone[7] = mlx_xpm_file_to_image(ptr->mlx_ptr,
		ptr->s, &ptr->w[7], &ptr->h[7]);
	ptr->wdata[7] = mlx_get_data_addr(ptr->wlone[7],
		&ptr->wbpp[7], &ptr->wsl[7], &ptr->wendian[7]);
	free(ptr->we);
	free(ptr->so);
	free(ptr->ea);
	free(ptr->no);
	free(ptr->s);
}

void	wall_texture(t_map *ptr)
{
	ptr->wlone[0] = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->we,
					&ptr->w[0], &ptr->h[0]);
	ptr->wdata[0] = mlx_get_data_addr(ptr->wlone[0],
		&ptr->wbpp[0], &ptr->wsl[0], &ptr->wendian[0]);
	ptr->wlone[2] = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->so,
					&ptr->w[2], &ptr->h[2]);
	ptr->wdata[2] = mlx_get_data_addr(ptr->wlone[2],
		&ptr->wbpp[2], &ptr->wsl[2], &ptr->wendian[2]);
	ptr->wlone[3] = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->no,
					&ptr->w[3], &ptr->h[3]);
	ptr->wdata[3] = mlx_get_data_addr(ptr->wlone[3],
		&ptr->wbpp[3], &ptr->wsl[3], &ptr->wendian[3]);
	ptr->wlone[4] = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->ea,
					&ptr->w[4], &ptr->h[4]);
	ptr->wdata[4] = mlx_get_data_addr(ptr->wlone[4],
		&ptr->wbpp[4], &ptr->wsl[4], &ptr->wendian[4]);
	othertexture(ptr);
}

int		pulsed(int key, t_map *ptr)
{
	if (key == KEY_W)
		ptr->buttw = 0;
	if (key == KEY_S)
		ptr->butts = 0;
	if (key == KEY_A)
		ptr->butta = 0;
	if (key == KEY_D)
		ptr->buttd = 0;
	if (key == KEY_LEFT)
		ptr->buttl = 0;
	if (key == KEY_RIGHT)
		ptr->buttr = 0;
	if (key == KEY_ESQ)
		ptr->buttr = 0;
	if (key == KEY_SHIFT)
		ptr->movespeed = 0.12;
	return (0);
}

int		nopulsed(int key, t_map *ptr)
{
	if (key == KEY_W)
		ptr->buttw = 1;
	if (key == KEY_S)
		ptr->butts = 1;
	if (key == KEY_A)
		ptr->butta = 1;
	if (key == KEY_D)
		ptr->buttd = 1;
	if (key == KEY_LEFT)
		ptr->buttl = 1;
	if (key == KEY_RIGHT)
		ptr->buttr = 1;
	if (key == KEY_ESQ)
		ptr->buttesq = 1;
	if (key == KEY_SHIFT)
		ptr->movespeed = 0.35;
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*ptr;

	if (argc == 2 || argc == 3)
	{
		if (!(ptr = malloc(sizeof(t_map))))
			return (error(3));
		if (prsnam(argv) == -1)
			return (error(0));
		initvars(ptr);
		readfile(argc, argv, ptr);
		read_map(ptr);
		if (checkmap(ptr) == -1)
			return (error(1));
		free(ptr->mapchar);
		openall(ptr);
		return (0);
	}
	return (error(2));
}
