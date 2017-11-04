/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 22:17:40 by alouisy-          #+#    #+#             */
/*   Updated: 2016/01/04 20:32:29 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	str = ft_strnew(end - start + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
