/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 10:59:03 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 23:09:17 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ptr;

	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	ptr = (char *)malloc(sizeof(*ptr) * len);
	i = 0;
	if (ptr)
	{
		while (*s1)
			ptr[i++] = *s1++;
		while (*s2)
			ptr[i++] = *s2++;
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
