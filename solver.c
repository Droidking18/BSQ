/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:12:34 by dkaplan           #+#    #+#             */
/*   Updated: 2018/03/07 10:15:37 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		min(int a, int b, int c)
{
	if ((a < b && a < c) || (a == c && a < b))
		return (a);
	else if ((b < c && b < a) || (b == a && b < c))
		return (b);
	else
		return (c);
}

void	convert(int **g, int row, int col)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (x < row + 1)
	{
		while (y < col + 1)
		{
			if (g[x][y] != 0)
				g[x][y] = min(g[x][y - 1], g[x - 1][y], g[x - 1][y - 1]) + 1;
			y++;
		}
		x++;
		y = 1;
	}
}

int		*largest_number(int **grid, int row, int col)
{
	int x;
	int y;
	int *largest;

	x = 1;
	y = 1;
	largest = (int*)malloc(sizeof(int) * 3);
	largest[0] = grid[x][y];
	while (x < row + 1)
	{
		while (y < col + 1)
		{
			if (grid[x][y] > largest[0])
			{
				largest[0] = grid[x][y];
				largest[1] = x;
				largest[2] = y;
			}
			y++;
		}
		x++;
		y = 1;
	}
	return (largest);
}

void	solver(int **grid, int row, int col, int *largest)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (x < row + 1)
	{
		while (y < col + 1)
		{
			if ((y <= largest[2] && y > largest[2] - largest[0])
					&& (x <= largest[1] && x > largest[1] - largest[0]))
				write(1, " x", 2);
			else if (grid[x][y] == 0)
				write(1, " o", 2);
			else
				write(1, " .", 2);
			y++;
		}
		write(1, "\n", 1);
		x++;
		y = 1;
	}
}
