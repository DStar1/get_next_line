/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:01:19 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 23:06:52 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		while (len > 0)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
