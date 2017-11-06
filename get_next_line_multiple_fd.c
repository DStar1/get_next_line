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

//multiple filedescriptors

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
			//free(tmp[fd]);
			//for ( int j = 0; j <= 255; j++ )
				//free(tmp);
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
	static char		*str[255];
	//char ***str1;

	RETURN_NEG1((fd < 0 || !line));
	RETURN_1((str[fd] && check_str((char**)str, line, fd)));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		RETURN_NEG1((ret == -1));
		if (!str[fd])
			RETURN_NEG((str[fd] = ft_strnew(0)));
		buff[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	// str1 = str;
	RETURN_1((check_str((char**)str, line, fd) && ret > 0));
	//str = str1;
	//free(str1);
	if ((str[fd] && ret == 0 && ft_strlen(str[fd])))
	{
		*line = ft_strsub(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		//for ( int j = 0; j < 255; j++ )
		//	free(str[fd]);
		str[fd] = NULL;
		return (1);
	}
	//free(str);
	return (0);
}



// int		ft_new_line(char **s, char **line, int fd, int ret)
// {
// 	char	*tmp;
// 	int		len;

// 	len = 0;
// 	while (s[fd][len] != '\n' && s[fd][len] != '\0')
// 		len++;
// 	if (s[fd][len] == '\n')
// 	{
// 		*line = ft_strsub(s[fd], 0, len);
// 		tmp = ft_strdup(s[fd] + len + 1);
// 		free(s[fd]);
// 		s[fd] = tmp;
// 	}
// 	else if (s[fd][len] == '\0')
// 	{
// 		if (ret == BUFF_SIZE)
// 			return (get_next_line(fd, line));
// 		*line = ft_strdup(s[fd]);
// 		free(s[fd]);
// 		s[fd] = NULL;
// 	}
// 	return (1);
// }

// int		get_next_line(const int fd, char **line)
// {
// 	static char	*s[255];
// 	char		buf[BUFF_SIZE + 1];
// 	char		*tmp;
// 	int			ret;

// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
// 	{
// 		buf[ret] = '\0';
// 		if (s[fd] == NULL)
// 			s[fd] = ft_strnew(1);
// 		tmp = ft_strjoin(s[fd], buf);
// 		free(s[fd]);
// 		s[fd] = tmp;
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 	}
// 	if (ret < 0)
// 		return (-1);
// 	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
// 		return (0);
// 	return (ft_new_line(s, line, fd, ret));
// }
