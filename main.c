// #include <unistd.h>
// #include <stdio.h>

// int		main(int ac, char **av)
// {
// 	char c = 'l';
// 	printf("%x hexadecimal with lower case letters.\n", c);
// 	//read(1, 'n', 1);
// 	return (0);
// }


//Reads from a file

//#include <stdio.h>
//#include <sys/types.h>
// #include <unistd.h>

// int main(int argc, char** argv)
// {
//     int nread;
//     char buffer[128];
    
//     nread=read(0,buffer,128);
    
//     if(nread == -1)
//      write(2,"an read error occured\n",26);
     
//     if((write(1,buffer,nread))!= nread)
//        write(2,"a write error occured\n",27);
    
//     return 0;
// } 

#include "get_next_line.h"

int main(int ac, char **av){
	int		filedesc;
	char	*line;
	char	*filename;

	//filename = av[1];
	line = "";
	if ((filedesc = open("test", O_RDONLY)) == -1)
		return (0);
	int i = 3;
	// while (i > 0){
    // 	get_next_line(filedesc, &line);
	// 	i--;
	// }
	get_next_line(filedesc, &line);
	printf("\nOffial_Result: %s\n", line);
	
	get_next_line(filedesc, &line);
	printf("\nOffial_Result2: %s\n", line);
	close(filedesc);
	return (0);
}
// char	*ft_get_stdin(char *filename, int *tot_char)
// {
// 	int		ret;
// 	char	*final;
// 	int		filedesc;
// 	char	buf[1001];

// 	if ((filedesc = open(filename, O_RDONLY)) == -1)
// 		return (NULL);
// 	if ((ret = read(filedesc, buf, 1000)) == -1)
// 		return (NULL);
// 	buf[ret] = '\0';
// 	final = ft_strdup(buf);
// 	*tot_char = ret;
// 	close(filedesc);
// 	return (final);
// }