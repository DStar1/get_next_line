#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av){
  int		filedesc;
  char	*line;
  char	*filename;
  int i = 0;

//filename = av[1];
line = NULL;
if ((filedesc = open(av[1], O_RDONLY)) == -1)
return (0);
//int i = 1;
while ((i = get_next_line(filedesc, &line)))
	printf("%d, %s\n", i, line);
printf("%d\n", i);
close(filedesc);
free(line);
return (0);
}

/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
*/