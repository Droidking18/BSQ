#include <stdio.h>
#include <unistd.h>

int	min(int a, int b, int c)
{
	if ((a < b && a < c) || (a == c && a < b))
		return (a);
	else if ((b < c && b < a) || (b == a && b < c))
		return(b);
	else
		return(c);
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
