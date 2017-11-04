/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:16:10 by lnagy             #+#    #+#             */
/*   Updated: 2015/12/30 19:16:13 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	if (n == 0)
		return (0);
	while (tmp1[i] == tmp2[i] && i < n - 1)
		++i;
	return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
}
