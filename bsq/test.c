#include <stdio.h>

int	min(int a, int b, int c)
{
	int sol;
	if((a<b && a<c)	|| (a == c && a < b))	
		sol = a;
	else if((b<c && b<a) || (b == a && b < c))
		sol = b;
	else
		sol = c;
}

void	convert(int **i)
{
	int x;
	int y;
	int **set;

	x = 0;
	y = 0;

	while (1 == 1)
	{
		printf("-");
		if (i[0][y] == 0)
			set[x][y] = i[x][y];
		else  
			set[x][y] = ((min(set[x][y - 1], set[x - 1][y], set[x - 1][y - 1]) + 1));
		printf("%i", set[x][y]);
	//	if (i[x][y] != '\0')
	//	{
	//		break;
	//	}
		y++;
	}
	set[x][y] = '\0';
}

int		main(void)
{
	int test[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 1, 1, 1}, {0, 0, 1, 1, 1}, {0, 1, 1, 1, 1}};
	convert(test);
	return(0);
}
