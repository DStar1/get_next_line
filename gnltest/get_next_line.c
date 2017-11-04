/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:39 by alouisy-          #+#    #+#             */
/*   Updated: 2016/05/10 20:01:51 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"

int		find_n_split(char **line, char *buf, char *next)
{
	char	*tmp;
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	c = ft_strnew(1);
	while (buf[i])
	{
		*c = buf[i++];
		if (buf[i - 1] == '\n')
		{
			while (buf[i])
				next[j++] = buf[i++];
			next[j] = '\0';
			free(c);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, c);
		free(tmp);
	}
	free(c);
	return (0);
}

char	*ft_readline(int const fd, int *check, char *next, char *buf)
{
	int		ret;
	char	*line;

	line = ft_strnew(0);
	if ((*check = find_n_split(&line, next, next)) == 1)
		return (line);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((*check = find_n_split(&line, buf, next)) == 1)
			return (line);
	}
	if (ret == -1)
		*check = (-1);
	else if (*line != '\0')
		*check = 2;
	return (line);
}

int		get_next_line(int const fd, char **line)
{
	static char	**next;
	char		*buf;
	int			check;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (next == NULL)
		next = (char**)malloc(sizeof(char*) * 1000 + 1);
	if (next[fd] == NULL)
		next[fd] = ft_strnew(BUFF_SIZE);
	check = 0;
	*line = ft_readline(fd, &check, next[fd], buf);
	free(buf);
	if (check == -1)
		return (-1);
	else if (check == 2)
		next[fd][0] = '\0';
	else if (check == 0)
		return (0);
	return (1);
}
