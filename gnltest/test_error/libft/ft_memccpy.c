/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:25:00 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 11:38:45 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	i = 0;
	pt1 = (unsigned char *)src;
	pt2 = (unsigned char *)dst;
	while (i < n && *pt1 != (unsigned char)c)
	{
		*pt2 = *pt1;
		pt1++;
		pt2++;
		i++;
	}
	if (i == n)
		return (NULL);
	if (*pt1 == (unsigned char)c)
		*pt2 = *pt1;
	return ((void *)pt2 + 1);
}
