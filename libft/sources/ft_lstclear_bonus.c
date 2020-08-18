/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antomart <antomart@student42>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:36:55 by antomart          #+#    #+#             */
/*   Updated: 2020/08/18 02:56:28 by Antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = *lst;
	while (tmp2 != NULL)
	{
		tmp = tmp2->next;
		ft_lstdelone(tmp2, del);
		tmp2 = tmp;
	}
	*lst = NULL;
}
