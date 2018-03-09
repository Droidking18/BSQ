/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:10:56 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/08 18:16:32 by tstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
	while (i < ft_get_rows(str) + 1)
	{
		grid[i] = (int*)malloc(sizeof(int) * (ft_check_map_length(str) + 1));
		i++;
	}
	ft_pad_grid(grid, str);
	ft_fill_int_grid(grid, str);
	convert(grid, ft_get_rows(str), ft_check_map_length(str));
	largest = largest_number(grid, ft_get_rows(str), ft_check_map_length(str));
	solver(grid, ft_get_rows(str), ft_check_map_length(str), largest);
	free(grid);
	free(str);
}

char	*ft_read(int fd, int buff_size)
{
	char	buff[buff_size + 1];
	char	*str;
	int		i;

	i = 0;
	if (fd == 0)
	{
		str = (char*)malloc(sizeof(char) * buff_size + 1);
		while (read(0, buff, 1))
		{
			ft_strcat(str, buff);
		}
	}
	else
	{
		str = (char*)malloc(sizeof(char) * buff_size + 1);
		read(fd, str, buff_size);
	}
	return (str);
}

void	ft_read_stdin(void)
{
	char *str;

	str = ft_read(0, BUFF_SIZE2);
	if ((!ft_check_map_length(str) || !ft_check_valid_char(str)
		|| !ft_check_free_space(str) || !ft_get_rows(str)))
	{
		ft_putstr("map error\n");
	}
	else
		ft_start(str);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		fd;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			str = ft_read(fd, BUFF_SIZE1);
			if (fd == -1 || !ft_check_map_length(str)
				|| !ft_get_rows(str) || !ft_check_valid_char(str)
				|| !ft_check_free_space(str))
				ft_putstr("map error\n");
			else
				ft_start(str);
			close(fd);
			i++;
		}
	}
	else
		ft_read_stdin();
	return (0);
}
