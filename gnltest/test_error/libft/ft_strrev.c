/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:37:08 by alouisy-          #+#    #+#             */
/*   Updated: 2016/01/04 20:54:54 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	int		len;
	char	*str;

	i = 0;
	len = (int)ft_strlen(s) - 1;
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	while (len >= 0)
	{
		str[i] = s[len];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
