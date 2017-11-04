/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:39:22 by lnagy             #+#    #+#             */
/*   Updated: 2016/04/05 21:27:57 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] && n)
	{
		if (n < ft_strlen(s2))
			return (NULL);
		if (!ft_strncmp(&s1[i], s2, ft_strlen((char*)s2)))
			return ((char*)&s1[i]);
		i++;
		n--;
	}
	return (NULL);
}
