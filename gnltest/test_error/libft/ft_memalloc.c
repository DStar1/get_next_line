/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:07:24 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 23:11:12 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*pt;

	i = 0;
	pt = NULL;
	pt = (char *)malloc(size * sizeof(pt));
	if (pt == NULL)
		return (NULL);
	while (i < (int)size)
	{
		pt[i] = 0;
		i++;
	}
	return ((void *)pt);
}
