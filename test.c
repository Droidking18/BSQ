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

void	convert(int i[5][5])
{
	int x;
	int y;
	int set[5][5];

	x = 0;
	y = 0;

	while (i[x][y] == 0 || i[x][y] == 1)
	{
		printf(" ");
		if (i[x][y] == 0)
			set[x][y] = i[x][y];
		else 
			set[x][y] = ((min(set[x][y - 1], set[x - 1][y], set[x - 1][y - 1]) + 1));
		printf("%i", set[x][y]);
		if (y == 4)
		{
			x++;
			printf("\n");
			y = -1;
		}
		y++;
	}
}

int		main(void)
{
	int test[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 1, 1, 1}, {0, 0, 1, 1, 1}, {0, 1, 1, 1, 1}};
	convert(test);
	return(0);
}
