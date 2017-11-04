/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 10:58:46 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 10:58:49 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*tmp;
	unsigned int	i;

	tmp = s;
	i = 0;
	while (*tmp)
	{
		f(i, tmp);
		i++;
		tmp++;
	}
}
