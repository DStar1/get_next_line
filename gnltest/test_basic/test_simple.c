/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2016/03/23 16:15:49 by ly               ###   ########.fr       */
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

int		test_simple( void )
{
	int		fdin	=	open("test1.in", O_RDONLY);
	int		fdout	=	open("test1.out", O_WRONLY|O_CREAT);
	int		r00		=	0;
	char	*line;
	FILE	*fpin;
	FILE	*fpout;

	if (fdin == -1 || fdout == -1) {
		perror("error: ");
		return 0;
	}
	while (get_next_line(fdin, &line) == 1)
	{
		write(fdout, line, strlen(line));
		write(fdout, "\n", 1);
		free(line);
	}
	close(fdout);
	close(fdin);
	chmod("test1.out", 0644);
	fpin = fopen("test1.in", "r+");
	fpout = fopen("test1.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
//	printf("{%c} = {%c}\n", fdin, fdout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
//		printf("{%c} = {%c}\n", fdin, fdout);
	}

	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_simple_%d: [ok]\n", BUFF_SIZE);
		return 1;
	}

	printf("test_simple_%d: [ko]\n", BUFF_SIZE);
	return 0;
}
