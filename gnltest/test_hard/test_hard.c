/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2015/12/17 17:04:27 by ly               ###   ########.fr       */
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

int		test_hard( void )
{
	int		fdin	=	open("test3.in", O_RDONLY);
	int		fdout	=	open("test3.out", O_WRONLY|O_CREAT);
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
	chmod("test3.out", 0644);
	fpin = fopen("test3.in", "r+");
	fpout = fopen("test3.out", "r+");
	if (!fpin || !fpout) {
		perror("error: ");
		return 0;
	}
	fdin = getc(fpin);
	fdout = getc(fpout);
	int i = 0;
	while ((fdin != EOF) && (fdout != EOF) && (fdin == fdout)) {
		fdin = getc(fpin);
		fdout = getc(fpout);
		i++;
	}

	if (fdin != fdout)
		r00 = 1;

	if (r00 == 0) {
		printf("test_hard_%d: [ok]\n", BUFF_SIZE);
		return 1;
	}

	printf("test_hard_%d: [ko]\n", BUFF_SIZE);
	return 0;
}
