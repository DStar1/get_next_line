/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:52:46 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/17 18:31:30 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*pt;

	i = 0;
	pt = (char *)b;
	while (i < (int)len)
	{
		pt[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
