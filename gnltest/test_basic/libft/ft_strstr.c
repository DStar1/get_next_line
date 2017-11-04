/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:10:54 by lnagy             #+#    #+#             */
/*   Updated: 2015/12/16 18:29:59 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!ft_strcmp(s1, s2) || !s2)
		return ((char *)s1);
	while (s1[i])
	{
		if (!ft_strncmp(&s1[i], s2, ft_strlen((char*)s2)))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
