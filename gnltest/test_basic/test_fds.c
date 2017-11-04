/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2016/03/23 16:36:26 by ly               ###   ########.fr       */
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

int		test_fds( void )
{
	int		fdin	=	open("test1.in", O_RDONLY);
	int		fdout	=	open("testfd.out", O_WRONLY|O_CREAT);
	int		r00		=	0;
	char	*line;
	FILE	*fpin;
	FILE	*fpout;

	if (fdin == -1 || fdout == -1) {
		perror("error: ");
		return 0;
	}
	fdin = dup2(fdin, 1024);
	while (get_next_line(fdin, &line) == 1)
	{
		write(fdout, line, strlen(line));
		write(fdout, "\n", 1);
		free(line);
	}
	close(fdout);
	close(fdin);
	chmod("testfd.out", 0644);
	fpin = fopen("test1.in", "r+");
	fpout = fopen("testfd.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
	}

	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_fds_%d: [ok]\n", BUFF_SIZE);
		return 1;
	}

	printf("test_fds_%d: [ko]\n", BUFF_SIZE);
	return 0;
}
