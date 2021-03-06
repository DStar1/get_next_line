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

/*
** multiple filedescriptors
*/

int		check_str(char **str, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd] && str[fd][i] != '\0')
	{
		if (str[fd][i] == '\n')
		{
			*line = ft_strsub(str[fd], 0, i);
			tmp = str[fd];
			str[fd] = ft_strsub(str[fd], i + 1, ft_strlen(str[fd]) - i);
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
	static char		*str[300];

	RETURN(-1, (fd < 0 || !line));
	RETURN(1, (str[fd] && check_str((char**)str, line, fd)));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		RETURN(-1, (ret == -1));
		if (!str[fd])
			RETURN(-1, !(str[fd] = ft_strnew(0)));
		buff[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	RETURN(1, (check_str((char**)str, line, fd) && ret > 0));
	if ((str[fd] && ret == 0 && ft_strlen(str[fd])))
	{
		*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = NULL;
		return (1);
	}
	return (0);
}
