#include "get_next_line.h"

int main(int ac, char **av){
	int		filedesc;
	char	*line;
	char	*filename;

	//filename = av[1];
	line = "";
	if ((filedesc = open("test", O_RDONLY)) == -1)
		return (0);
	int i = 5;
	while (i > 0){
    	get_next_line(filedesc, &line);
		printf("\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOffial_Result%d: %s\n", i, line);
		i--;
	}
	close(filedesc);
	return (0);
}
