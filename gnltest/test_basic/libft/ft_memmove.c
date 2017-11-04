/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:15:51 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/05 21:07:14 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*src_2;
	char	*dest_2;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * n);
	if (!tmp)
		return (NULL);
	src_2 = (char *)src;
	dest_2 = (char *)dest;
	i = 0;
	while (i < n)
	{
		tmp[i] = src_2[i];
		++i;
	}
	i = 0;
	while (i < n)
	{
		dest_2[i] = tmp[i];
		++i;
	}
	return (dest);
}
