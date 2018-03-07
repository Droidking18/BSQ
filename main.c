/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:10:56 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:10:58 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utility.h"
#include "validator.h"
#include "converter.h"
#include "solver.h"
#define BUFF_SIZE1 1000000
#define BUFF_SIZE2 8000000

void	ft_start(char *str)
{
	int **grid;
	int *largest;
	int i;

	grid = (int**)malloc(sizeof(int*) * (ft_get_rows(str) + 1));
	i = 0;
	while (i < ft_check_map_length(str) + 1)
	{
		grid[i] = (int*)malloc(sizeof(int) * (ft_check_map_length(str) + 1));
		i++;
	}
	ft_pad_grid(grid, str);
	ft_fill_int_grid(grid, str);
	convert(grid, ft_get_rows(str), ft_check_map_length(str));
	largest = largest_number(grid, ft_get_rows(str), ft_check_map_length(str));
	solver(grid, ft_get_rows(str), ft_check_map_length(str), largest);
	free(str);
	free(grid);
}

char	*ft_read(int fd, int buff_size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * BUFF_SIZE1);
	read(0, str, BUFF_SIZE1);
	return (str);
}

int		main(int argc, char **argv)
{
	char *str;

	str = ft_read(0, BUFF_SIZE1);
	if (!ft_check_map_length(str) || !ft_check_valid_char(str)
			|| !ft_check_free_space(str) || !ft_get_rows(str))
	{
		printf("map error\n");
		return (0);
	}
	ft_start(str);
	return (0);
}
