/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/31 18:05:44 by hasmith          ###   ########.fr       */
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

/*

//attempting to fix 2nd error

int		check_str(char **str, char **line, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[0] && str[0][i] != '\0')
	{
		if (str[0][i] == c)
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

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*str;

	RETURN_NEG1((fd < 0 || !line));
	RETURN_1((str && check_str(&str, line, '\n')));
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
	// int i = check_str(&str, line, '\n');
	 RETURN_1((i && ret > 0));
	// if (i == 0)
	// 	check_str(&str, line, '\0');
	if ((str && ret == 0 && ft_strlen(str)))// || str && ret == 0 && !(ft_strchr(str, '\n')))
	{
		*line = ft_strsub(str, 0, ft_strlen(str));
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

*/
/*
int		ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
*/
