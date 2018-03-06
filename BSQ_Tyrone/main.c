#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utility.h"
#include "validator.h"
#include "converter.h"
#include "solver.h"
#define BUFF_SIZE 100000000

int	main(void)
{
	char *str;
	int **grid;
	int i;
	int j;

	str = (char*)malloc(sizeof(char) * BUFF_SIZE);
	read(0, str, BUFF_SIZE);
	if (!ft_check_map_length(str) || !ft_check_valid_char(str) || !ft_check_free_space(str)
		|| !ft_get_rows(str))
	{
		printf("map error\n");
		return (0);
	}

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
	i = 0;
	j = 0;
	while (i < ft_get_rows(str) + 1)
	{
		while (j < ft_check_map_length(str) + 1)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	

	free(str);
	free(grid);
	return (0);
}
