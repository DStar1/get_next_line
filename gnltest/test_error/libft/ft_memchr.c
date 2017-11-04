/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:12:30 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 20:46:07 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pt;
	int				i;

	pt = (unsigned char *)s;
	i = 0;
	while (i < (int)n)
	{
		if (*pt == (unsigned char)c)
			return ((void *)pt);
		pt++;
		i++;
	}
	return (NULL);
}
