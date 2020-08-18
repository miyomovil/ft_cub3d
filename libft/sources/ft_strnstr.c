/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:34:11 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 04:15:16 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*a;
	char	*b;

	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	if (b[0] == '\0')
		return (a);
	while (a[i] != '\0' && i < n)
	{
		j = 0;
		while (a[i + j] != '\0' && i + j < n && a[i + j] == b[j])
		{
			if (b[j + 1] == '\0')
				return (&a[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
