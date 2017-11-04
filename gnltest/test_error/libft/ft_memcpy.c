/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:16:46 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 18:31:43 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;
	int		i;

	i = 0;
	p1 = (char *)src;
	p2 = (char *)dst;
	while (i < (int)n)
	{
		*p2 = *p1;
		p1++;
		p2++;
		i++;
	}
	return (dst);
}
