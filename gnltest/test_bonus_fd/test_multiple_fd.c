/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multiple_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2016/01/06 09:13:30 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int		test_multiple_fd( void )
{
	int		fdin1	=	open("test4.in", O_RDONLY);
	int		fdin2	=	open("test5.in", O_RDONLY);
	int		fdout1	=	open("test4.out", O_WRONLY|O_CREAT);
	int		fdout2	=	open("test5.out", O_WRONLY|O_CREAT);
	int		r00		=	0;
	int		r01		=	0;
	int		result1	=	0;
	int		result2	=	0;
	char	*line1;
	char	*line2;
	FILE	*fpin1;
	FILE	*fpout1;
	FILE	*fpin2;
	FILE	*fpout2;

	if (fdin1 == -1 || fdout1 == -1 || fdin2 == -1 || fdout2 == -1) {
		perror("error: ");
		return 0;
	}
	while ((result1 = get_next_line(fdin1, &line1)) == 1 || (result2 = get_next_line(fdin2, &line2)) == 1)
	{
		if (result1 == 1)
		{
//			printf("[%s]\n", line1);
			write(fdout1, line1, strlen(line1));
			write(fdout1, "\n", 1);
			free(line1);
		}
		if (result2 == 1)
		{
//			printf("{%s}\n", line2);
			write(fdout2, line2, strlen(line2));
			write(fdout2, "\n", 1);
			free(line2);
		}
	}
	/****************************** TEST FILE 1 ******************************/
	close(fdout1);
	close(fdin1);
	chmod("test4.out", 0644);
	fpin1 = fopen("test4.in", "r+");
	fpout1 = fopen("test4.out", "r+");
	if (!fpin1 || !fpout1) {
		perror("error: ");
		return 0;
	}
	fdin1 = getc(fpin1);
	fdout1 = getc(fpout1);
	int i = 0;
	while ((fdin1 != EOF) && (fdout1 != EOF) && (fdin1 == fdout1)) {
		//printf("i => %d = [%c] - [%c]\n", i, fdin1, fdout1);
		fdin1 = getc(fpin1);
		fdout1 = getc(fpout1);
		i++;
	}
	if (fdin1 != fdout1)
		r00 = 1;
//	printf("i => %d = [%c] - [%c]\n", i, fdin1, fdout1);

	/****************************** TEST FILE 2 ******************************/
	close(fdout2);
	close(fdin2);
	chmod("test5.out", 0644);
	fpin2 = fopen("test5.in", "r+");
	fpout2 = fopen("test5.out", "r+");
	i = 0;
	if (!fpin2 || !fpout2) {
		perror("error: ");
		return 0;
		i++;
	}
	fdin2 = getc(fpin2);
	fdout2 = getc(fpout2);
	i = 0;
	while ((fdin2 != EOF) && (fdout2 != EOF) && (fdin2 == fdout2)) {
//		printf("y => %d = [%c] - [%c]\n", i, fdin2, fdout2);
		fdin2 = getc(fpin2);
		fdout2 = getc(fpout2);
		i++;
	}
//	printf("y => %d = [%c] - [%c]\n", i, fdin2, fdout2);
	if (fdin2 != fdout2)
		r01 = 1;

	if (r00 == 0 && r01 == 0) {
		printf("test_multiplefd_%d: [ok]\n", BUFF_SIZE);
		return 1;
	}

	printf("test_multiplefd_%d: [ko]\n", BUFF_SIZE);
	return 0;
}
