/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:54:47 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 02:39:57 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t x, size_t size)
{
	void	*result;

	result = malloc(size * x);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, x * size);
	return (result);
}
