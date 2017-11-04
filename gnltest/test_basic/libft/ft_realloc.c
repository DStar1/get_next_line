/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noich <noich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 10:38:09 by noich             #+#    #+#             */
/*   Updated: 2016/01/07 11:47:21 by vrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *res;

	if ((res = ft_memalloc(new_size)) == 0)
		return (0);
	ft_bzero(res, new_size);
	ft_memcpy(res, ptr, old_size);
	ft_memdel(&ptr);
	return ((void *)res);
}
