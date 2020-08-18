/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:38:25 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 04:02:58 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list		*element;

	if ((element = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	element->content = (void*)content;
	element->next = NULL;
	return (element);
}
