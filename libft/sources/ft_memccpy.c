/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 11:10:38 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 03:04:06 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	i = 0;
	dest2 = (char *)dst;
	src2 = (char *)src;
	while (i < n)
	{
		dest2[i] = src2[i];
		if ((unsigned char)src2[i] == (unsigned char)c)
		{
			return ((char *)dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
