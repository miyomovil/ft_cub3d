/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:33:52 by Antomart          #+#    #+#             */
/*   Updated: 2020/08/18 04:40:41 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_sign(char str)
{
	if (str == '-' || str == '+')
	{
		if (str == '-')
			return (-1);
	}
	return (1);
}

int			ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int			ft_atoi_color(char *line, int *i)
{
	int	num;
	int	sg;

	num = 0;
	ft_spaceskip(line, i);
	sg = ft_sign(line[*i]);
	if (line[*i] == '-')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num * sg);
}
