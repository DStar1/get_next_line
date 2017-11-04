/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:18:44 by lnagy             #+#    #+#             */
/*   Updated: 2015/11/10 22:21:13 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*maplist;

	maplist = NULL;
	if (f)
	{
		while (lst)
		{
			ft_lstaddend(&maplist, f(lst));
			lst = lst->next;
		}
	}
	return (maplist);
}
