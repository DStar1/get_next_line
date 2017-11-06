/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/11/03 20:54:55 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_str(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[0] && str[0][i] != '\0')
	{
		if (str[0][i] == '\n')
		{
			*line = ft_strsub(str[0], 0, i);
			tmp = str[0];
			str[0] = ft_strsub(str[0], i + 1, ft_strlen(str[0]) - i);
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Defined macros to return -1 if a malloc fails
** and to return 1 if it works to save lines
** if (ret == -1)
** 	return (-1); = RETURN_NEG1((ret == -1)); //difined as MACRO
*/

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*str;

	RETURN_NEG1((fd < 0 || !line));
	RETURN_1((str && check_str(&str, line)));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		RETURN_NEG1((ret == -1));
		if (!str)
			RETURN_NEG((str = ft_strnew(0)));
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	RETURN_1((check_str(&str, line) && ret > 0));
	if ((str && ret == 0 && ft_strlen(str)))
	{
		*line = ft_strsub(str, 0, ft_strlen(str));
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}
