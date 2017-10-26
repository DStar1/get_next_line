/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/25 16:20:51 by hasmith          ###   ########.fr       */
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
	if (*str == NULL)
		*str = "";
	tmp = *str;
	last = *last1;
	while (i < BUFF_SIZE || buff[i] != '\0')
	{
		if (buff[i] == '\n' || buff[i] == '\0')
		{
			//ft_putstr("found newline\n");
			found = 1;
			//last = i;//last + i;
			//line = (ft_strjoin(str, ft_strsub(buff, last, i)));
			*line = ft_strjoin(tmp, ft_strsub(buff, 0, i)); //find starting place (maybe somthing wrong here)
						printf("tttttttttttttttttTmp: %s, LINE: %s\n", tmp, ft_strjoin(tmp, ft_strsub(buff, 0, i)));
			last = last + i;
			*last1 = last + 1; //to skip the new line for the next time
			printf("buff: %s, last: %d, i: %d\nLine: %s\n", buff, last, i, (char*)line);
			return (1);
		}
		i++;
	} 
	if (found != 1)
	{
		tmp = ft_strjoin(tmp, buff);
				printf("sssssssssssssssssssssssssStr1: %s\n", ft_strjoin(*str, tmp));
		*str = ft_strjoin(*str, tmp); //was just tmp but added to add str to the front of tmp for the next line

		return (0);
	}
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	//int i;
	int ret;
	char buff[BUFF_SIZE];
	static char *str;
	static int last;
	int checked;
	//char *none;

	checked = 0;
	str = "";
	last = 0; //not sure about this
	if (!fd || !(*line))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		// if (ret == -1)
		// 	return (-1);
		//buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if (ret == 0 && checked != 0){
			printf("%s", str);
			return (0);
		}
		checked = 1;
		
	}
		
		// //str = ft_strjoin(str, buff);
		// //printf("\njoined: %s\n", ft_strjoin(str, buff));
		// checked = check_for_nl(buff, &last, line, &str);
		// printf("Llllllllllllllllllline: %s\n", (char*)line);
		// printf("ssssssssssssssssssssStr2;;;;: %s\n", str);
		// printf("lllllllllllllllast;;;;: %d\n", last);
		// printf("bbbbbbbbbbbuff;;;;: %s\n", buff);

		// //char *str1 = str;
		// str = ft_strsub(buff, last, (BUFF_SIZE - last));
		// //if (str == NULL)
		// //	str = str1;
		// //last = ft_strlen(str);
		// printf("ssssssssssssssssssssStr3;;;;: %s\n", str);
		// printf("\nLast: %d, New_buff: %s\n", last, str);
	//}
	return (0);
}

