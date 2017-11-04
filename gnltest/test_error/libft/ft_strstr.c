/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:54:02 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/30 00:26:05 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ps1;
	char	*ps2;
	char	*sv1;

	ps1 = (char *)s1;
	ps2 = (char *)s2;
	if (*ps2 == '\0')
		return (ps1);
	while (*ps1 != '\0')
	{
		sv1 = ps1 + 1;
		while (*ps2 == *ps1 && *ps2 != '\0')
		{
			ps2++;
			ps1++;
		}
		if (*ps2 == '\0')
			return (sv1 - 1);
		ps2 = (char *)s2;
		ps1 = sv1;
	}
	return (NULL);
}
