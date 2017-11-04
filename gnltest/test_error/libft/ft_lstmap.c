/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:40:24 by alouisy-          #+#    #+#             */
/*   Updated: 2016/01/04 16:40:26 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;

	if (lst != NULL && f != NULL)
	{
		newlst = f(lst);
		if (newlst != NULL && lst->next != NULL)
			newlst->next = ft_lstmap(lst->next, f);
		return (newlst);
	}
	return (NULL);
}
