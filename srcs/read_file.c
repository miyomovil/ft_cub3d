/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:34:58 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 06:34:14 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		resolution(char *temp, t_map *ptr)
{
	int			i;
	int			aux;
	char		*temp2;

	i = 0;
	while (!(ft_isdigit(temp[i])))
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	ptr->winx = ft_atoi(temp2);
	free(temp2);
	while (temp[i] == ' ')
		i++;
	aux = i;
	while (ft_isdigit(temp[i]))
		i++;
	temp2 = ft_substr(temp, aux, i);
	ptr->winy = ft_atoi(temp2);
	free(temp2);
}

static char		*getstr(char *temp)
{
	while (*temp != '.')
		temp++;
	return (temp);
}

static int		getcolor(unsigned int *color, char *line, t_map *ptr)
{
	int			i;

	i = 0;
	while (line[i])
	{
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		ptr->r = ft_atoi_color(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		ptr->g = ft_atoi_color(line, &i);
		while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			i++;
		if (line[i] == '\0')
			break ;
		ptr->b = ft_atoi_color(line, &i);
	}
	*color = ptr->r * 256 * 256 + ptr->g * 256 + ptr->b;
	return (0);
}

static void		takeline(t_map *ptr, char *temp, char *line)
{
	char *temp2;

	temp = ft_strjoin(line, "\n");
	temp2 = ptr->mapchar;
	ptr->mapchar = ft_strjoin(ptr->mapchar, temp);
	free(temp2);
	free(temp);
}

void			info(t_map *ptr, char *line)
{
	char	*temp;
	int		len;

	len = ft_strlen(line);
	if ((temp = ft_strchr(line, 'R')))
		resolution(line, ptr);
	else if ((temp = ft_strnstr(line, "NO", len)))
		ptr->no = ft_strdup(getstr(line));
	else if ((temp = ft_strnstr(line, "SO", len)))
		ptr->so = ft_strdup(getstr(line));
	else if ((temp = ft_strnstr(line, "WE", len)))
		ptr->we = ft_strdup(getstr(line));
	else if ((temp = ft_strnstr(line, "EA", len)))
		ptr->ea = ft_strdup(getstr(line));
	else if ((temp = ft_strnstr(line, "S .", len)))
		ptr->s = ft_strdup(getstr(line));
	else if ((temp = ft_strchr(line, 'F')))
		getcolor(&ptr->f, line, ptr);
	else if ((temp = ft_strchr(line, 'C')))
		getcolor(&ptr->c, line, ptr);
	else if ((temp = ft_strchr(line, '1')))
		takeline(ptr, temp, line);
}
