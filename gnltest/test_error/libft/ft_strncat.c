/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:27:31 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 17:19:50 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*pt1;
	char	*pt2;

	pt1 = s1;
	pt2 = (char *)s2;
	while (*pt1)
		pt1++;
	while (n != 0)
	{
		*pt1 = *pt2;
		pt1++;
		pt2++;
		n--;
	}
	*pt1 = '\0';
	return (s1);
}
