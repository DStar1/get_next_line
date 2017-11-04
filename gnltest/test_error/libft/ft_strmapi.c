/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:00:14 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 23:08:53 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*pt;
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen((char *)s);
	pt = (char *)malloc(sizeof(*pt) * (len + 1));
	if (s && pt)
	{
		while (s[i] != 0)
		{
			pt[i] = f(i, s[i]);
			i++;
		}
		pt[i] = '\0';
		return (pt);
	}
	return (NULL);
}
