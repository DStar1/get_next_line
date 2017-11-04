/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:21:20 by lnagy             #+#    #+#             */
/*   Updated: 2016/02/06 01:15:07 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*o;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((o = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		o[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		o[i + j] = s2[j];
		j++;
	}
	o[i + j] = '\0';
	return (o);
}
