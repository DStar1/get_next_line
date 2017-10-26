/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/25 18:52:51 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	check_for_nl(char *buff, int *last1, char **line, char **str)
{
	int i;
	int found;
	char *tmp;
	int last;

	i = 0;
	found = 0;
	tmp = *str;
	last = *last1;
	while (i < BUFF_SIZE || buff[i] != '\0')
	{
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			found = 1;
			*line = ft_strjoin(*line, ft_strsub(buff, 0, i));
			last = last + i;
			*last1 = last + 1; //to skip the new line for the next time
			return (1);
		}
		i++;
	} 
	if (found != 1)
	{
		*line = ft_strjoin(*line, buff);
		return (0);
	}
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	int ret;
	char buff[BUFF_SIZE];
	static char *str;
	int last;
	int checked;

	checked = 0;
	i = 0;
	last = 0;
	if (!fd || !(*line))
		return (-1);
	if (str)
		*line = str;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			str = ft_strsub(str, i+1, ft_strlen(str)-i);
			checked = 1;
			break ;
		}
		i++;
	}
	while (checked == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		checked = check_for_nl(buff, &last, line, &str);
		str = ft_strsub(buff, last, (BUFF_SIZE - last));
	}
	return (0);
}

