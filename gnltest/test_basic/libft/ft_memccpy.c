/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:15:29 by lnagy             #+#    #+#             */
/*   Updated: 2015/12/30 19:15:30 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tmp;
	char	*src_2;
	size_t	i;

	i = 0;
	tmp = (char *)dest;
	src_2 = (char *)src;
	while (i < n)
	{
		tmp[i] = src_2[i];
		if (tmp[i] == (char)c)
			return ((char *)dest + i + 1);
		++i;
	}
	return (NULL);
}
