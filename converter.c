/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:11:56 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:22:16 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"
#include "validator.h"
#include "utility.h"
#include <stdio.h>

void	ft_pad_grid(int **grid, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (ft_get_rows(str) + 1))
	{
		while (j < (ft_check_map_length(str) + 1))
		{
			if (i == 0)
			{
				grid[i][j] = 0;
			}
			else if (j == 0)
			{
				grid[i][j] = 0;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_fill_int_grid(int **grid, char *str)
{
	int		i;
	int		j;
	int		k;
	char	empty;
	char	obstacle;
	char	square;

	k = ft_find_map_start(str);
	ft_find_valid_char(str, &empty, &obstacle, &square);
	j = 1;
	i = 1;
	while (str[k] != '\0')
	{
		while (i < ft_get_rows(str) + 1)
		{
			while (j < ft_check_map_length(str) + 1)
			{
				if (str[k] == empty)
					grid[i][j] = 1;
				else if (str[k] == obstacle)
					grid[i][j] = 0;
				j++;
				k++;
			}
			k++;
			i++;
			j = 1;
		}
		k++;
	}
}
