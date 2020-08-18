/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:32:27 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 07:18:45 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESQ 65307
# define KEY_SHIFT 65507
# include <X11/Xlib.h>
# include "../minilibx_linux/mlx.h"

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 1
# define MAXX 1920
# define MAXY 1080

typedef struct		s_sprite
{
	double			spritex;
	double			spritey;
	double			changex;
	double			changey;
	int				scx;
	int				sph;
	int				spw;
	int				spstarty;
	int				spendy;
	int				spstartx;
	int				spendx;
	int				texx;
	int				texy;
	double			spriteposx;
	double			spriteposy;
}					t_sprite;

typedef struct		s_map
{
	char			*mapchar;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	f;
	unsigned int	c;
	int				winy;
	int				winx;
	int				width;
	int				height;
	int				**maparray;
	int				y;
	int				x;
	int				n;
	char			dir;
	int				initialdir;
	double			posx;
	double			posy;
	int				screenshot;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*wlone[8];
	char			*wdata[8];
	int				wbpp[8];
	int				wendian[8];
	int				wsl[8];
	int				h[8];
	int				w[8];
	int				col;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camera;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				color;
	int				j;
	char			*img_ptr;
	int				id;
	double			x_wall;
	int				x_text;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
	int				fpposx;
	int				fpposy;
	int				alturalinea;
	int				butta;
	int				buttw;
	int				buttl;
	int				buttr;
	int				butts;
	int				buttd;
	int				buttesq;
	int				presshift;
	double			oldplanex;
	double			olddirx;
	double			zbuffer[4000];
	int				numsprite;
	t_sprite		*sprite;
	int				obj;
	int				*spriteorder;
	double			*spritedistance;
	int				stripe;
	int				count;
	int				countb;
	int				pos;
	int				r;
	int				g;
	int				b;
}					t_map;

void				readfile(int argc, char **flname, t_map *ptr);
int					get_next_line(int fd, char **line);
int					prsnam(char **argv);
void				info(t_map *ptr, char *line);
void				read_map(t_map *ptr);
void				enter_matrix(t_map *ptr);
void				initvars(t_map *ptr);
void				stringarray(t_map *ptr);
void				mapchars(t_map *ptr);
int					get_width(char *str);
int					get_height(char *str);
int					checkmap(t_map *ptr);
void				openall(t_map *ptr);
void				ft_verline(t_map *ptr);
void				wall_texture(t_map *ptr);
void				othertexture(t_map *ptr);
void				raycasting(t_map *ptr);
void				auxline(t_map *ptr);
void				auxlinetwo(t_map *ptr);
void				put_pxl_to_img(t_map *ptr, int x, int y);
void				to_img(t_map *ptr);
void				raycauxthree(t_map *ptr);
int					nopulsed(int key, t_map *ptr);
int					pulsed(int key, t_map *ptr);
int					deal_key(t_map *ptr);
int					bmp_header(int fd, int filesize, t_map *ptr);
int					bmp_data(int file, t_map *ptr, int pad);
int					ft_close(t_map *ptr, int win);
void				draw_sprite(t_map *ptr);
void				ft_swap_int(int *a, int *b);
void				ft_swap_double(double *a, double *b);
void				raysprite(t_map *ptr);
void				spritepos(t_map *ptr, int x, int y);
int					ft_atoi_color(char *line, int *i);
int					error(int i);
#endif
