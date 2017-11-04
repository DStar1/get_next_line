/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 20:18:22 by alouisy-          #+#    #+#             */
/*   Updated: 2016/01/04 20:53:28 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	else
		return (0);
}