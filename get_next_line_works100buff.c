/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_works100buff.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 14:59:00 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/31 15:59:56 by hasmith          ###   ########.fr       */
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
		if (buff[i] == '\n')// || buff[i] == '\0')
		{
			*line = ft_strjoin(*line, ft_strsub(buff, 0, i));
			*last = *last + i + 1;
			// if (buff[i] == EOF)
			// 	return (-1);
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
		if (str[0][i] == '\n' || str[0][i] == '\0')
		{
			*line = ft_strsub(str[0], 0, i);
			str[0] = ft_strsub(str[0], i + 1, ft_strlen(str[0]) - i);
			// if (str[0][i] == EOF)
			// 	return (-1);
			return (1);
		}
		if (str[0][i+1] == '\0')
		{
			*line = ft_strsub(str[0], 0, i+1);
			str[0] = ft_strsub(str[0], i + 2, ft_strlen(str[0]) - i+1);
			// if (str[0][i] == EOF)
			// 	return (-1);
			return (-1);
		}
		i++;
	}
	return (0);
}

// int null_check(char *buff)
// {
// 	int i;

// 	i = 0;
// 	while (*buff)
// 	{
// 		if (buff == '\0')
// 			return (0);
// 		buff++;
// 	}
// 	return (1);
// }

int		get_next_line(const int fd, char **line)
{
	static int				ret;
	char			buff[BUFF_SIZE + 1]; //added +1 and it now works with all BUFF_SIZEs
	static char		*str;
	int				last;
	int				checked; //added to check for end

//	static int finish; //not sure

	if (str && str[0] == EOF)
		return (0);
	checked = 0;
	last = 0;
	if (fd < 0 || !line)
		return (-1);
	// if (finish == 1)
	// 	return (0);
	*line = ft_strnew(0);
	if (str)
		*line = str;
	if ((checked = check_str(&str, line)) == 1)
	{
		// if (str == NULL)
		// 	return (0);

		return (1);
	}
	if (checked == -1 && ret == 0)
	{
		if (str[0] == '\0')
		{
			//if (ret == 0)
				str[0] = EOF;
			//return (0);
		}
		//return (0);
	}

	// if (checked == -1)
	// 	printf("EOF3");// return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		// for (int i = 0;i < BUFF_SIZE; i++){
		// 	if (buff[i] == EOF)
		// 		printf("hello");
		// }
		buff[ret] = '\0';

		if ((checked = check_for_nl(buff, &last, line, &str)) == 1)// && !ft_strchr(str))
		{
			//if (ft_strlen(buff) == BUFF_SIZE)
			//{
				str = ft_strsub(buff, last, (BUFF_SIZE - last));
				// if (!str)
				// 	return (0);
				//printf("%s", str);
				//if (str[0] != '\x0f')
				// if (str == NULL)
				// 	return (0);
				return (1);
			//}
		}

		if (ft_strlen(buff) < BUFF_SIZE)
			return (1);
		// if (!str)
		// 	printf("nostr");
		// for (int i = 0;i < ft_strlen(str); i++){
		// 	if (str[i] == '7')
		// 		printf("hello");
		// 	printf("no end: ");
		// }
		
		if (checked == -1 && !str)
			ft_putstr("");
		
		// if (ret == 0)
		// 	str = NULL;
	}
	// if (ret == 0 && str)
	// {
	// 	*line = ft_strjoin(*line, str);
	// 	str = NULL;
	// 	return (1);
	//}
	// if (!(str && !ft_strchr(str, '\n')))
	// {
	// 	*line = str;
	// 	ft_strdel(&str);
	// 	return (0);
	// }
	// if (ft_strcmp(str, ""))
	// 	return (0);


	// if (ret == 0)
	// 	finish = 1;
	if (ret != 0)
		return 1;
	else if (checked == -1)
	{
		str[0] = EOF;
		return 1;
	}
	return 0;
	 //to return 1 everytime is goes, until the end of file
 //to return 1 everytime is goes, until the end of file
	//return (1);
}
