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

void	convert(int **grid, int row, int col)
{
	int x;
	int y;

	x = 1;
	y = 1;

	while (x < row + 1)
	{
		while (y < col + 1)
		{
			if (grid[x][y] != 0)
				grid[x][y] = min(grid[x][y - 1], grid[x - 1][y], grid[x - 1][y - 1]) + 1;
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
	printf("%d\n", largest[0]);
	printf("---%d---", largest[1]);
	printf("%d---\n", largest[2]);
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
			if ((y <= largest[2] && y > largest[2] - largest[0]) && (x <= largest[1] && x > largest[1] - largest[0]))
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




