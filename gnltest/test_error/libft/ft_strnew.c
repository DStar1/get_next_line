/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:23:25 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 17:16:22 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*pt;

	pt = NULL;
	i = 0;
	pt = malloc(sizeof(char) * (size + 1));
	if (pt == NULL)
		return (NULL);
	while (i < (int)size + 1)
	{
		pt[i] = '\0';
		i++;
	}
	return (pt);
}
