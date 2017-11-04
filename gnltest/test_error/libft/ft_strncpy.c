/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:16:52 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 17:17:53 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int	i;

	i = 0;
	while (src[i] && len > 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	if (len > 0)
	{
		while (len > 0)
		{
			dest[i] = '\0';
			i++;
			len--;
		}
	}
	return (dest);
}
