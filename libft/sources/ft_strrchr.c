/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:32:47 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 09:48:03 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i--)
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
