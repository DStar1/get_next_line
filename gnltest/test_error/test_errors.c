/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:23:15 by ly                #+#    #+#             */
/*   Updated: 2016/01/22 11:21:20 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

int		test_errors( void )
{
	char	*line;
	int		r00 = 0;
	int		r01 = 0;
	int		r02 = 0;
	int		r03 = 0;
	int		r04 = 0;

	if (get_next_line(-1, &line) != -1)
		r00 = 1;
	if (get_next_line(INT_MAX + 1, &line) != -1)
		r01 = 1;
	if (get_next_line(INT_MIN - 1, &line) != -1)
		r02 = 1;
	if (get_next_line(1, NULL) != -1)
		r03 = 1;
	if (get_next_line(42, &line) != -1)
		r04 = 1;

	if (r00 == 0 && r01 == 0 && r02 == 0 && r03 == 0 && r04 == 0) {
		printf("test_errors: [ok]\n");
		return 1;
	}
	printf("test_errors: [ko]\n");
	return 0;
}
