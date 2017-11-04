/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:01:07 by alouisy-          #+#    #+#             */
/*   Updated: 2015/12/29 23:16:43 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_tab(char *str, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}

static int	ft_lentab(char *str, char c, int first)
{
	int		len;

	len = 0;
	while (str[first] != c && str[first])
	{
		len++;
		first++;
	}
	return (len);
}

static char	*ft_filltab(char *str, char *tab, char c, int first)
{
	int		i;

	i = 0;
	while (str[first] && str[first] != c)
	{
		tab[i] = str[first];
		i++;
		first++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	**ft_maketab(char **tab, char *str, char c, int first)
{
	int		len;
	int		i;
	int		j;

	i = first;
	j = 0;
	while (str[i])
	{
		len = ft_lentab(str, c, first);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j])
		{
			tab[j] = ft_filltab(str, tab[j], c, first);
			j++;
			i += ft_lentab(str, c, first);
			while (str[i] == c && str[i])
				i++;
			first = i;
		}
		else
			return (NULL);
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_tab((char *)s, c);
		tab = (char **)malloc(sizeof(char *) * (size + 1));
		i = 0;
		if (tab)
		{
			while (s[i] == c && s[i])
				i++;
			tab = ft_maketab(tab, (char *)s, c, i);
			return (tab);
		}
		return (NULL);
	}
	return (NULL);
}
