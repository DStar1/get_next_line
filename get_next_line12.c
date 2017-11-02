/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/25 22:49:25 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_for_nl(char *buff, int *last, char **line, char **str)
{
	int		i;
	int		found;
	char	*tmp;

	i = 0;
	found = 0;
	tmp = *str;
	while (i < BUFF_SIZE || buff[i] != '\0')
	{
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			*line = ft_strjoin(*line, ft_strsub(buff, 0, i));
			*last = *last + i + 1;
			return (1);
		}
		i++;
	}
	*line = ft_strjoin(*line, buff);
	return (0);
}

int		check_str(char **str, char **line)
{
	int i;

	i = 0;
	while (str[0] && str[0][i] != '\0')
	{
		if (str[0][i] == '\n')
		{
			*line = ft_strsub(str[0], 0, i);
			str[0] = ft_strsub(str[0], i + 1, ft_strlen(str[0]) - i);
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1]; //added +1 and it now works with all BUFF_SIZEs
	//char			*buff;
	static char		*str;
	int				last;
	int				checked; //added to check for end

	// static int finish;

	checked = 0;
	last = 0;
	// if (ret == 0)
	// 	return (0); //to return 1 everytime is goes, until the end of file
	//buff = (char *)malloc(sizeof(char*)*BUFF_SIZE); //also works

	if (fd < 0 || !line)
		return (-1);
	// if (finish == 1)
	// 	return (0);
	*line = ft_strnew(0);
	if (str)
		*line = str;
	checked = check_str(&str, line);
	while (checked == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		checked = check_for_nl(buff, &last, line, &str);
		str = ft_strsub(buff, last, (BUFF_SIZE - last));
		if (ret == 0)
			str = NULL;
	}
	// if (str == NULL)
	// 	return (0);
	if (ret == 0)
		return 0;
	 //to return 1 everytime is goes, until the end of file
 //to return 1 everytime is goes, until the end of file
	return (1);
}
